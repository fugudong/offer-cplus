#include "pch.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int numSum(int m)
{
	int sum = 0;

	if (m / 100) {
		sum += m/100 + (m/10)%10 + m%100;
	}
	else if (m / 10) {
		sum += m / 10 + m % 10;
	}
	else {
		sum += m;
	}

	return sum;
}

int replaceSpace(int m, int n, int k) {
	int i = 0, j = 0;
	int cubeCount = 0;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if ((numSum(i) + numSum(j)) <= k) {
				cubeCount++;
			}
		}
	}

	return cubeCount;
}

int main()
{
	std::cout << "RE Hello World!\n";
	int m, n, k;

	std::cin >>m >> n >> k;
	cout << replaceSpace(m, n, k) << endl;

}