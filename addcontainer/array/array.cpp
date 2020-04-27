#include <iostream>
#include <array>
#include <algorithm>
//std::array:数组容器

//std::vector 堆内存
//std::array  栈内存
//提升性能

void foo(int* p, int len)
{
    std::cout << "foo()" << std::endl;
}

int main()
{
    //编译时创建一个固定大小数组
    std::array<int,4> arr = {2,1,4,3};
    //不能够被隐式转换为指针
    // foo(arr, arr.size());    // 非法，无法隐式转换
    foo(&arr[0], arr.size());
    foo(arr.data(), arr.size());
    //使用 sort
    std::sort(arr.begin(), arr.end());
    for(auto x : arr)
    {
        std::cout << x << std::endl;
    }
    return 0;
}
