//constexpr特性：
//1.让用户显式声明函数或对象构造函数在编译器会成为常数
//2.使用递归
//
#include <iostream>
#include <fstream>
using namespace std;
constexpr int fibonacci(const int n)
{
    return n == 1 || n == 2 ? 1 : fibonacci(n-1) + fibonacci(n-2);

}

int main()
{
    int i;
    ofstream mycout("ret.txt");
    std::cout << "Enter a number:";
    mycout << "Enter a number:";
    std::cin >> i;
    mycout << i << std::endl;
    std::cout << i << " fibonacci val is " << fibonacci(i) << std::endl;
    mycout << i << " fibonacci val is " << fibonacci(i) << std::endl;
    mycout.close();
    return 0;
}




