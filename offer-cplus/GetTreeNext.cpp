#include "pch.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	TreeLinkNode* temp, *temp2;
	if (pNode == nullptr) {
		return nullptr;
	}
	if (pNode->right != nullptr) {
		temp = pNode->right;
		while (temp->left != nullptr) {
			temp = temp->left;
		}
		return temp;
	}
	else {
		if (pNode->next != nullptr && pNode->next->left == pNode) {
			return pNode->next;
		}
		else {
			temp = pNode;
			while (temp->next != nullptr) {
				temp2 = temp;
				temp = temp->next;
			}
			if (temp->left == temp2) {
				return temp;
			}
			else {
				return nullptr;
			}
		}
	}
}