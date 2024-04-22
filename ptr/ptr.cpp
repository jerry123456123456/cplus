//智能指针的两种创建方式

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
    // 使用 std::make_shared 创建 std::shared_ptr 智能指针
    std::shared_ptr<MyClass> ptr = std::make_shared<MyClass>(42);

    // 使用智能指针调用对象的成员函数
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
    // 使用 std::shared_ptr 的构造函数手动创建智能指针
    std::shared_ptr<MyClass> ptr(new MyClass(42));

    // 使用智能指针调用对象的成员函数
    ptr->printValue();

    return 0;
}