#include "pch.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;


int merge(int *array1, int len1, int *array2, int len2, int *array3) {
	int length1 = 1, length2 = 1;

	while (length1 <= len1 && length2 <= len2) {
		if (*array1 > *array2) {
			*array3 = *array2;
			array2++;
			length2++;
		}
		else {
			*array3 = *array1;
			array1++;
			length1++;
		}
		array3++;
	}
	if (length1 > len1) {
		while (length2 <= len2) {
			*array3 = *array2;
			array2++;
			length2++;
			array3++;
		}
	}
	if (length2 > len2) {
		while (length1 <= len1) {
			*array3 = *array1;
			array1++;
			length1++;
			array3++;
		}
	}
	return 1;
}
int main() {

	int a[] = { 3, 7, 9,12 ,15, 18};
	int b[] = {1, 3, 4};
	int c[20] = {0};
	merge(a, 6, b, 3, c);
	for (int i = 0; i < 20; i++) {
		cout << c[i]<<endl;
	}
}