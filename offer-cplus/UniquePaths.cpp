#include "pch.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;


int uniquePaths(int m, int n) {
	int dp[101][101] = { 0 };
	for (int i = 0; i < m + 1; i++) {
		dp[0][i] = 1;
	}

	for (int i = 0; i < n + 1; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			cout << dp[i][j] << endl;
		}
	}

	return dp[n][m];

}
static bool compare(int a, int b) {
	string str1 = to_string(a) + to_string(b);
	string str2 = to_string(b) + to_string(a);

	return str1 < str2;
}

string PrintMinNumber(vector<int> numbers) {
	int len = numbers.size();
	if (len == 0) {
		return "";
	}
	sort(numbers.begin(), numbers.end(), compare);
	string result = "";
	for (int i = 0; i < len; i++) {
		result += to_string(numbers[i]);
	}

	return result;
}



int main()
{
	cout<<min(1, 2)<<endl;
	//cout<<"Out"<<uniquePaths(51, 9)<<endl;
	return 0;
}