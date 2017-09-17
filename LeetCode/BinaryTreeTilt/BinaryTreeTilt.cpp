#include <iostream>
#include <cmath>
using namespace std;

int sum(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }
    
    return root->val + sum(root->left) + sum(root->right);
}

int findTilt(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }
    
    int currentTilt=abs(sum(root->left) - sum(root->right));
    
    return currentTilt + findTilt(root->left) + findTilt(root->right);
}