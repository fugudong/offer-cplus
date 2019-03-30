#include "pch.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include "parseBigLittle.h"
#include <algorithm>

using namespace std;

void replaceSpace(char *str, int n) {
	vector<int> index;
	vector<char> outputStr;
	int i = 0, j, strLen;
	//cout << "ori"<<endl << str << endl;
	while (str[i] != '\0') {
		if (str[i] == '0' || str[i] == '1') {
			index.push_back(i);
		}
		i++;
	}
	strLen = i;
	index.push_back(i);
	for (j = 0; j < index.size()-1; j++) {
		if (str[index[j]] == '0') {
			reverse(&str[index[j]+1], &str[index[j+1]]);
		}
	}
	i = 0;
	while (str[i] != '\0') {
		if (str[i] == '0' || str[i] == '1') {
			str[i] = ' ';
		}
		i++;
	}
	for (i = 0; i < strLen; i++) {
		str[i] = str[i + 1];
	}
	//strcpy_s(str, strLen,str + 1);
	str[strLen - 1] = '\0';
	//cout << "parse"<<endl<<str << endl;
}

int main()
{
	std::cout << "RE Hello World!\n";
	int n;
	string inputline;
	std::cin >> n;

	//getline(cin, inputline);
	std::cin >> inputline;
	char *c = nullptr;
	const char * constc = nullptr;
	constc = inputline.c_str();
	c = const_cast<char *>(constc);
	replaceSpace(c, n);
}