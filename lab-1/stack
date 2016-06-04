#include "stdafx.h"
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;
struct stack
{
	int value;
	struct stack *next;
};

stack *st;

/** \func void push(int newvalue) */
void push(int newvalue)
{
	stack *node = new stack;
	if (st == 0)
	{
		node->value = newvalue;
		node->next = 0;
		st = node;
	}
	else
	{
		node->value = newvalue;
		node->next = st;
		st = node;
	}
}
int top()
{
	return st->value;
}
void del()
{
	if (st == NULL)
	{
		cout << "ñòåê ïóñòîé" << endl;
	}
	else
	{
		st = st->next;
	}

}
/*int main()
{
	setlocale(LC_CTYPE, "rus");
	int num, val;
	int m = 0;
	int exit[20];
	char str[64];
	char *act = new char[64];
	fstream fin;
	fin.open("text.txt", ios::in);
	if (fin.is_open())
	{
		fin.getline(str, 64);
		cout << str << endl;;
		num = atoi(str);
		for (int i = 0; i < num; i++)
		{
			fin.getline(str, 64);
			cout << str << endl;
			act = strtok(str, " ");
			if (!strcmp(act, "add"))
			{
				val = atoi(strtok(NULL, " "));
				push(val);
			}
			if (!strcmp(str, "del"))
			{
				del();
			}
			if (!strcmp(str, "get"))
			{
				exit[m] = top();
				m++;
			}
		}
	}
	for (int i = 0; i < m; i++)
		cout << exit[i] << endl;
	system("pause");
	return 0;
}*/
