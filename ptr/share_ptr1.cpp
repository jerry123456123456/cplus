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
    cout<<*sp1<<endl;     //取值的时候跟普通指针一样，解引用就是数据
    //相当于shared_ptr<int>sp2(new int(100));

    //2.
    //shared_ptr<int>p=new int(1);    不能将一个原始指针直接复制给智能指针
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
    delete p;   //这个不能轻易使用，

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
    int size = 5; // 数组大小为5

    // 使用 lambda 表达式作为自定义删除器，用于释放动态数组内存
    std::shared_ptr<int> arrayPtr(new int[size], [](int* ptr) {
        delete[] ptr;
    });

    // 给数组赋值
    for (int i = 0; i < size; ++i) {
        arrayPtr.get()[i] = i * 10; // 等价于 *(arrayPtr.get() + i) = i * 10;
    }

    // 访问数组元素
    for (int i = 0; i < size; ++i) {
        std::cout << arrayPtr.get()[i] << " "; // 输出数组元素
    }
    std::cout << std::endl;

    return 0;
}