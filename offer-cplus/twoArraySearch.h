#pragma once
#include "pch.h"
#include <vector>
#include <iostream>
//#include <map>
#include <unordered_map>
using namespace std;

class TwoArraySearch
{
public:
	TwoArraySearch();
	~TwoArraySearch();
	bool Find(int target, vector<vector<int> > array);
};

