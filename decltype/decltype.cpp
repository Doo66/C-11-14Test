/*
 decltype(表达式) 类似于 sizeof(类型)
 1.解决auto关键字只能对变量进行类型推导的缺陷而出现的
 2.c++11接受尾返回类型
 */
#include <iostream>
using namespace std;

//c++11
template<typename T, typename U>
auto add(T x, U y) -> decltype(x+y)
{
    return x+y;
}


//c++14
template<typename T, typename U>
auto fun(T x, U y) 
{
    return x+y;
}


int main()
{
    auto x = 1;
    auto y = 2;
    //1.接受类型推导
    decltype(x+y) z = x+y;
    cout << "z = " << z << endl;
    //2.接受尾返回类型推导
    //c++11
    z = add(x, y);
    cout << "z = " << z << endl;
    //c++14
    z = fun(x,y);
    cout << "z = " << z << endl;
    return 0;
}

