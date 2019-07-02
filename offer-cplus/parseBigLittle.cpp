#include "pch.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool duplicate(int numbers[], int length, int* duplication) {
	if (numbers == nullptr || length <= 0)
		return false;
	int *temp = new int(length);
	memset(temp, 0, length*sizeof(int));
	for (int i = 0; i < length; i++) {
		if (temp[numbers[i]] == 1) {
			*duplication = numbers[i];
			return true;
		}
		else {
			temp[numbers[i]] = 1;
		}

	}
	return false;
}

int main()
{
	
}