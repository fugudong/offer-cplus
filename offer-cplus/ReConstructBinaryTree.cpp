#include "pch.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

 
//Definition for binary tree
  struct TreeNode {
	 int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
  TreeNode*  ConstructBinaryTree(int * startPreOrder, int * endPreOrder,
	  int * startInOrder, int * endInOrder) {
	  int rootValue = startPreOrder[0];
	  TreeNode *root = new TreeNode(1);
	  root->val = rootValue;
	  root->left = nullptr;
	  root->right = nullptr;
	  if (startPreOrder == endPreOrder) {
		  if (startInOrder == endInOrder) {
			  return root;
		  }
		  else {
			  throw exception("Invalid input");
		  }
	  }

	  int *temp = startInOrder;
	  while (temp <= endInOrder && *temp != rootValue) {
		  temp++;
	  }
	  if (temp == endInOrder && *temp != rootValue) {
		  throw exception("Invalid input");
	  }

	  int leftLength = temp - startInOrder;
	  int *leftPreOrderEnd = startPreOrder + leftLength;
	  if (leftLength > 0) {
		  root->left = ConstructBinaryTree(startPreOrder + 1, leftPreOrderEnd,
			  startInOrder, temp - 1);
	  }
	  if (leftLength < endPreOrder - startPreOrder) {
		  root->right = ConstructBinaryTree(leftPreOrderEnd + 1, endPreOrder,
			  temp + 1, endInOrder);
	  }

	  return root;
  }

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	if (pre.size() != vin.size())
		return nullptr;
	if (pre.size() == 0 || vin.size() == 0)
		return nullptr;
	int treeLength = pre.size();
	return ConstructBinaryTree(&pre[0], &pre[treeLength-1], &vin[0], &vin[treeLength-1]);

}



int main()
{
	vector<int>  pre = { 1,2,4,7,3,5,6,8 };
	vector<int> in = { 4,7,2,1,5,3,8,6 };
	reConstructBinaryTree(pre, in);
}