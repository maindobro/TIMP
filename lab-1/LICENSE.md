#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;
int main()
{
	char  buff[100];
	ifstream file;
	file.open("input.txt");
	 if (file.is_open()){
	while (file) {
		file >> buff;
		if (!strcmp(buff, "/**")) {
			file >> buff;
			if (!strcmp(buff, "\\func")) {
				while (strcmp(buff, "*/")) {
					file >> buff;
					if (strcmp(buff, "*/")) {
						cout << buff << " ";
					}
					else {
						cout << "\n";
					}
				}
			}
		}
	}
}
	system("pause");
	return 0;

}
