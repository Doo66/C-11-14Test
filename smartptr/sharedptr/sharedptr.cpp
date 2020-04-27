#include <iostream>
#include <memory>

// shared_ptr 共同指向一个对象
// 使用 make_shared 分配创建传入参数中的对象，并返回这个对象类型的std::shared_ptr指针

void foo(std::shared_ptr<int> i)
{
    (*i)++;
}

int main()
{
    //构造一个shared_ptr
    auto ptr = std::make_shared<int>(10);
    foo(ptr);
    std::cout << *ptr << std::endl;
    
    auto pointer = std::make_shared<int>(10);
    auto pointer2 = pointer;        //引用计数+1
    auto pointer3 = pointer;        //引用计数+1
    //shared_ptr通过get()方法获取原始指针
    int* p = pointer.get();         //引用不会增加
    
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;      // 3
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;    // 3
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;    // 3

    //reset()减少一个引用计数,通过use_count()查看一个对象的引用计数
    pointer2.reset();
    std::cout << "reset pointer2:" << std::endl;
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;      // 2
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;    // 0
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;    // 2

    pointer3.reset();
    std::cout << "reset pointer3:" << std::endl;
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;      // 1
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;    // 0
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;    // 0
    
    return 0;
}
