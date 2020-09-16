#include "pch.h"

#include <string>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
}; 


void Mirror(TreeNode *pRoot) {
	if (pRoot == nullptr)
		return;
	deque<TreeNode *> temp;
	TreeNode *pSwap, *pNode;
	temp.push_back(pRoot);
	while (!temp.size()) {
		pNode = temp.front();
		pSwap = pNode->left;
		pNode->left = pNode->right;
		pNode->right = pNode->left;
		temp.pop_front();
		if (pNode->left != nullptr)
			temp.push_back(pNode->left);
		if (pNode->right != nullptr)
			temp.push_back(pNode->right);
	}
}

int main()
{
	

}