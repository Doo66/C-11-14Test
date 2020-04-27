#include <iostream>
#include <memory>

// weak_ptr 解决特殊情况下资源无法释放的问题
// 弱引用不会引起引用计数增加
// weak_ptr 没有 * 运算符和 -> 运算符，不能对资源进行操作
// 唯一作用就是用于检查 std::shared_ptr 是否存在
// expired() 方法在资源未被释放时，会返回 true，否则返回 false

class A;
class B;

class A{
    public:
        // A 或 B 中至少有一个使用 weak_ptr
        std::weak_ptr<B> pointer;
        ~A()
        {
            std::cout << "A 被销毁" << std::endl;
        }   
};

class B{
    public:
        std::shared_ptr<A> pointer;
        ~B()
        {
            std::cout << "B 被销毁" << std::endl;
        }
};

int main()
{
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    a->pointer = b;
    b->pointer = a;
   
    return 0;
}
