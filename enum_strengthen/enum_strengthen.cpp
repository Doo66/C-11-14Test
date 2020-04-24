#include <iostream>
using namespace std;

enum class new_a_enum : unsigned int
{
    value1,
    value2,
    value3 = 100,
    value4 = 100
};


enum class new_b_enum : unsigned int
{
    value1,
    value2,
    value3 = 100,
    value4 = 100
};

int main()
{
    if (new_a_enum::value3 == new_a_enum::value4)
    {
        cout << "==" << endl;
    }
    else
    {
        cout << "!=" << endl;
    }

    //非法，类型安全
    /*if(new_a_enum::value3 == new_b_enum::value3)
    {
        cout << "==" << endl;
    }
    else
    {
        cout << "!=" << endl;
    }*/
    return 0;
}
