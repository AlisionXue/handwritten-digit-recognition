#ifndef MAILBOX_H
#define MAILBOX_H

#include <vector>
class Message;
class Mailbox {
public:
    void add_message(const Message& m);
    Message get_message(int index) const;
    void remove_message(int index);
    void print() const;

private:
    std::vector<Message> inbox;
};

#endif // MAILBOX_H
