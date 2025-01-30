#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <iostream>

class Message {
public:
    Message(const std::string& sender, const std::string& recipient);  // Constructor
    void append(const std::string& text);  // Append text to the message
    std::string toString() const;  // Convert message to a string
    void print() const;  // Print the message

private:
    std::string sender;
    std::string recipient;
    std::string messageBody;
};

#endif

