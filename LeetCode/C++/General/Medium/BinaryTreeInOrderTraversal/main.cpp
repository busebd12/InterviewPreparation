#include "../TreeNode.h"
#include <iostream>
#include <stack>
#include <vector>

/*
 * Solutions:
 *
 * 1. Recursive.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 *
 * 2. Iterative, using a stack to simulate the recursive stack.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 *
 * 3. Iterative, using a copy of the root node so that we don't change the tree.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

void helper(TreeNode* root, std::vector<int> & traversal)
{
    if(root==nullptr)
    {
        return;
    }

    helper(root->left, traversal);

    traversal.emplace_back(root->val);

    helper(root->right, traversal);
}

std::vector<int> inorderTraversal(TreeNode* root)
{
    std::vector<int> traversal;

    helper(root, traversal);

    return traversal;
}

std::vector<int> inorderTraversal(TreeNode* root)
{
    std::vector<int> result;

    if(root==nullptr)
    {
        return result;
    }

    std::stack<TreeNode*> stk;

    while(!stk.empty() || root!=nullptr)
    {
        while(root!=nullptr)
        {
            stk.push(root);

            root=root->left;
        }

        auto current=stk.top();

        stk.pop();

        result.emplace_back(current->val);

        root=current->right;
    }

    return result;
}

std::vector<int> inorderTraversal(TreeNode* root)
{
    std::vector<int> result;

    if(root==nullptr)
    {
        return result;
    }

    TreeNode* copy=root;

    std::stack<TreeNode*> stk;

    while(!stk.empty() || copy!=nullptr)
    {
        while(copy!=nullptr)
        {
            stk.push(copy);

            copy=copy->left;
        }

        auto current=stk.top();

        stk.pop();

        result.emplace_back(current->val);

        copy=current->right;
    }

    return result;
}