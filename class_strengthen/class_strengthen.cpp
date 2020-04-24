#include <iostream>
using namespace std;

class Base{
public:
    int value1;
    int value2;

    Base(){
        value1 = 1;
    }
    //1.c++11引入委托构造，可以使得构造函数可以在同一个类中一个构造函数调用另一个构造函数，目的简化代码
    Base(int value):Base(){ //委托Base()构造函数
        value2 = 2;
    }
};

class Subclass:public Base{
    public:
        //2.传统c++，构造函数如果需要继承是需要将参数一一传递，导致效率低下。c++利用using 引入继承构造函数，目的提升效率
        using Base::Base; //继承构造
};

//3.c++11为了防止意外重载虚函数，引入显示虚函数重载
//3.1 override 显示告知编译器进行重载，编译器将检查基类是否存在这样的虚函数，不存在无法通过编译
struct B{
        virtual void foo(int);
        virtual void fun() final;
};
struct D : B{
        virtual void foo(int) override;     //合法
        //virtual void foo(float) override;   //非法，父类没有此虚函数
};
//3.2 final 防止类被继续继承以及终止虚函数继续重载引入
struct Z1 final : B{
    //合法
};
/*struct Z2 : Z1{
    //非法
};*/

/*struct Z3 : B{
    void fun(); //非法，fun已 final
};*/

//显示禁用默认函数
//传统c++，编译器会默认为对象生成构造函数、析构函数等；
//1.导致无法精确控制默认函数的生成行为
//2.编译器产生的默认构造函数与用户定义的构造函数无法共同存在
//c++11 允许显示的声明采用或拒绝编译器自带的函数
class Magic{
    public:
        Magic() = default; //显示声明使用编译器生成的构造
        Magic& operator=(const Magic&) = delete; //显示声明拒绝编译器生成构造
        Magic(int magic_number) //与编译器生成的构造函数并存
        {
            _magic_number = 3; 
        }
    public:
        int _magic_number;
};
int main(){
    //1.委托构造
    Base b(2);
    cout << b.value1 << endl;
    cout << b.value2 << endl;
    //2.继承构造
    Subclass s(3);
    cout << s.value1 << endl;
    cout << s.value2 << endl;
    //3.显示虚函数重载
    
    //4.显示禁用默认函数
    Magic dm;
    cout << "defalut() val:" << dm._magic_number << endl;
    Magic um(2);
    cout << "user val:" << um._magic_number << endl;
    Magic cm = um;
    cout << "= val:" << cm._magic_number << endl;
    Magic cm2(um);
    cout << "() val:" << cm2._magic_number << endl;
    return 0;
}
