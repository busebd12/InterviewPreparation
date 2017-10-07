#include <iostream>
using namespace std;

bool isSame(TreeNode* s, TreeNode* t)
{
    if(s==nullptr && t==nullptr)
    {
        return true;
    }
    
    if(s==nullptr || t==nullptr)
    {
        return false;
    }
    
    return (s->val==t->val) && isSame(s->left, t->left) && isSame(s->right, t->right);
}

bool isSubtree(TreeNode* s, TreeNode* t)
{
    if(s==nullptr)
    {
        return false;
    }
    
    if(isSame(s, t))
    {
        return true;
    }
    
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}