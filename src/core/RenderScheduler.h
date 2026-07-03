#pragma once
#include <functional>
#include <future>
#include <queue>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <atomic>

namespace swm::graphics {

class RenderScheduler {
public:
    RenderScheduler();
    ~RenderScheduler();
    void start();
    void stop();
    std::future<void> schedule(std::function<void()> task);
private:
    void run();
    std::thread m_worker;
    std::queue<std::pair<std::function<void()>, std::promise<void>>> m_tasks;
    std::mutex m_mutex;
    std::condition_variable m_cv;
    std::atomic<bool> m_running{false};
};

}
