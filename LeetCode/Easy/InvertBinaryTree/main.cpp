#include "../TreeNode.h"
#include <iostream>
#include <stack>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * 1) Recursion. If the root is not nullptr, swap the left sub-tree and right sub-trees.
 * Then, recurse for the left sub-tree and right sub-tree.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(n) [recursive stack space used]
 *
 * 2) Iterative, using stack in-lieu of the recursion stack.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(n) [where n is the number of nodes in the binary tree]
 *
 *
 */

TreeNode* invertTree(TreeNode* root)
{
    if(root!=nullptr)
    {
        TreeNode* temp=root->right;

        root->right=root->left;

        root->left=temp;

        invertTree(root->right);

        invertTree(root->left);
    }

    return root;
}

TreeNode* invertTree(TreeNode* root)
{
    if(root==nullptr)
    {
        return root;
    }

    stack<TreeNode*> stk;

    stk.push(root);

    while(!stk.empty())
    {
        TreeNode* current=stk.top();

        stk.pop();

        TreeNode* left=current->left;

        current->left=current->right;

        current->right=left;

        if(current->left!=nullptr)
        {
            stk.push(current->left);
        }

        if(current->right!=nullptr)
        {
            stk.push(current->right);
        }
    }

    return root;
}