#include "pch.h"
#include "replaceSpace.h"
#include <string>
#include <iostream>
#include <vector>
#include "replaceSpace.h"
#include <windows.h>

using namespace std;

void replaceSpace(char *str, int length) {
	//vector<string> strData;
	int spaceCnt = 0;
	int strLength = 0, i, j;
	if (str == nullptr)
		return;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == 0x20) {
			spaceCnt++;
		}
	}
	strLength = i + 1;
	if ((strLength + spaceCnt * 2) > length)
		return;
	j = strLength + spaceCnt * 2 - 1;
	for (i = strLength - 1; i >= 0; i--) {
		if (str[i] == 0x20) {
			str[j] = '0';
			str[j - 1] = '2';
			str[j - 2] = '%';
			j = j - 3;
		}
		else {
			str[j] = str[i];
			j = j - 1;
		}
	}
}

int main()
{
	std::cout << "RE Hello World!\n";
	string inputline;
	getline(cin, inputline);
	
	char *c = nullptr;
	const char * constc = nullptr;
	constc = inputline.c_str();
	c = const_cast<char *>(constc);
	int length = 3 * inputline.length();
	replaceSpace(c, length);
	cout << constc << endl;
}