#include "pch.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

vector<int> printListFromTailToHead(ListNode* head) {
	ListNode* temp = head;
	int listLength = 0;
	while (temp != nullptr) {
		listLength++;
		temp = temp->next;
	}

	
	vector<int> data(listLength);

	temp = head;
	while (temp != nullptr) {
		data[--listLength] = temp->val;
		temp = temp->next;
	}
	return data;
}