#include <iostream>
#include <memory>

// unique_ptr 是一种独占的智能指针，它禁止其他智能指针与其共享同一个对象，从而保证了代码的安全

// c++11无make_unique
// c++14引入make_unique
// 自实现make_unique
template<typename T, typename ...Args>
std::unique_ptr<T> make_unique( Args&& ...args )
{
    return std::unique_ptr<T>(new T( std::forward<Args>(args)...));
}

struct Foo{
    Foo()      { std::cout << "Foo::Foo" << std::endl;  }
    ~Foo()     { std::cout << "Foo::~Foo" << std::endl; }
    void foo() { std::cout << "Foo::foo" << std::endl;  }
};

void fun(const Foo&)
{
    std::cout << "fun(const Foo&)" << std::endl;
}

int main()
{
    std::unique_ptr<Foo> p1(std::make_unique<Foo>());

    // p1 不空, 输出
    if (p1) p1->foo();
    {
        std::unique_ptr<Foo> p2(std::move(p1));

        // p2 不空,输出
        fun(*p2);

        // p2 不空,输出
        if(p2) p2->foo();

        // p1 为空,无输出
        if(p1) p1->foo();

        p1 = std::move(p2);

        // p2 为空,无输出
        if(p2) p2->foo();
        std::cout << "p2 被销毁" << std::endl;

    }

    // p1 不空,输出
    if(p1) p1->foo();
    return 0;
}
