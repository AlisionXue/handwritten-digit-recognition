#include "Message.h"
#include <iostream>
#include <chrono>

using namespace std;

int main() {
    // 创建一个消息对象
    Message my_message("Chang", "Ahmed");
    my_message.append("Hello Professor! Have a good day!");
    my_message.print();

    // 设置新的时间戳
    auto newTime = chrono::system_clock::now();
    my_message.setTime(newTime);
    my_message.print();

    return 0;
}
