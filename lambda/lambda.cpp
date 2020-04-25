#include <iostream>
#include <utility>
#include <memory>
using namespace std;
//lambda表达式
//提供一个类似匿名函数的特性
//与函数具有相同的功能，但是又不会费力去命名一个函数
//基本语法：
//[捕获列表](参数列表) mutable(可选) 异常属性 -> 返回类型{ //函数体 }
//
//1.值捕获:与参数传值类似，值捕获的前期是变量可以拷贝，不同之处则在于，被捕获的变量在 lambda 表达式被创建时拷贝，而非调用时才拷贝
void learn_lambda_func_1()
{
    int value_1 = 1;
    auto copy_value_1 = [value_1]
    {
        return value_1;
    };
    value_1 = 100;
    auto stored_value_1 = copy_value_1();
    //创建了一份value_1的拷贝
    cout << "value_1 = " << value_1 << endl;
    cout << "stored_value_1 = " << stored_value_1 << endl;
    cout << "value_1 address :" << &value_1 << endl;
    cout << "stored_value_1 address :" << &stored_value_1 << endl;
}
//2.引用捕获:捕获引用，值会发生变化
void learn_lambda_func_2()
{
    int value_2 = 1;
    auto copy_value_2 = [&value_2]{
        return value_2;
    };

    value_2 = 100;
    //保存一份引用
    auto stored_value_2 = copy_value_2();
    
    cout << "value_2 = " << value_2 << endl;
    cout << "stored_value_2 = " << stored_value_2 << endl;
    cout << "value_2 address :" << &value_2 << endl;
    cout << "stored_value_2 address :" << &stored_value_2 << endl;
}
//3.隐式捕获:默认编译器进行处理
//·[]:空捕获列表
//·[name1,name2,...]:捕获一系列变量
//·[&]:引用捕获，编译器自行推导捕获列表
//·[=]:值捕获,编译器执行推导列表

//4.表达式捕获-c++14
//特点:允许捕获右值
void learn_lambda_func_4()
{
    auto important = make_unique<int>(1);
    auto add = [v1 = 1, v2 = move(important)](int x, int y) -> int {
        return x+y+v1+(*v2);
    };

    cout << "add(3,4) = " << add(3,4) << endl;
}
//5.泛型lambda,c++14
//auto关键字不能用于参数列表，与模板功能产生冲突
//lambda表达式不是普通的函数，并不存在模板化
//导致lambda表达式参数列表不能泛化，必须明确参数表类型
//c++14完美解决了这个问题
void learn_lambda_func_5()
{
    auto generic = [](auto x, auto y){
        return x+y;
    };

    cout << "generic(1,2) = " << generic(1,2) << endl;
    cout << "generic(1.1,2.2) = " << generic(1.1, 2.2) << endl;
}
int main()
{
    //1.值捕获
    learn_lambda_func_1();
    //2.引用捕获
    learn_lambda_func_2();
    //4.表达式捕获-c++14
    learn_lambda_func_4();
    //5.泛型lambda,c++14
    learn_lambda_func_5();
    return 0;
}
