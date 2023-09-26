//
// Created by Karenina-na on 2023/9/22.
//

#ifndef SORTING_ALGORITHM_INTERFACE_FRAMEWORK_THREADPOOL_H
#define SORTING_ALGORITHM_INTERFACE_FRAMEWORK_THREADPOOL_H

#include <queue>
#include <shared_mutex>
#include <mutex>
#include <thread>
#include <vector>
#include <atomic>

namespace structure{
    // 并发安全队列
    template<typename T>
    class SafeQueue {
    public:
        SafeQueue() = default;

        ~SafeQueue() = default;

        void push(T t);

        T pop();

        bool empty();

        int size();

    private:
        std::queue<T> queue;
        std::shared_mutex mutex;
    };

    // 线程池
    class ThreadPool {
    public:
        ThreadPool(int core_num, int max_num);
        ~ThreadPool();

        void addTask(void (*task)(void*));              // 添加任务
        void destroy();                                // 销毁线程池

    private:
        SafeQueue<void*> taskQueue;                    // 任务队列
        std::vector<std::thread> threadPool;           // 线程池
        std::shared_mutex mutex;                       // 读写锁
        int core_num;                                  // 核心线程数
        int max_num;                                   // 最大线程数
        std::atomic<int> active_num{};                   // 活动线程数
        std::atomic<bool> is_running{};                  // 线程池是否运行
        std::atomic<int> task_num{};                     // 任务数
    };
}

// 安全队列
// 入队
template<typename T>
void structure::SafeQueue<T>::push(T t) {
    // 入队
    std::unique_lock<std::shared_mutex> lock(mutex);
    queue.push(t);
    lock.unlock();
}

// 出队
template<typename T>
T structure::SafeQueue<T>::pop() {
    // 出队
    std::unique_lock<std::shared_mutex> lock(mutex);
    T t = queue.front();
    queue.pop();
    lock.unlock();
    return t;
}

// 判空
template<typename T>
bool structure::SafeQueue<T>::empty() {
    // 判空
    std::shared_lock<std::shared_mutex> lock(mutex);
    bool empty = queue.empty();
    lock.unlock();
    return empty;
}

// 队列大小
template<typename T>
int structure::SafeQueue<T>::size() {
    // 队列大小
    std::shared_lock<std::shared_mutex> lock(mutex);
    int size = queue.size();
    lock.unlock();
    return size;
}

// 线程池
// 构造函数
structure::ThreadPool::ThreadPool(int core_num, int max_num) {
    // 检查参数
    if (core_num <= 0 || max_num <= 0 || core_num > max_num) {
        throw std::invalid_argument("invalid argument");
    }
    if (core_num > std::thread::hardware_concurrency()) {
        throw std::invalid_argument("core_num is too large");
    }

    // 初始化
    this->core_num = core_num;
    this->max_num = max_num;
    active_num = 0;
    is_running = true;

    // 创建核心线程
    for (int i = 0; i < core_num; i++) {
        active_num++;
        threadPool.emplace_back([this](){
            while (true) {
                if (!is_running) {
                    break;
                }

                // 从任务队列中取出任务
                std::unique_lock<std::shared_mutex> lock(mutex);
                auto (*task)(void *) = (void (*)(void *)) taskQueue.pop();
                lock.unlock();

                // 执行任务
                task(nullptr);

                // 如果活动线程大于核心线程，销毁线程
                if (active_num > this->core_num || !is_running) {
                    active_num--;
                    break;
                }
            }
        });
    }
}

// 析构函数
structure::ThreadPool::~ThreadPool() {
    // 销毁线程池
    destroy();
}

// 添加任务
void structure::ThreadPool::addTask(void (*task)(void*)) {
    // 检查参数
    if (task == nullptr) {
        throw std::invalid_argument("invalid argument");
    }

    // 添加任务
    taskQueue.push((void*)task);

    // 任务数加一
    task_num++;

    // 活动线程数小于最大线程、大于核心线程，创建新线程
    if (active_num < max_num) {
        active_num++;
        threadPool.emplace_back([this]() {
            while (true) {
                if (!is_running) {
                    break;
                }

                // 从任务队列中取出任务
                std::unique_lock<std::shared_mutex> lock(mutex);
                auto (*task)(void *) = (void (*)(void *)) taskQueue.pop();
                lock.unlock();

                // 执行任务
                task(nullptr);

                // 如果活动线程大于核心线程，销毁线程
                if (active_num > this->core_num || !is_running) {
                    active_num--;
                    break;
                }
            }
        });
    }
}

// 销毁线程池
void structure::ThreadPool::destroy() {
    // 销毁线程池
    is_running = false;
    std::unique_lock<std::shared_mutex> lock1(mutex);
    while (!taskQueue.empty()) {
        taskQueue.pop();
    }
    lock1.unlock();
    // 注入任务
    auto lambda = [](void* data) {
        // pass
    };
    std::unique_lock<std::shared_mutex> lock2(mutex);
    for (int i = 0; i < threadPool.size(); i++) {
        taskQueue.push(&lambda);
    }
    lock2.unlock();
    // 等待线程结束
    for (auto & i : threadPool) {
        if (i.joinable()) {
            i.join();
        }
    }
    threadPool.clear();
}

#endif //SORTING_ALGORITHM_INTERFACE_FRAMEWORK_THREADPOOL_H
