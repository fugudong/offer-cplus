#include "pch.h"
#include <iostream>
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


ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == nullptr) {
		return nullptr;
	}
	if (pHead->next == nullptr) {
		return pHead;
	}
	ListNode *pNode = pHead, *pToBeDel;
	ListNode *pPreNode = pNode;
	while (pNode != nullptr) {
		ListNode *pNext = pNode->next;
		if (pNext != nullptr&&pNode->val == pNext->val) {
			pToBeDel = pNode;
			int val = pToBeDel->val;
			while (pToBeDel != nullptr && pToBeDel->val == val) {
				pNext = pToBeDel->next;
				if (pToBeDel == pHead) {
					pPreNode == nullptr;
					pHead = pToBeDel->next;

				}
				delete pToBeDel;
				pToBeDel = pNext;
			}
			if (pToBeDel == nullptr) {
				if (pPreNode != nullptr) {
					pPreNode->next = nullptr;
				}
				else
					return nullptr;
			}
			else {
				if (pPreNode == nullptr) {

					pNode = pHead;
				}
				else {
					pPreNode->next = pToBeDel;
					pNode = pToBeDel;
				}
			}

		}
		else {

			pPreNode = pNode;
			pNode = pNext;

		}
	}
	return pHead;
}

int main() {
	vector<int> data = { 1,1,2,3,3,4,5,5 };

	ListNode *pHead = new ListNode(1), *pNode, *preNode;
	pHead->val = data[0];
	preNode = pHead;
	for (int i = 1; i < (int)data.size(); i++) {
		pNode = new ListNode(1);
		pNode->val = data[i];
		preNode->next = pNode;
		preNode = pNode;
	}
	preNode->next = nullptr;
	pNode = pHead;
	while (pNode != nullptr) {
		cout << pNode->val << endl;
		pNode = pNode->next;
	}
	cout << "after delete" << endl;
	pNode = deleteDuplication(pHead);
	
	while (pNode != nullptr) {
		cout << pNode->val << endl;
		pNode = pNode->next;
	}
	return 0;
}