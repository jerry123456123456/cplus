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
        ap->bptr = bp;     //ѭ�����ã������count�����ڶ�����A��B�Լ��ͷŵ�ʱ�򶼻�-1�����Ƕ�Ϊ1���޷�����������������count��ֵ��Ϊ0 
        bp->aptr = ap;
    }
    cout<< "main leave" << endl;  // ѭ�����õ���ap bp�˳���������û������
    return 0;
}
