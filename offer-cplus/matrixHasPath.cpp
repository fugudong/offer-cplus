#include "pch.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool hasPathCore(const char* matrix, int rol, int rows, int col, int cols, int &pathLength, const char* str, bool *visited) {
	if (str[pathLength] == '\0') {
		return true;
	}
	bool haspath = false;
	if (rol < rows&&col < cols&&matrix[rol*cols + col] == str[pathLength] && !visited[rol*cols + col]) {
		++pathLength;
		visited[rol*cols + col] = true;
		haspath = hasPathCore(matrix, rol + 1, rows, col, cols, pathLength, str, visited) ||//об
			hasPathCore(matrix, rol - 1, rows, col, cols, pathLength, str, visited) ||//ио
			hasPathCore(matrix, rol, rows, col + 1, cols, pathLength, str, visited) ||//ср
			hasPathCore(matrix, rol, rows, col - 1, cols, pathLength, str, visited); //вС
		if (!haspath) {
			visited[rol*cols + col] = false;
			pathLength--;
		}
	}
	return haspath;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
		return false;
	bool *visited = new bool[rows*cols];
	memset(visited, 0, rows*cols);
	int rol = 0, col = 0;
	int pathLength = 0;
	for (rol = 0; rol < rows; rol++) {
		for (col = 0; col < cols; col++) {
			if (hasPathCore(matrix, rol, rows, col, cols, pathLength, str, visited))
				return true;
		}
	}

	delete []visited;
	return false;
}