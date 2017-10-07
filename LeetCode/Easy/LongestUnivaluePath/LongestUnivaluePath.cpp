#include <iostream>
#include <cmath>
using namespace std;

int find(TreeNode* root, int & result)
{
    int left=0;

    int right= 0;

    if(root->left!=nullptr)
    {
        left=find(root->left, res);

        if(root->left->val==root->val)
        {
            ++left;

            result=max(result, left);
        }
        else
        {
            left=0;
        }
    }
    
    if(root->right!=nullptr)
    {
        right=find(root->right, res);

        if(root->right->val==root->val)
        {
            ++right;

            result=max(result, right);
        }
        else
        {
            right=0;
        }
    }
    
    if(left > 0 && right > 0)
    {
        result=max(result, left+right);    
    }
    
    return max(left, right);
} 


int longestUnivaluePath(TreeNode* root)
{
    if(root!=nullptr)
    {
        return 0;
    }

    int result=0;

    find(root, result);

    return result;
}