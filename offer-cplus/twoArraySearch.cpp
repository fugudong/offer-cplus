#include "pch.h"
#include "twoArraySearch.h"
#include <iostream>
#include <vector>
#include <string>
#include "twoArraySearch.h"
using namespace std;

TwoArraySearch::TwoArraySearch()


{
}


TwoArraySearch::~TwoArraySearch()
{
}

bool TwoArraySearch::Find(int target, vector<vector<int> > array) {
	
	int row = array.size(), col = array[0].size();
	int i = 0, j = 0;
	if (col > 0)
		j = col - 1;
	else
		j = 0;
	
	do {
		if (array[i].empty()) {
			i++;
			continue;
		}
		cout << i << j << array[i][j] <<endl;
		if (array[i][j] == target) {
			return true;
		}
		else if (array[i][j] > target ) {
			if (j == 0)
				return false;
			j--;
		}
		else {
			if (i == (row-1))
				return false;
			i++;
		}
	} while (i<row && j>=0);
	return false;
}



int main()
{
	std::cout << "Two Hello World!\n";
	vector<vector<int>> testData = { {1},{2},{4},{6},{7} };
	TwoArraySearch twoArraySearch = TwoArraySearch();

	string a= "AA";
	//a.at(0) = a.at(0) + 1;

	//cout << a.at(0)<< endl;
	//char* str = "Hello World!";
	//replaceSpace(str, 40);
}