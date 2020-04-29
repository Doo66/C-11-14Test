#include <iostream>

// c++11 将异常的声明简化为以下两种情况
// 1.函数可能抛出任何异常
// 2.函数不能抛出任何异常
// 使用 noexcept 进行限制行为
// void may_throw();                //可以抛出异常
// void no_throw() noexcept;        //不可能抛出异常
//
// 使用 noexcept 修饰过的函数如果抛出异常，编译器会使用 std::terminate() 来立即终止程序运行。
// noexcept 还能用作操作符，用于操作一个表达式，当表达式无异常时，返回 true，否则返回 false

void may_throw(){
    throw true;
}

auto non_block_throw = []{
    may_throw();
};

void no_throw() noexcept {
    return;
}

auto block_throw = []() noexcept {
    no_throw();
};

int main()
{   
    std::cout << std::boolalpha;
    std::cout << "may_throw() noexcept ?" << noexcept(may_throw()) << std::endl;
    std::cout << "no_throw() noexcept ?" << noexcept(no_throw()) << std::endl;
    std::cout << "lmay_throw() noexcept ?"<< noexcept(non_block_throw()) << std::endl;
    std::cout << "lno_throw() noexcept ?" << noexcept(block_throw()) << std::endl;
    
    // 捕获异常
    try{
        may_throw();
    }
    catch(...){
        std::cout << "捕获异常,来自 may_throw()" << std::endl;
    }

    try{
        non_block_throw();
    }
    catch(...){
        std::cout << "捕获异常,来自 non_block_throw()" << std::endl;
    }


    try{
        block_throw();
    }
    catch(...){
        std::cout << "捕获异常,来自 block_throw()" << std::endl;
    }

    return 0;
}
