#include <iostream>
#include <tuple>
#include <string>

// std::tuple 元组      存放多种类型多个元素
// std::pair  键值对    存放多种类型两个元素
// 1.基本操作
// std::make_tuple  构造元组
// std::get         获得元组某个位置的值
// std::tie         元组拆包
// 2.运行期索引 std::get<>依赖编译器常量
// 3.元组合并与遍历
// 合并 std::tuple_cat auto new_tuple = tuple_cat(get_student(1), move(t))
// 遍历 std::tuple_size

auto get_student(int id)
{
    // 返回类型被推断为 std::tuple<double, char, std::string>
    
    if (id == 0)
        return std::make_tuple(3.8, 'A', "张三");
    if (id == 1)
        return std::make_tuple(2.9, 'C', "李四");
    if (id == 2)
        return std::make_tuple(1.7, 'D', "王五");
    return std::make_tuple(0.0, 'D', "null"); //else

}

int main()
{
    auto student = get_student(0);
    std::cout << "ID:0, "
        << "GPA: "  << std::get<0>(student) << ", "
        << "成绩: " << std::get<1>(student) << ", "
        << "姓名: " << std::get<2>(student) << '\n';

    double gpa;
    char grade;
    std::string name;

    // 元组进行拆包
    std::tie(gpa, grade, name) = get_student(1);
    std::cout << "ID: 1, "
        << "GPA: " << gpa << ", "
        << "成绩: " << grade << ", "
        << "姓名: " << name << '\n';
    
    return 0;
}
