#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

//1.左值、右值、纯右值、将亡值
//左值:表达式之后依然存在的值
//右值:表达式之后不再存在的值
//纯右值:纯粹的右值（字面量\非引用返回的临时变量\运算表达式产生的临时变量\原始字面量\lambda表达式）
//将亡值:即将被销毁、却能够被移动的值（临时的值能够被识别、同时又能够被移动）

//2.右值引用和左值引用
//左值引用
void reference(std::string& str) 
{
        std::cout << "左值" << std::endl;
}
//右值引用
void reference(std::string&& str) 
{
        std::cout << "右值" << std::endl;
}
//3.移动语义
//区分移动和拷贝的概念，移动节省时间、空间
class A{
    public:
    int* pointer;
    A():pointer(new int(1)){
        cout << "构造" << pointer << endl;
    }
    A(A& a):pointer(new int(*a.pointer)){
        cout << "拷贝" << pointer << endl;
    }
    A(A&& a):pointer(a.pointer){
        a.pointer = nullptr;
        cout << "移动" << pointer << endl;
    }
    ~A(){
        cout << "析构" << pointer << endl;
    }
};

// 防止编译器优化
A return_rvalue(bool test){
    A a,b;
    if(test)
        return a;
    else
        return b;
}
//4.完美转发
// 完美转发，就是为了让我们在传递参数的时候，保持原来的参数类型
// （左引用保持左引用，右引用保持右引用）
// 为了解决这个问题，我们应该使用 std::forward 来进行参数的转发（传递）
void ref(int& v){
    cout << "左值引用" << endl;
}
void ref(int&& v){
    cout << "右值引用" << endl;
}
template <typename T>
void pass(T&& v){
    cout << "普通传参:";
    ref(v);
    cout << "move 传参:";
    ref(move(v));
    cout << "forward 传参:";
    ref(forward<T>(v));
}

int main()
{
    string lv1 = "string,";          // lv1左值
    string && rv1 = move(lv1);      // move可以将左值转移为右值
    cout << "rv1 = " << rv1 << endl;
    
    const string& lv2 = lv1 + lv1;  // 合法, 常量左值引用能够延长临时变量的生命周期
    cout << "lv2 = " << lv2 << endl;

    string&& rv2 = lv1 + lv2;       // 合法, 右值引用延长临时对象的生命周期
    rv2 += "string";                // 合法, 非常量引用能够修改临时变量
    cout << "rv2 = " << rv2 << endl;

    cout << "&& rv1:";
    reference(move(lv1));
    cout << "rv1:"; 
    reference(rv1); 
    cout << "rv2:"; 
    reference(rv2); 
    
    A obj = return_rvalue(false);
    cout << "obj:" << endl;
    cout << obj.pointer << endl;
    cout << *obj.pointer << endl;

    //完美转发
    cout << "传递右值:" << endl;
    pass(1);
    cout << "传递左值:" << endl;
    int v = 1;
    pass(v);

    return 0;
}
