#include "pch.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;


void take_sum(string strln, int* n, vector<int> &outArray)
{
	int i = 0, j = 0, tmp = 0, flag = 0, num = 0;
	int len = strln.size();
	//	cout << len << endl;
	while (i < len)
	{
		while (i < len&&strln[i] >= '0'&&strln[i] <= '9')
		{
			tmp = tmp * 10 + strln[i] - '0';
			flag = 1;
			i++;
		}
		if (flag)
		{
			outArray.push_back(tmp);
			tmp = 0;
			j++;
		}
		i++;
		flag = 0;
	}
	*n = j;
}


string isBST(vector<int> tree) {
	string result = "True";

	for (int i = 0; (2 * i + 2) < tree.size(); i++) {
		if ((tree[2 * i + 1] > tree[i]) || (tree[i] > tree[2 * i + 2])) {
			result = "False";
		}
	}

	return result;
}

int main()
{
	int n;
	string data;
	vector<int> tree;

	cin >> data;
	
	take_sum(data, &n, tree);
	cout << isBST(tree) << endl;

}