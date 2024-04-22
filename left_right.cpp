#include <iostream>

using namespace std;

//��ģ���⴫�ݵ�t����ֵ������ֵ
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
    Print(std::move(t));            //��ֵת��ֵ
    Print(std::forward<T>(t));      //ԭ����ʲôֵ��ת������ʲôֵ
}

int main()
{
    cout << "-- func(1)" << endl;
    func(1);
    int x = 10;
    int y = 20;
    cout << "\n-- func(x)" << endl;
    func(x);  // x��������ֵ
    cout << "\n-- func(std::forward<int>(y))" << endl;
    func(std::forward<int>(y)); ////TΪint������ֵ��ʽת��y
    cout << "\n-- func(std::forward<int&>(y))" << endl;
    func(std::forward<int&>(y));   //����ֵ�ķ�ʽת��
    cout << "\n-- func(std::forward<int&&>(y))" << endl;
    func(std::forward<int&&>(y));   //����ֵ�ķ�ʽת��
    return 0;
}
