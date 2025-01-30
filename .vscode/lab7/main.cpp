#include "Message.h"
#include <iostream>
#include <chrono>

using namespace std;

int main() {
    // ����һ����Ϣ����
    Message my_message("Chang", "Ahmed");
    my_message.append("Hello Professor! Have a good day!");
    my_message.print();

    // �����µ�ʱ���
    auto newTime = chrono::system_clock::now();
    my_message.setTime(newTime);
    my_message.print();

    return 0;
}
