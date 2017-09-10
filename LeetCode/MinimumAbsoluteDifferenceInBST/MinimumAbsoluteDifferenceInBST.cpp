#include <iostream>
#include <limits>
using namespace std;

void inOrderTraversal(TreeNode* root, int & value, int & minDifference)
{
    if(root->left!=NULL)
    {
        inOrderTraversal(root->left, value, minDifference);
    }
        
    if(value >= 0)
    {
        minDifference=min(minDifference, root->val - value);
    }
        
    value=root->val;
    
    if(root->right!=NULL)
    {
        inOrderTraversal(root->right, value, minDifference);
    }
}

int getMinimumDifference(TreeNode* root)
{
    auto minDifference=numeric_limits<int>::max();
    
    int value=-1;

    inOrderTraversal(root, value, minDifference);

    return minDifference;
}