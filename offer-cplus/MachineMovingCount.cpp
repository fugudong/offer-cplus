#include "pch.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int digitSum(int num) {
	int sum = num%10;
	while (num / 10) {
		num = num / 10;
		sum += num % 10;
	}
	return sum;
}

bool check(int threshold, int rol, int rows, int col, int cols, bool *visited)
{
	if(rol >= 0 && col >= 0 && col<cols&&rol<rows&&(digitSum(rol)+digitSum(col)<=threshold)&& !visited[rol*cols + col]){
		return true;
	}
	return false;
}


int movingCountCore(int threshold, int rol, int rows, int col, int cols, bool *visited) {
	int count = 0;
	if (check(threshold, rol, rows, col, cols, visited)) {
		visited[rol*cols + col] = true;
		count += 1 + movingCountCore(threshold, rol + 1, rows, col, cols, visited) +//об
			movingCountCore(threshold, rol - 1, rows, col, cols, visited) +//ио
			movingCountCore(threshold, rol, rows, col + 1, cols, visited) +//ср
			movingCountCore(threshold, rol, rows, col - 1, cols, visited); //вС
	}
	return count;
}

int movingCount(int threshold, int rows, int cols)
{
	if (threshold <0 || rows < 1 || cols < 1)
		return 0;
	bool *visited = new bool[rows*cols];
	memset(visited, 0, rows*cols);
	
	int count = 0;
	count = movingCountCore(threshold, 0, rows, 0, cols, visited);
				
	delete []visited;
	return count;
}

int main() {
	cout << movingCount(5, 10, 10) << endl;
}