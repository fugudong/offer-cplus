#include "pch.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

string PrintMinNumber(vector<int> numbers) {
	int len = numbers.size();
	if (len == 0) {
		return "";
	}
	sort(numbers.begin(), numbers.end(), compare)£»
		string result = "";
	for (int i = 0; i < len; i++) {
		result += to_string(numbers[i]);
	}

	return result;
}
static bool compare(int a, int b) {
	string str1 = to_string(a) + to_string(b);
	string str2 = to_string(b) + to_string(a);

	return str1 < str2;
}

int main() {

	return 0;
}