#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <condition_variable>
#include <queue>
#include <chrono>

// std::mutex 创建互斥量
// lock()   上锁
// unlock() 解锁
// std::lock_gurad RAII语法的模板类
// 1. 代码简洁
// 2. 保证代码异常安全
// std::unique_lock 独占拥有的mutex对象的所有权
// 1. 灵活
// 2. 管理mutex对象上的上锁和解锁的操作

// std::future 支持异步操作
// get_future() 获得一个 std::future对象，线程同步所需
//
// std::package_task 封装任何可以调用的目标,从而用于实现异步调用

// std::condition_variable 解决死锁而生
// 实例被创建出现主要就是用于唤醒等待线程从而避免死锁
// 1.notify_one() 用于唤醒一个线程
// 2.notify_all() 通知所有线程
std::mutex mtx;

void block_area(){
    std::unique_lock<std::mutex> lock(mtx);
    // ...临界区
}

int main()
{
    std::thread thd1(block_area);
    thd1.join();

    // 将一个返回值为7的 lambda 表达式封装到 task 中
    // std::packaged_task 的模板参数为要封装函数的类型
    std::packaged_task<int()> task([](){return 7;});
    // 获得 task 的 future
    std::future<int> result = task.get_future();    // 在一个线程中执行 task
    std::thread(std::move(task)).detach();    std::cout << "Waiting...";
    result.wait();
    // 输出执行结果
    std::cout << "Done!" << std:: endl << "Result is " << result.get() << '\n';
    
    // 生产者模型
    std::queue<int> produced_nums;
    // 互斥锁
    std::mutex m;
    // 条件变量
    std::condition_variable cond_var;
    // 结束标志
    bool done = false;
    // 通知标志
    bool notified = false;

   // 生产者线程
    std::thread producer([&](){
        for(int i = 0; i<5; i++){
            std::this_thread::sleep_for(std::chrono::seconds(1));
            // 创建互斥锁
            std::unique_lock<std::mutex> lock(m);
            std::cout << "producing " << i << '\n';
            produced_nums.push(i);
            notified = true;
            // 通知一个线程
            cond_var.notify_one();
        }
        done = true;
        cond_var.notify_one();
    });

    // 消费者线程
    std::thread consumer([&](){
        std::unique_lock<std::mutex> lock(m);
        while(!done)
        {
            while(!notified){
                // 循环避免虚假唤醒
                cond_var.wait(lock);
            }

            while(!produced_nums.empty()){
                std::cout << "consuming" << produced_nums.front() << "\n";
                produced_nums.pop();
            }

            notified = false;
        }
    });
    
    producer.join();
    consumer.join();

    return 0;
}
