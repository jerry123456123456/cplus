#include<iostream>
#include<memory>
using namespace std;

//2.
weak_ptr<int> gw;
void f(){
    auto spt=gw.lock();
    if(gw.expired()){
        cout<<"gw��Ч����Դ�Ѿ��ͷ�!"<<endl;
    }else{
        cout<<"gw��Ч��"<<*spt<<endl;
    }
}

int main(){
    //1.weak_ptr�Ĺ����������������count�����ӻ��߼���
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