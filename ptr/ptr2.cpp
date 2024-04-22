#include <iostream>
#include <memory>
#include <thread>

void threadFunction() {
    std::cout << "Thread is running" << std::endl;
}

int main() {
    // ʹ�� std::make_shared ����һ�� shared_ptr �������̶߳���
    auto threadPtr = std::make_shared<std::thread>(threadFunction);

    // �ȴ��߳�ִ�����
    threadPtr->join();

    std::cout << "Thread has completed" << std::endl;

    return 0;
}