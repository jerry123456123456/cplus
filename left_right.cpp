#include <iostream>

using namespace std;

//用模版检测传递的t是左值还是右值
template <typename T>
void Print(T &t)
{
    cout << "L" << t << endl;
}

template <typename T>
void Print(T &&t)
{
    cout << "R" << t << endl;
}

template <typename T>
void func(T &&t)
{
    Print(t);
    Print(std::move(t));            //左值转右值
    Print(std::forward<T>(t));      //原来是什么值，转发就是什么值
}

int main()
{
    cout << "-- func(1)" << endl;
    func(1);
    int x = 10;
    int y = 20;
    cout << "\n-- func(x)" << endl;
    func(x);  // x本身是左值
    cout << "\n-- func(std::forward<int>(y))" << endl;
    func(std::forward<int>(y)); ////T为int，以右值方式转发y
    cout << "\n-- func(std::forward<int&>(y))" << endl;
    func(std::forward<int&>(y));   //以左值的方式转发
    cout << "\n-- func(std::forward<int&&>(y))" << endl;
    func(std::forward<int&&>(y));   //以右值的方式转发
    return 0;
}
