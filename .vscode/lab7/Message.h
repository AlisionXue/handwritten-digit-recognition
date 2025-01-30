#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <chrono>  // ʹ�ñ�׼ʱ���

class Message {
public:
    Message(const std::string& sender, const std::string& recipient);
    void append(const std::string& line);
    std::string to_string() const;
    void print() const;
    void setTime(std::chrono::system_clock::time_point newTime);

private:
    std::string sender;
    std::string recipient;
    std::string text;
    std::chrono::system_clock::time_point timestamp;  // ʹ�ñ�׼ʱ���
};

#endif
