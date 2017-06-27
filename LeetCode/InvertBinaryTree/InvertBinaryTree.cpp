#include <iostream>
using namespace std;

TreeNode* invertTree(TreeNode* root)
{
	if(root)
	{
		invertTree(root->right);

		invertTree(root->left);

		swap(root->right, root->left);
	}

	return root;
}