#include "Mailbox.h"
#include  "message.h"

void Mailbox::add_message(const Message& m) {
    inbox.push_back(m);
}

Message Mailbox::get_message(int index) const {
    if (index < 0 || index >= inbox.size()) {
        throw std::out_of_range("Index out of range");
    }
    return inbox[index];
}

void Mailbox::remove_message(int index) {
    if (index < 0 || index >= inbox.size()) {
        throw std::out_of_range("Index out of range");
    }
    inbox.erase(inbox.begin() + index);
}

void Mailbox::print() const {
    for (const auto& message : inbox) {
        message.print();
    }
}
