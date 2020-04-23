#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5};
    //区间迭代
    for(auto &x : arr)
    {
        cout << x << endl;
    }
    //原始遍历方法
    vector<int> vec(5, 100);
    for(vector<int>::iterator i = vec.begin(); i != vec.end(); ++i)
    {
        cout << *i << endl;
    }
    //C++11
    for(auto &i : vec)
    {
        cout << i << endl;
    }

    return 0;
}
