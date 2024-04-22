#include<iostream>
#include<memory>
using namespace std;

void test1(){
    cout<<"test1"<<endl;
    auto add=[](int a,int b)->int{
        return a+b;
    };
    cout<<add(1,2)<<endl;
}

//һ������±����������Զ��ƶϳ�lambada���ʽ�ķ������ͣ�����Ҳ���Բ���ָ��
template <typename T>
void test2(){
    cout<<"test2"<<endl;
    auto add=[](T a,T b){
        return a+b;
    };
    cout<<add(2,3)<<endl;
}

//lambada���ʽ�����԰�ֵ����
void test3(){
    cout<<"test3"<<endl;
    int c=12;
    int d=20;
    auto add=[c,d](int a,int b)->int{    //c,d�ǲ����б�
        cout<<"d="<<d<<endl;
        return a+b;
    };
    cout<<add(3,4)<<endl;
}

void test4(){
    cout<<"test4"<<endl;
    int a=0;
    auto change=[&a](){        //�����б����ô��ݻ��޸�����ֵ
        a=3;
    };
    change();
    cout<<a<<endl;
}

void test5(){
    cout<<"test5"<<endl;
    int a=10;
    auto add1=[a](){
        return a;
    };
    auto add2=[&a](){
        return a;
    }; 
    a=20;
    cout<<add1()<<"  "<<add2()<<endl;          //��һ�����10���ڶ������20
}

//��ʽ����
void test6(){
    cout<<"test6"<<endl;
    int c=12;
    int d=30;
    auto add=[&](int a,int b)->int{
        c=a;
        cout<<"d="<<d<<endl;
        cout<<"c="<<c<<endl;
        return a+b;
    };
    cout<<"c="<<c<<endl;      //�ڲ��޸��޷��ı��ⲿ��ֵ
    d=50;
    cout<<add(1,2)<<endl;
}

//�ղ����б�
void test7(){
    cout<<"test7"<<endl;
    int c=12;
    int d=20;
    auto add=[](int a,int b){
        //cout<<c<<d<<endl;  //���뱨��
    return a+b;
    };
    cout<<add(3,6)<<endl;
}

//���ʽ����
void test8(){
    cout<<"test8"<<endl;
    auto important=make_unique<int>(1);
    //C++14֮��֧����ֵ����������ĳ�Ա��������ı��ʽ���г�ʼ�����������Ĳ������������auto��������
    auto add=[v1=1,v2=move(important)](int x,int y){
        return x+y+v1+(*v2);
    };
    cout<<add(3,4)<<endl;    //9
}

//����lambada
void test9(){
    cout<<"test9"<<endl;
    auto add=[](auto x,auto y){
        return x+y;
    };
    cout<<add(1,2)<<endl;
    cout<<add(1.1,2.2)<<endl;
}

//�ɱ��lambada
void test10(){
    cout<<"test9"<<endl;
    int v=5;
    auto ff=[v]() mutable{return ++v;};
    cout<<v<<" "<<ff()<<endl;    //5  6
}

int main(){
    //test1();
    //test2<int>();  //ʹ��ģ��������б���ģ������
    //test3();
    //test4();
    //test5();
    //test6();
    //test7();
    //test8();
    //test9();
    test10();
    return 0;
}