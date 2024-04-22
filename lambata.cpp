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

//一般情况下编译器可以自动推断出lambada表达式的返回类型，所以也可以不用指定
template <typename T>
void test2(){
    cout<<"test2"<<endl;
    auto add=[](T a,T b){
        return a+b;
    };
    cout<<add(2,3)<<endl;
}

//lambada表达式还可以按值传递
void test3(){
    cout<<"test3"<<endl;
    int c=12;
    int d=20;
    auto add=[c,d](int a,int b)->int{    //c,d是补货列表
        cout<<"d="<<d<<endl;
        return a+b;
    };
    cout<<add(3,4)<<endl;
}

void test4(){
    cout<<"test4"<<endl;
    int a=0;
    auto change=[&a](){        //捕获列表引用传递会修改真是值
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
    cout<<add1()<<"  "<<add2()<<endl;          //第一个输出10，第二个输出20
}

//隐式捕获
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
    cout<<"c="<<c<<endl;      //内部修改无法改变外部的值
    d=50;
    cout<<add(1,2)<<endl;
}

//空捕获列表
void test7(){
    cout<<"test7"<<endl;
    int c=12;
    int d=20;
    auto add=[](int a,int b){
        //cout<<c<<d<<endl;  //编译报错
    return a+b;
    };
    cout<<add(3,6)<<endl;
}

//表达式捕获
void test8(){
    cout<<"test8"<<endl;
    auto important=make_unique<int>(1);
    //C++14之后支持右值捕获，允许捕获的成员以用任意的表达式进行初始化，被声明的捕获变量类型与auto功能类似
    auto add=[v1=1,v2=move(important)](int x,int y){
        return x+y+v1+(*v2);
    };
    cout<<add(3,4)<<endl;    //9
}

//泛型lambada
void test9(){
    cout<<"test9"<<endl;
    auto add=[](auto x,auto y){
        return x+y;
    };
    cout<<add(1,2)<<endl;
    cout<<add(1.1,2.2)<<endl;
}

//可变的lambada
void test10(){
    cout<<"test9"<<endl;
    int v=5;
    auto ff=[v]() mutable{return ++v;};
    cout<<v<<" "<<ff()<<endl;    //5  6
}

int main(){
    //test1();
    //test2<int>();  //使用模板类参数列表传递模版类型
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