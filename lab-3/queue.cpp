#include <iostream>
#include <string>
using namespace std;

/**
	\class Class of move
*/
class move {
	move* Next;
	string Data;
public:
	move() : Next(nullptr), Data("") {};
	void push(string data);
	void get();
	void pop();
	~move() { if (Next != nullptr) delete Next; }
} Move;

/// \fn Adding element
void move::push(string data) {
	if (Next == nullptr)
		if (Data != "")
			Next = new move();
		else {
			Data = data;
			return;
		}
		Next->push(Data);
		Data = data;
}

/// \fn Getting element
void move::get() {
	if (Next == nullptr) {
		cout << Data << endl;
		return;
	}
	Next->get();
}

/// \fn Deleting element
void move::pop() {
	if (Next == nullptr) {
		Data = "";
		return;
	}
	else
		Next->pop();
}

/**
	\fn Main function of application
*/
int main() {
	size_t n;       ///Number of commands
	string line;    ///Command name
	cin >> n;
	for (size_t i = 0; i < n; i++) {
		cin >> line;
		if (line == "add") {
			cin >> line;
			Move.push(line);
		}
		else if (line == "get")
			Move.get();
		else if (line == "del")
			Move.pop();
		else
			return 1;

	}

	return 0;
}
