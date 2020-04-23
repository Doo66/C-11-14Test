#include <iostream>
#include <initializer_list>
#include <vector>
using namespace std;

class Magic
{
    public:
        Magic(initializer_list<int> list)
        {}
};
class Foo
{
    private:
        int value;
    public:
        Foo(int val)
        {
            value = val;
        };
};

void func(initializer_list<int> list)
{
    return;
}

struct A{
    int a;
    float b;
};

struct B{
    B(int _a, float _b):a(_a), b(_b){}

    private:
        int a;
        int b;
};

int main()
{
    //初始化列表
    //1.为了解决对象不能统一进行初始化的问题

    //数组对象初始化
    int arr[3] = {1,2,3};
    //类对象初始化通过构造函数，或拷贝构造函数等进行初始化
    Foo foo(1);
    //c++11特性
    //1.可以通过初始化列表进行初始化
    Magic magic = {1,2,3,4,5};
    vector<int> vec = {1,2,3,4};
    //2.可以作为普通函数的形参
    func({1,2,3});
    //统一语法
    A a {1,1.1};
    B b {2,2.2};
    

    return 0;
}
