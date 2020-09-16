#include "pch.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool Increment(char *number) {
	bool isOverFlow = false;
	int nLength = strlen(number);
	int nTakeOver = 0;
	for (int i = nLength - 1; i >= 0; i--) {
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1) {
			nSum++;
		}
		if (nSum >= 10) {
			if (i == 0) {
				isOverFlow = true;
			}
			else {
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else {
			number[i] = '0' + nSum;
			break;
		}
	}
	return isOverFlow;
}

void PrintNumber(char *number) {
	bool isBegin = true;
	int nLength = strlen(number);
	for (int i = 0; i < nLength; i++) {
		if (isBegin&&(number[i]!='0') ){
			isBegin = false;
		}
		if (!isBegin) {
			printf("%c", number[i]);
		}
	}
	
}

void Print1ToMaxOfNDigits(int n) {
	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';
	while (!Increment(number)) {
		PrintNumber(number);
		printf("\n");
	}
}

int main()
{
	Print1ToMaxOfNDigits(2);
	return 0;
}