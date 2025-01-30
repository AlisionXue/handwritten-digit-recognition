CSC 155
Lab #7
Message class
Design a class Message that models an e - mail message.A message has a recipient, a sender, a message
text, and a time stamp.Support the following member functions :
? A constructor that takes the sender and recipient and sets the time stamp to the current time
o Use the Time class provided in the files : ccc_time.h and ccc_time.cpp from Course
Files in D2L for the time stamp information
? A member function append that appends a line of text to the message body
? A member function to_string that makes the message into one long string like this :
	¡°From : Harry\nTo : Rudolf Reindeer\n ...¡±
	? A member function print that prints the message text.Use to_string function in the
	implementation of this function
	? A member function setTime that allows the time stamp to be changed
	Use the provided header file Message.h from Course Files in D2L.
	Implement the Message class in the file Message.cpp.Write a driver program that uses this class to
	make a message and print it.Also, test the setTime function and confirm the results by printing the
	initial message.
	Here is an example driver program :
#include "Message.h"
#include <iostream>
using namespace std;
int main() {
	Message my_message = Message("Jim", "Bob");
	my_message.append("Hello buddy! I miss you!");
	my_message.print();
	Time changed(5, 45, 30);
	my_message.setTime(changed);
	my_message.print();
	return 0;
}