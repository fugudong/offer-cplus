#include "pch.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int  NumberOf1(int n) {
	int count = 0;
	while (n) {
		count++;
		n = n & (n - 1);
	}
	return count;
}

int main() {
	cout << NumberOf1(9) << endl;
}