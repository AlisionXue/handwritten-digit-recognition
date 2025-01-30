#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <iostream>

class Message {
public:
    Message(const std::string& sender, const std::string& recipient, const std::string& text)
        : sender(sender), recipient(recipient), text(text) {}

    void print() const {
        std::cout << "From: " << sender
            << "\nTo: " << recipient
            << "\nMessage: " << text << std::endl;
    }

private:
    std::string sender;
    std::string recipient;
    std::string text;
};

#endif // MESSAGE_H
