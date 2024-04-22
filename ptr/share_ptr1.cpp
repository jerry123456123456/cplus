#if 0

#include<iostream>
#include<memory>
using namespace std;

void test(shared_ptr<int>sp){
    cout<<sp.use_count()<<endl;
}

//5.
class A : public enable_shared_from_this<A>{
public:
    shared_ptr<A>GetSelf(){
        return shared_from_this();
    }
    A(){
        cout<<"Construction A"<<endl;
    }
    ~A(){
        cout<<"Destruction A"<<endl;
    }
};

int main(){
    //1.
    auto sp1=make_shared<int>(100);
    cout<<*sp1<<endl;     //ȡֵ��ʱ�����ָͨ��һ���������þ�������
    //�൱��shared_ptr<int>sp2(new int(100));

    //2.
    //shared_ptr<int>p=new int(1);    ���ܽ�һ��ԭʼָ��ֱ�Ӹ��Ƹ�����ָ��
    shared_ptr<int>p1;
    p1.reset(new int(1));
    shared_ptr<int>p2=p1;

    //3.
    cout<<p2.use_count()<<endl;
    p1.reset();
    cout<<p1.use_count()<<endl;
    cout<<p2.use_count()<<endl;

    //4.
    //p2[0]=1;
    int *p=p2.get();
    delete p;   //�����������ʹ�ã�

    //5.
    shared_ptr<A>a1(new A);
    shared_ptr<A>a2=a1->GetSelf();
    cout<<a1.use_count()<<endl;
    cout<<a2.use_count()<<endl;
    cout<<"leave{}"<<endl;

    return 0;
}

#endif

#include <iostream>
#include <memory>

int main() {
    int size = 5; // �����СΪ5

    // ʹ�� lambda ���ʽ��Ϊ�Զ���ɾ�����������ͷŶ�̬�����ڴ�
    std::shared_ptr<int> arrayPtr(new int[size], [](int* ptr) {
        delete[] ptr;
    });

    // �����鸳ֵ
    for (int i = 0; i < size; ++i) {
        arrayPtr.get()[i] = i * 10; // �ȼ��� *(arrayPtr.get() + i) = i * 10;
    }

    // ��������Ԫ��
    for (int i = 0; i < size; ++i) {
        std::cout << arrayPtr.get()[i] << " "; // �������Ԫ��
    }
    std::cout << std::endl;

    return 0;
}