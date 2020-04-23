/*
 1.auto不能用于函数传参
 2.auto不能用于推导数组类型
 */
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;

    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(4);

    for(auto iter = vec.cbegin(); iter != vec.cend(); ++iter)
    {
       std::cout << *iter << std::endl;
    }
    return 0;
}
