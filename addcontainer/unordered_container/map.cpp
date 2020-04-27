#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

// 无序容器 底层实现:哈希表
// 1.std::unordered_map/std::unordered_multimap
// 2.std::unordered_set/std::unordered_multiset
// 有序容器 底层实现:红黑树
// 1.std::map/std::multimap
// 2.std::set/std::multiset

int main()
{
    //同样方式初始化
    std::unordered_map<int, std::string> umap = {
        {1, "1"},
        {3, "3"},
        {2, "2"}
    };

    std::map<int, std::string> nmap = {
        {1, "1"},
        {3, "3"},
        {2, "2"}
    };

    // 分别对两种容器进行遍历
    std::cout << "std::unordered_map" << std::endl;
    for (const auto &n : umap)
    {
        std::cout << "key:[" << n.first << "] value: [" << n.second << "]\n";
    }

    std::cout << std::endl;
    std::cout << "std::map" << std::endl;
    for (const auto &n : nmap)
    {
        std::cout << "key:[" << n.first << "] value: [" << n.second << "]\n";
    }

    return 0;
}
