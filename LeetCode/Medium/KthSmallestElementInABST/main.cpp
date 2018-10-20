#include <iostream>
#include <vector>
using namespace std;


struct TreeNode
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

void inOrderTraversal(TreeNode* root, vector<int> & traversal)
{
    if(root==nullptr)
    {
        return;
    }

    inOrderTraversal(root->left, traversal);

    traversal.emplace_back(root->val);

    inOrderTraversal(root->right, traversal);
}

int kthSmallest(TreeNode* root, int k)
{
    if(root==nullptr)
    {
        return 0;
    }

    if(root!=nullptr && root->right==nullptr && root->left==nullptr)
    {
        return root->val;
    }

    vector<int> traversal;

    inOrderTraversal(root, traversal);

    if(k > traversal.size())
    {
        return 0;
    }

    return traversal[k-1];
}