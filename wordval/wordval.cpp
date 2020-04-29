#include <iostream>
#include <string>
// 字面量
// C++11 提供了原始字符串字面量的写法，可以在一个字符串前方使用 R 来修饰这个字符串，同时，将原始字符串使用括号包裹
// 1.原始字符串字面量 R"()"
// 2.自定义字面量    重载""后缀运算符实现
//
// 自定义字面量支持四种字面量：
// 1.整型字面量：重载时必须使用 unsigned long long、const char *、模板字面量算符参数，在上面的代码中使用的是前者；
// 2.浮点型字面量：重载时必须使用 long double、const char *、模板字面量算符；
// 3.字符串字面量：必须使用 (const char *, size_t) 形式的参数表；
// 4.字符字面量：参数只能是 char, wchar_t, char16_t, char32_t 这几种类型

// 字符串字面量自定义必须设置如下的参数列表
std::string operator"" _wow1(const char *wow1, size_t len) {
    return std::string(wow1)+"woooooooooow, amazing";
}

std::string operator"" _wow2 (unsigned long long i) {
    return std::to_string(i)+"woooooooooow, amazing";
}

int main()
{   
    // 原始字符串字面量
    std::string str = R"(C:\\what\\the\\kkkk)";
    std::cout << str << std::endl;
    
    // 自定义字面量
    auto zstr = "abc"_wow1;
    auto znum = 1_wow2;
    std::cout << zstr << std::endl;
    std::cout << znum << std::endl;

    return 0;
}
