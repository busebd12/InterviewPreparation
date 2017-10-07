#include <iostream>
#include <set>
using namespace std;

int findSecondMinimumValue(TreeNode* root)
{
    if(root==nullptr)
    {
        return -1;
    }

    if(root->left==nullptr && root->right==nullptr)
    {
        return -1;
    }

    int left=root->left->val;

    int right=root->right->val;

    if(root->left->val==root->val)
    {
        left=findSecondMinimumValue(root->left);
    }

    if(root->left->val==root->val)
    {
        right=findSecondMinimumValue(root->right);
    }

    if(left!=-1 && right!=-1)
    {
        return min(left, right);
    }
    else if(left!=-1)
    {
        return left;
    }
    else
    {
        return right;
    }
}

void inOrderTraversal(TreeNode* root, set<int> & cache)
{
    if(root==nullptr)
    {
        return;
    }
    
    inOrderTraversal(root->left, cache);
    
    cache.insert(root->val);
    
    inOrderTraversal(root->right, cache);
}

int findSecondMinimumValue(TreeNode* root)
{
    if(root==nullptr)
    {
        return -1;
    }
    
    set<int> cache;
    
    inOrderTraversal(root, cache);
    
    int count=1;
    
    int firstMinimum=-1;
    
    int secondMinimum=-1;
    
    for(const auto & element : cache)
    {
        if(count > 2)
        {
            break;
        }
        
        if(count==1)
        {
            firstMinimum=element;
        }
        else if(count==2)
        {
            secondMinimum=element;
        }
        
        ++count;
    }
    
    return (firstMinimum==secondMinimum) ? -1 : secondMinimum;
}