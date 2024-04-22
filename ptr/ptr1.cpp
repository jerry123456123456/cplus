//����ָ���Ա����

#if 0
//1.������ָ���У�`.get()` ��һ����Ա���������ڻ�ȡָ���ԭʼָ�롣������Ҫ��������ָ��������Ķ��󣬵�����Ҫʹ��ԭʼָ��ʱ�����Ե��� `.get()` ��������ȡָ������ԭʼָ�롣
#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> ptr(new int(42));

    // ʹ�� .get() ��ȡָ���ԭʼָ��
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
//2. **reset()**��������ָ������Ϊ�գ�ͬʱ�ͷ�ԭ����Դ��
#include <memory>
int main() {
    std::shared_ptr<int> ptr(new int(42));
    
    ptr.reset(); // ��������ָ��Ϊ��

    return 0;
}
#endif

#if 0
//3. **operator->()**������ͨ������ָ��������������ĳ�Ա
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
    
    ptr->print(); // ʹ������ָ��������������ĳ�Ա����

    return 0;
}
#endif


//4. **use_count()**����ȡ����ָ������ü������������� `std::shared_ptr`����
#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> ptr1(new int(42));
    std::shared_ptr<int> ptr2 = ptr1;
    
    std::cout << "Reference count: " << ptr1.use_count() << std::endl;

    return 0;
}