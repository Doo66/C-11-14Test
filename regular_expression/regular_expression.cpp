#include <iostream>
#include <regex>
#include <string>

// 正则表达式:正则表达式是由普通字符（例如 a 到 z）以及特殊字符组成的文字模式。模式描述在搜索文本时要匹配的一个或多个字符串。正则表达式作为一个模板，将某个字符模式与所搜索的字符串进行匹配

// 需求:
// 1.检查一个串是否包含某种形式的子串
// 2.将匹配的子串替换
// 3.从某个串中取出符合条件的子串

// (1).普通字符包括没有显式指定为元字符的所有可打印和不可打印字符。这包括所有大写和小写字母、所有数字、所有标点符号和一些其他符号
// (2).特殊字符是正则表达式里有特殊含义的字符，也是正则表达式的核心匹配语法。参见下表：
//
// 特别字符             描述
//  $            匹配输入字符串的结尾位置。
//  (,)          标记一个子表达式的开始和结束位置。子表达式可以获取供以后使用。
//  *            匹配前面的子表达式零次或多次。
//  +            匹配前面的子表达式一次或多次。
//  .            匹配除换行符 \n 之外的任何单字符。
//  [            标记一个中括号表达式的开始。
//  ?            匹配前面的子表达式零次或一次，或指明一个非贪婪限定符。
//  \            将下一个字符标记为或特殊字符、或原义字符、或向后引用、或八进制转义符。例如， n 匹配字符 n。\n 匹配换行符。序列 \\ 匹配 '\' 字符，而 \( 则匹配 '(' 字符。
//  ^            匹配输入字符串的开始位置，除非在方括号表达式中使用，此时它表示不接受该字符集合。
//  {            标记限定符表达式的开始。
//  |            指明两项之间的一个选择。
// (3).限定符
// 用来指定正则表达式的一个给定的组件必须要出现多少次才能满足匹配
// 字符                 描述
//  *           匹配前面的子表达式零次或多次。例如，foo* 能匹配 fo 以及 foooo。* 等价于{0,}。
//  +           匹配前面的子表达式一次或多次。例如，foo+ 能匹配 foo 以及 foooo，但不能匹配 fo。+ 等价于 {1,}。
//  ?           匹配前面的子表达式零次或一次。例如，Your(s)? 可以匹配 Your 或 Yours 中的Your 。? 等价于 {0,1}。
//  {n}         n 是一个非负整数。匹配确定的 n 次。例如，f{2} 不能匹配 for 中的 o，但是能匹配 foo 中的两个 o。
//  {n,}        n 是一个非负整数。至少匹配 n 次。例如，f{2,} 不能匹配 for 中的 o，但能匹配 foooooo 中的所有 o。o{1,} 等价于 o+。o{0,} 则等价于 o*。
//  {n,m}       m 和 n 均为非负整数，其中 n 小于等于 m。最少匹配 n 次且最多匹配 m 次。例如，o{1,3} 将匹配 foooooo 中的前三个 o。o{0,1} 等价于 o?。注意，在逗号和两个数之间不能有空格

// std::regex       进行初始化
// std::regex_match 进行匹配,产生std::smatch对象

int main()
{
    std::string fnames[] = {"foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt"};
    std::regex txt_regex("[a-z]+\\.txt");

    for(const auto& fname:fnames)
    {
        std::cout << fname << ":" << std::regex_match(fname, txt_regex) << std::endl;
    }
    
    std::regex base_regex("([a-z]+)\\.txt");
    std::smatch base_match;
    for(const auto& fname:fnames){
        if(std::regex_match(fname, base_match, base_regex)){
            // sub_match 的第一个元素匹配整个字符串
            // sub_match 的第二个元素匹配了第一个括号表达式
            if(base_match.size() == 2){
                std::string base = base_match[1].str();
                std::cout << "sub-match[0]: " << base_match[0].str() << std::endl;
                std::cout << fname << " sub-match[1]: " << base << std::endl;
            }
        }
    }   

    return 0;
}
