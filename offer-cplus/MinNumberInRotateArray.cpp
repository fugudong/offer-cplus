#include "pch.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int findArrayMin(vector<int> rotateArray, int index1, int index2) {
	int result = rotateArray[index1];
	for (int i = index1 + 1; i <= index2; i++) {
		if (result > rotateArray[i]) {
			result = rotateArray[i];
		}
	}
	return result;
}
int minNumberInRotateArray(vector<int> rotateArray) {
	int index1 = 0;
	int index2 = rotateArray.size() - 1;
	int indexMid = index1;

	while (rotateArray[index1] >= rotateArray[index2]) {
		if ((index2 - index1) == 1) {
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2) / 2;
		if (rotateArray[index1] == rotateArray[index2] && rotateArray[indexMid] == rotateArray[index2]) {
			return findArrayMin(rotateArray, index1, index2);
		}
		if (rotateArray[indexMid] >= rotateArray[index1]) {
			index1 = indexMid;
		}
		if (rotateArray[indexMid] <= rotateArray[index2]) {
			index2 = indexMid;
		}
	}
	return rotateArray[indexMid];
}
int main() {
	vector<int> number = { 3,4,5,0,1,2,3};
	cout << minNumberInRotateArray(number) << endl;
}