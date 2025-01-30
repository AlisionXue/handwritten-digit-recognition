#include "Message.h"

// Constructor
Message::Message(const std::string& sender, const std::string& recipient)
    : sender(sender), recipient(recipient) {}

// Append text to the message body
void Message::append(const std::string& text) {
    messageBody += text + "\n";
}

// Convert the message to a string format
std::string Message::toString() const {
    return "From: " + sender + "\nTo: " + recipient + "\n\n" + messageBody;
}

// Print the message
void Message::print() const {
    std::cout << toString();
}
