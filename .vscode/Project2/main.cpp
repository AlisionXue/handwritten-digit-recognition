#include "Message.h"

int main() {
    Message email("Alice", "Bob");
    email.append("Hello Bob, I hope you are well.");
    email.print();

    return 0;
}