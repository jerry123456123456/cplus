//智能指针成员函数

#if 0
//1.在智能指针中，`.get()` 是一个成员函数，用于获取指向的原始指针。当你需要访问智能指针所管理的对象，但又需要使用原始指针时，可以调用 `.get()` 函数来获取指向对象的原始指针。
#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> ptr(new int(42));

    // 使用 .get() 获取指向的原始指针
    int* rawPtr = ptr.get();

    if (rawPtr) {
        std::cout << "Value stored in the managed object: " << *rawPtr << std::endl;
    } else {
        std::cout << "The managed object is null." << std::endl;
    }

    return 0;
}
#endif

#if 0
//2. **reset()**：将智能指针重置为空，同时释放原有资源。
#include <memory>
int main() {
    std::shared_ptr<int> ptr(new int(42));
    
    ptr.reset(); // 重置智能指针为空

    return 0;
}
#endif

#if 0
//3. **operator->()**：用于通过智能指针访问所管理对象的成员
#include <memory>
#include <iostream>

class MyClass {
public:
    void print() {
        std::cout << "Hello from MyClass" << std::endl;
    }
};

int main() {
    std::shared_ptr<MyClass> ptr(new MyClass());
    
    ptr->print(); // 使用智能指针访问所管理对象的成员函数

    return 0;
}
#endif


//4. **use_count()**：获取共享指针的引用计数（仅适用于 `std::shared_ptr`）。
#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> ptr1(new int(42));
    std::shared_ptr<int> ptr2 = ptr1;
    
    std::cout << "Reference count: " << ptr1.use_count() << std::endl;

    return 0;
}