#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool match(char* str, char* pattern)
{
	if (str == nullptr || pattern == nullptr)
		return false;
	if (*str == '\0' && *pattern == '\0')
		return true;
	if (*str != '\0' && *pattern == '\0')
		return false;


	if (*str == *pattern || (*pattern == '.'&&*str != '\0')) {
		if (*(pattern + 1) != '*') {
			return match(str + 1, pattern + 1);
		}
		else {
			return match(str + 1, pattern) || match(str + 1, pattern + 2) || match(str, pattern + 2);
		}
	}
	else {
		if (*(pattern + 1) != '*') {
			return false;
		}
		else {
			return match(str, pattern + 2);
		}
	}
}

int main() {


	return 0;
}