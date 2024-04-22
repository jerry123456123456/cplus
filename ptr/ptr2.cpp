#include <iostream>
#include <memory>
#include <thread>

void threadFunction() {
    std::cout << "Thread is running" << std::endl;
}

int main() {
    // 使用 std::make_shared 创建一个 shared_ptr 来管理线程对象
    auto threadPtr = std::make_shared<std::thread>(threadFunction);

    // 等待线程执行完成
    threadPtr->join();

    std::cout << "Thread has completed" << std::endl;

    return 0;
}