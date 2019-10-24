#include "../TreeNode.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Recursive depth-first (pre-order) traversal. If the current node is a leaf node, add its value to the leafNodeValues
 * vector and then recurse for the left and right subtrees. If the root node is nullptr, just return.
 *
 * Time complexity: O(2n) [where n is the number of nodes in the each Binary Tree]
 * Space complexity: O(2n) recursive stack space used and O(2L) [where L is the number of leaf node values in each Binary Tree]
 *
 * 2) Just the iterative version of depth-first (pre-order) traversal, using stacks to simulate the recursion.
 *
 * Time complexity: O(n) [where n is the number of nodes in the Binary Tree]
 * Space complexity: O(2n + 2L) [where n is the number of nodes in each Binary Tree and L number of leaf node values.
 */

void dfs(TreeNode* root, vector<int> & leafNodeValues)
{
    if(root==nullptr)
    {
        return;
    }

    if(root->left==nullptr && root->right==nullptr)
    {
        leafNodeValues.emplace_back(root->val);
    }

    dfs(root->left, leafNodeValues);

    dfs(root->right, leafNodeValues);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2)
{
    if(root1==nullptr || root2==nullptr)
    {
        return false;
    }

    vector<int> root1LeafNodeValues;

    dfs(root1, root1LeafNodeValues);

    vector<int> root2LeafNodeValues;

    dfs(root2, root2LeafNodeValues);

    return root1LeafNodeValues==root2LeafNodeValues;
}

void dfs(TreeNode* root, vector<int> & leafNodeValues)
{
    stack<TreeNode*> stk;

    stk.push(root);

    while(!stk.empty())
    {
        TreeNode* current=stk.top();

        stk.pop();

        if(current->left==nullptr && current->right==nullptr)
        {
            leafNodeValues.emplace_back(current->val);
        }

        if(current->right!=nullptr)
        {
            stk.push(current->right);
        }

        if(current->left!=nullptr)
        {
            stk.push(current->left);
        }
    }
}

bool leafSimilar(TreeNode* root1, TreeNode* root2)
{
    if(root1==nullptr || root2==nullptr)
    {
        return false;
    }

    vector<int> root1LeafNodeValues;

    vector<int> root2LeafNodeValues;

    dfs(root1, root1LeafNodeValues);

    dfs(root2, root2LeafNodeValues);

    return root1LeafNodeValues==root2LeafNodeValues;
}