#include "pch.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;


double Power(double base, int exponent) { 
	if (exponent == 0) {
		return 1;
	}
	if (exponent == 1) {
		return base;
	}
	if (base == 0) {
		return 0.0;
	}
	int absExponent = exponent;
	if (exponent < 0) {
		absExponent = -exponent;
	}
	double result = 1.0;
	for (int i = 1; i <= absExponent; i++) {
		result = result * base;
	}
	if (exponent < 0) {
		result = 1.0 / result;
	}
	return result;
}

int main()
{

	return 0;
}