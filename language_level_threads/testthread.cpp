#include <iostream>
#include <thread>

// std::thread 创建一个线程
// get_id() 获取创建线程的线程ID
// join() 加入一个线程

void fun()
{
    std::cout << "hello thread." << std::endl;
}

int main()
{
    std::thread t(fun);
    t.join();
    return 0;
}
