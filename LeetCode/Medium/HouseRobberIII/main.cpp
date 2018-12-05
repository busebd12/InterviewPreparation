#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int rob(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    if(root->right==nullptr && root->left==nullptr)
    {
        return root->val;
    }

    int left=0;

    int right=0;

    int grandchildLeft=0;

    int grandchildRight=0;

    if(root->left!=nullptr)
    {
        left=rob(root->left);

        grandchildLeft=rob(root->left->left) + rob(root->left->right);
    }

    if(root->right!=nullptr)
    {
        right=rob(root->right);

        grandchildRight=rob(root->right->left) + rob(root->right->right);
    }

    int childSum=left + right;

    int grandchildSum=grandchildLeft + grandchildRight + root->val;

    return childSum > grandchildSum ? childSum : grandchildSum;
}