#include "RenderScheduler.h"

namespace swm::graphics {

RenderScheduler::RenderScheduler() {
}

RenderScheduler::~RenderScheduler() {
    stop();
}

void RenderScheduler::start() {
    if (m_running.exchange(true)) {
        return;
    }
    m_worker = std::thread(&RenderScheduler::run, this);
}

void RenderScheduler::stop() {
    if (!m_running.exchange(false)) {
        return;
    }
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_cv.notify_one();
    }
    if (m_worker.joinable()) {
        m_worker.join();
    }
}

std::future<void> RenderScheduler::schedule(std::function<void()> task) {
    std::promise<void> promise;
    auto future = promise.get_future();
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_tasks.push(std::make_pair(task, std::move(promise)));
        m_cv.notify_one();
    }
    return future;
}

void RenderScheduler::run() {
    while (m_running) {
        std::pair<std::function<void()>, std::promise<void>> taskPair;
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            m_cv.wait(lock, [this]() { return !m_running || !m_tasks.empty(); });
            if (!m_running && m_tasks.empty()) {
                break;
            }
            taskPair = std::move(m_tasks.front());
            m_tasks.pop();
        }
        try {
            taskPair.first();
            taskPair.second.set_value();
        } catch (...) {
            taskPair.second.set_exception(std::current_exception());
        }
    }
}

}
