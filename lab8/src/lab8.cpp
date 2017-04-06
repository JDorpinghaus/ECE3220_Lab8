//============================================================================
// Name        : lab8.cpp
// Author      : Jacob Dorpinghaus
//============================================================================

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

class message{
public:
	message();
	message(string messageString);
	virtual ~message();
	virtual void print();
protected:
	string messageText;
};

class morseCodeMessage: public message{
public:
	morseCodeMessage();
	morseCodeMessage(string messageString);
	~morseCodeMessage();
	virtual void print();
private:
	void translate();
	string messageCode;
};

class messageStack{
public:
	messageStack(message* firstMessage);
	~messageStack();
	void push(message* messageObject);
	message* pop(void);
	void printStack(void);
private:
	vector <message*> stack;
};

int main() {
	message m1("message1");
	message m2;
	morseCodeMessage morse1("morse code message one");
	morseCodeMessage morse2;

	cout << "\n\n$$$$$$$$$$$$ MESSAGE 1 $$$$$$$$$$$$" << endl;
	m1.print();
	cout << "$$$$$$$$$$$$ MESSAGE 2 $$$$$$$$$$$$" << endl;
	m2.print();


	cout << "\n\n$$$$$$$$$$$$ MORSE MESSAGE 1 $$$$$$$$$$$$" << endl;
	morse1.print();
	cout << "$$$$$$$$$$$$ MORSE MESSAGE 2 $$$$$$$$$$$$" << endl;
	morse2.print();

	cout << "\n\n$$$$$$$$$$$$ MESSAGE STACK $$$$$$$$$$$$" << endl;
	messageStack stack(&m1);
	stack.push(&m2);
	stack.push(&morse1);
	stack.push(&morse2);
	stack.printStack();

	message* poppedMessage = stack.pop();
	cout << "\n\n$$$$$$$$$$$$ POPPED MESSAGE $$$$$$$$$$$$" << endl;
	poppedMessage->print();

	cout << "\n\n$$$$$$$$$$$$ MESSAGE STACK AFTER POP $$$$$$$$$$$$" << endl;
	stack.printStack();

	return 0;
}

message::message(){
	cout << "\nEnter your message: " << endl;
	getline(cin, messageText, '\n');
}

message::~message(){ //nothing to free
}

message::message(string messageString){
	messageText = messageString;
}

void message::print(){
	cout << messageText << endl;
}

morseCodeMessage::morseCodeMessage(string messageString) : message(messageString){ //calls message constructor to set message parameter
	translate();
}

morseCodeMessage::morseCodeMessage(){
	translate();
}

morseCodeMessage::~morseCodeMessage(){ //nothing to free
}

void morseCodeMessage::print(void){
	cout << messageText << endl;
	cout << messageCode << endl;
}

void morseCodeMessage::translate(){
	string morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
	"..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
	"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}; //only alpha characters supported with this array
	unsigned int i;
	string tempString;
	int position;
	for(i=0;i<messageText.length();i++){
		//if(!isalpha(messageText[i])){
		//	cout << "Error: only alpha characters allowed to be translated" << endl;
		//	exit(0);
		//}
		if(islower(messageText[i])){ //handle lowercase letters
			position = messageText[i] - 'a';
			messageCode += morse[position];
		} else if(isupper(messageText[i])){ //handle capital letters
			position = messageText[i] - 'A';
			messageCode += morse[position];
		} else{
			switch(messageText[i]){ //special cases for handling punctuation
			case '.':
				tempString = ".-.-.-";
				break;
			case ',':
				tempString = "--..--";
				break;
			case '?':
				tempString = "..--..";
				break;
			case ' ':
				tempString = " ";
				break;
			case '!':
				tempString = "-.-.--";
				break;
			case '\'':
				tempString = ".----.";
				break;
			default:
				cout << "ERROR invalid character \"" << messageText[i] << "\"" << endl; //only alpha characters and some punctuation supported
				exit(0);
			}
			messageCode += tempString;
		}
	}
}

messageStack::messageStack(message* firstMessage){
	stack.push_back(firstMessage);
}

messageStack::~messageStack(){
}

void messageStack::push(message* newMessage){
	stack.push_back(newMessage);
}

message* messageStack::pop(void){
	message* tempMessage;
	tempMessage = stack.back();
	stack.pop_back();
	return tempMessage;
}

void messageStack::printStack(void){
	int i;
	int size = stack.size();
	for(i=1;i<=size;i++){
		stack[size-i]->print();
	}
}
