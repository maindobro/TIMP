#include "stdafx.h"
#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <sstream>
#include <string>
using namespace std;
class Base 
{
protected:
	int value;
public:
	Base() {};
	Base(int x) 
	{
		value = x;
	}
	virtual void show() = 0;
};
class A : public Base 
{
public: 
	A(int x) 
	{
		value = x;
	};
	void show() 
	{
		cout << "Class A: " << value << endl;

	}
};
class B: public Base 
{
public:
	B(int x) 
	{
		value = x;
	};
	void show() 
	{
		cout << "Class B: " << value << endl;
	}
};
class C : public Base 
{
public:
	C(int x) 
	{
		value = x;
	};
	void show() 
	{
		cout << "Class C: " << value << endl;
	}
};
vector<Base*> my_obj;
class Functor
{
public:
	virtual void operator()() {};
	virtual void operator()(string, int) {};
};

class FunctorShow : public Functor
{
public:
	FunctorShow() 
	{

	};
	void operator()() {

		for (auto it : my_obj)
			it->show();
	};
};

class FunctorCreate : public Functor
{
public:
	FunctorCreate() {};
	void operator()(string classname, int value) 
	{
		Base* obj;
		if (classname == "A")
			obj = new A(value);
		if (classname == "B")
			obj = new B(value);
		if (classname == "C")
			obj = new C(value);
		my_obj.push_back(obj);
	};
};
vector<string> split(const string &s, char delim)
{
	vector<string> elems;
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim))
		elems.push_back(item);

	return elems;
}
int main()
{
	string com;
	int n;
	map<string, Functor*> mfunc;
	Functor *f = new FunctorShow;
	Functor *fc = new FunctorCreate;
	mfunc["showall"] = f;
	mfunc["create"] = fc;
	Functor *fctr;
	cout << endl;
	cin >> n;;
	vector<string> commands;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 1; i <= n; i++)
	{
		getline(cin, com);
		commands = split(com, ' ');
		fctr = mfunc[commands[0]];

		if (commands.size() == 1)
			(*fctr)();
		else if (commands.size() == 3)
			(*fctr)(commands[1], stoi(commands[2]));
		else
		{
			cout << "Whoops...Try again!"; i--;
		}
	}

	system("pause");
	return 0;
}
