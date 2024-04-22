#include<iostream>
#include<memory>
using namespace std;

//2.
weak_ptr<int> gw;
void f(){
    auto spt=gw.lock();
    if(gw.expired()){
        cout<<"gw无效，资源已经释放!"<<endl;
    }else{
        cout<<"gw有效："<<*spt<<endl;
    }
}

int main(){
    //1.weak_ptr的构造和析构不会引起count的增加或者减少
    shared_ptr<int>sp(new int(10));
    weak_ptr<int>wp(sp);
    cout<<sp.use_count()<<endl;
    cout<<wp.use_count()<<endl;

    //2.
    {
        auto sp=make_shared<int>(42);
        gw=sp;
        f();
    }
    f();

    return 0;
}