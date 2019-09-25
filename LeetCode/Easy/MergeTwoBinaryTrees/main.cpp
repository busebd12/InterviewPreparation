#include "../TreeNode.h"
#include <iostream>
#include <stack>
#include <utility>
using namespace std;

/*
 * Approaches:
 *
 * 1) Recursion. If t1 is null, return t2. If t2 is null, return t1. If neither are null, add the root
 * values together and this is the new, merged root value. Recurse for the left and right subtrees.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(h) [where h is the height of the binary tree]
 *
 *
 * 2) Iterative version of the first approach.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(h) [where h is the height of the binary tree]
 */

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
{
    TreeNode* merged=nullptr;

    if(t1==nullptr && t2==nullptr)
    {
        return merged;
    }

    if(t1==nullptr)
    {
        return t2;
    }

    if(t2==nullptr)
    {
        return t1;
    }

    int sum=t1->val + t2->val;

    merged=new TreeNode(sum);

    merged->left=mergeTrees(t1->left, t2->left);

    merged->right=mergeTrees(t1->right, t2->right);

    return merged;
}

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
{
    if(t1==nullptr && t2==nullptr)
    {
        return nullptr;
    }

    if(t1==nullptr)
    {
        return t2;
    }

    if(t2==nullptr)
    {
        return t1;
    }

    stack<pair<TreeNode*, TreeNode*>> stk;

    stk.push(make_pair(t1, t2));

    while(!stk.empty())
    {
        pair<TreeNode*, TreeNode*> current=stk.top();

        stk.pop();

        if(current.first==nullptr || current.second==nullptr)
        {
            continue;
        }

        current.first->val+=current.second->val;

        if(current.first->left==nullptr)
        {
            current.first->left=current.second->left;
        }
        else
        {
            stk.push(make_pair(current.first->left, current.second->left));
        }

        if(current.first->right==nullptr)
        {
            current.first->right=current.second->right;
        }
        else
        {
            stk.push(make_pair(current.first->right, current.second->right));
        }
    }

    return t1;
}