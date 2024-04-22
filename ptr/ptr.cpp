//����ָ������ִ�����ʽ

/*
#include <memory>
#include <iostream>

class MyClass {
public:
    MyClass(int value) : m_value(value) {}
    void printValue() {
        std::cout << "Value: " << m_value << std::endl;
    }
private:
    int m_value;
};

int main() {
    // ʹ�� std::make_shared ���� std::shared_ptr ����ָ��
    std::shared_ptr<MyClass> ptr = std::make_shared<MyClass>(42);

    // ʹ������ָ����ö���ĳ�Ա����
    ptr->printValue();

    return 0;
}
*/

#include <memory>
#include <iostream>

class MyClass {
public:
    MyClass(int value) : m_value(value) {}
    void printValue() {
        std::cout << "Value: " << m_value << std::endl;
    }
private:
    int m_value;
};

int main() {
    // ʹ�� std::shared_ptr �Ĺ��캯���ֶ���������ָ��
    std::shared_ptr<MyClass> ptr(new MyClass(42));

    // ʹ������ָ����ö���ĳ�Ա����
    ptr->printValue();

    return 0;
}