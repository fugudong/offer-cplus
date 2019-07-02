#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int m, limit, temp;
	vector<int> weight;

	std::cin >> m >> limit ;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		weight.push_back(temp);
	}


	sort(&weight[0], &weight[m-1]);

	vector<int> newWeight;
	int p = 0, q = m-1;
	for (int i = 0; i < m; i++) {
		newWeight.push_back(weight[p++]);
		if (p == q) {
			newWeight.push_back(weight[p]);
			break;
		}
		newWeight.push_back(weight[q--]);
		if (p == q) {
			newWeight.push_back(weight[p]);
			break;
		}
	}
	int index = 0, count = 0;
	for (int i = 0; i < m; i = index) {
		if (i == m - 1) {
			count++;
			index = i + 1;
		}
		else {
			if (newWeight[i] + newWeight[i + 1] > limit) {
				count++;
				index = i + 1;
			}
			else {
				count++;
				index = i + 2;
			}
		}
	}

	cout << count;
}