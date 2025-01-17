// 1-3-2-cycle-shared-ptr
#include <iostream>
#include <memory>
using namespace std;


class A;
class B;

class A {
public:
    std::shared_ptr<B> bptr;
    ~A() {
        cout << "A is deleted" << endl;
    }
};

class B {
public:
    std::shared_ptr<A> aptr;
    ~B() {
        cout << "B is deleted" << endl;
    }
};

int main()
{
    {
        std::shared_ptr<A> ap(new A);
        std::shared_ptr<B> bp(new B);
        ap->bptr = bp;     //循环引用，互相的count都等于二，当A或B自己释放的时候都会-1，但是都为1，无法调用析构函数，将count的值减为0 
        bp->aptr = ap;
    }
    cout<< "main leave" << endl;  // 循环引用导致ap bp退出了作用域都没有析构
    return 0;
}
