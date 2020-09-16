#include "pch.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int NumberOf1Between1AndN_Solution(int n)
{
	int numOf1 = 0;
	int count = 0;
	int temp = 0;
	if (n < 1)
		return 0;
	for (int i = 1; i <= n; i++) {
		temp = i;
		while (temp) {
			if (temp % 10 == 1) {
				count++;
			}
			temp = temp / 10;
		}
	}
	return count;
}

int main() {
	cout << NumberOf1Between1AndN_Solution(10) << endl;
}