#include <iostream>
#include <vector>

using namespace std;

template<typename T, typename U, int value>
class SuckType{
    public:
        T a;
        U b;
        SuckType():
            a(value),
            b(value)
    {}
};

template<typename T>
using NewType = SuckType<int, T, 1>;

//传统c++中，模板只有使用时才会被实例化
//编译文件中编译的代码中遇到完整定义的模板，都会进行实例化
//进而会重复实例化导致编译时间增加，并且无法通知编译器不要触发模板实例化

//1.c++11引入外部模板，显示通道编译器何时进行模板实例化
template class vector<int>; //强行实例化
extern template class vector<double>; //不在该编译文件中实例化模板
//指定模板的默认参数
template<typename T = int, typename U = int>
auto add(T x, U y) -> decltype(x+y)
{
    return x+y;
}
//c++11允许任意个数，任意类别的模板参数，同时也不需要在定义时将参数的个数固定
template<typename... Args>
void magic(Args... args)
{
    cout << "sizeof:" << sizeof...(args) << endl;
}
int main()
{
    //模板增强
    
    //传统c++，">>"一律被当做右移运算符
    //2.引入">"
    vector< vector<int>> doublevec;
    cout << "double vec." << endl;
    //传统c++：模板是用来产生类型的，typedef可以为类型定义一个新的名称，但不能为模板定义一个类型，因为模板不是类型
    //3.c++11 使用using引入类型别名模板
    typedef int (*process) (void *); //定义一个返回类型为int，参数为void *的函数指针，名字叫process
    using process = int(*)(void *);  //含义同上，更加直观
    //4.默认模板参数,c++11可以指定模板的默认参数
    cout << add(2,3) << endl;
    //5.变长参数模板
    magic();
    magic(1);
    magic(1,1.1);

    return 0;
}
