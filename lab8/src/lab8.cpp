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
	~message();
	void print();
protected:
	string messageText;
};

class morseCodeMessage: public message{
public:
	morseCodeMessage();
	morseCodeMessage(string messageString);
	void print();
private:
	void translate();
	string messageCode;
};

string morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
"..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

int main() {
	morseCodeMessage morse1();
	return 0;
}

message::message(){
	cout << "Enter your message: " << endl;
	cin >> messageText;
}

message::~message(){
}

message::message(string messageString){

}

void message::print(){
	cout << messageText << endl;
}

morseCodeMessage::morseCodeMessage(string messageString){
	messageText = messageString;
	translate();
}

morseCodeMessage::morseCodeMessage(){
	cout << "Enter your message: " << endl;
	cin >> messageText;
	translate();
}

void morseCodeMessage::print(void){
	cout << messageText << endl;
	cout << messageCode << endl;
}

void morseCodeMessage::translate(){
	unsigned int i;
	int position;
	for(i=0;i<messageText.length();i++){
		if(!isalpha(messageText[i])){
			cout << "Error: only alpha characters allowed to be translated" << endl;
			exit(0);
		}
		position = messageText[i] - 'a';
		messageCode += morse[position];
	}
}
