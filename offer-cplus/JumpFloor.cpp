#include "pch.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int jumpFloor(int number) {
	int result[3] = { 0, 1, 2 };
	if (number <= 2) {
		return result[number];
	}
	return jumpFloor(number - 1) + jumpFloor(number - 2);
}

int Fibonacci(int n) {
	int result[2] = { 0, 1 };
	if (n < 2) {
		return result[n];
	}

	int f1 = 0, f2 = 1, f3 = 0, cnt = 2;
	while (cnt <= n) {
		f3 = f2 + f1;
		f1 = f2;
		f2 = f3;
		cnt++;
	}

	return f3;
}

int main() {
	int number = 200;

	//cout << jumpFloor(number) << endl;
	cout << Fibonacci(number) << endl;
}