#include "Message.h"
#include <iostream>
#include <iomanip>
#include <ctime>

Message::Message(const std::string& sender, const std::string& recipient)
    : sender(sender), recipient(recipient), timestamp(std::chrono::system_clock::now()) {}

void Message::append(const std::string& line) {
    text += line + "\n";
}

std::string Message::to_string() const {
    std::time_t time = std::chrono::system_clock::to_time_t(timestamp);
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &time); // 使用 ctime_s 以避免不安全的调用
    return "From: " + sender + "\nTo: " + recipient + "\nTime: " + std::string(buffer) + "Message: " + text;
}

void Message::print() const {
    std::cout << to_string() << std::endl;
}

void Message::setTime(std::chrono::system_clock::time_point newTime) {
    timestamp = newTime;
}

