#include "../TreeNode.h"
#include <iostream>
#include <stack>
using namespace std;

/*
 * Approaches:
 *
 * 1) Recursive. We check if the left subtree of the current node is not null.
 * If it isn't, then we have two cases. First, if the current node is a leaf node, then we just add
 * its value to the sum. Else, we recurse for the left-subtree. If the left-subtree is null, then
 * we recurse for the right sub-tree.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(n) recursive stack space
 *
 * 2) Recursive. Base cases are: if the root is null, return 0. If the root node is a left leave node, then
 * we just return its value. Else, we recurse for the left and right subtrees.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(n) recursive stack space
 *
 * 3) Iterative version of the first approach using a stack.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(n)
 */

int helper(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    int answer=0;

    if(root->left!=nullptr)
    {
        if(root->left->left==nullptr && root->left->right==nullptr)
        {
            answer+=root->left->val;
        }
        else
        {
            answer+=helper(root->left);
        }
    }

    answer+=helper(root->right);

    return answer;
}

int sumOfLeftLeaves(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    return helper(root);
}

int helper(TreeNode* root, bool isLeft)
{
    if(root==nullptr)
    {
        return 0;
    }

    if(isLeft && root->left==nullptr && root->right==nullptr)
    {
        return root->val;
    }

    return helper(root->left, true) + helper(root->right, false);
}

int sumOfLeftLeaves(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    return helper(root, false);
}

int sumOfLeftLeaves(TreeNode* root)
{
    int sum=0;

    if(root==nullptr)
    {
        return sum;
    }

    stack<TreeNode*> stk;

    stk.push(root);

    while(!stk.empty())
    {
        TreeNode* current=stk.top();

        stk.pop();

        if(current->left!=nullptr)
        {
            if(current->left->left==nullptr && current->left->right==nullptr)
            {
                sum+=current->left->val;
            }
            else
            {
                stk.push(current->left);
            }
        }

        if(current->right!=nullptr)
        {
            if(current->right->left!=nullptr || current->right->right!=nullptr)
            {
                stk.push(current->right);
            }
        }
    }

    return sum;
}