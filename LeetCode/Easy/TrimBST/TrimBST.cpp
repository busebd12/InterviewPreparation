#include <iostream>
using namespace std;

TreeNode* trimBST(TreeNode* root, int L, int R)
{
    if(root==nullptr)
    {
        return nullptr;
    }
    
    root->left=trimBST(root->left, L, R);
    
    root->right=trimBST(root->right, L, R);
    
    if(root->val >= L && root->val <= R)
    {
        return root;
    }
    
    if(root->val < L)
    {
        return root->right;
    }
    
    if(root->val > R)
    {
        return root->left;
    }
}