#include "../TreeNode.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>

/*
 * Solutions:
 *
 * 1. Breadth-first search, level-order traversal.
 *
 * Time complexity: O(n) [where n is the number of nodes in the Binary Tree]
 * Space complexity: O(n)
 *
 * 2. Depth-first search, recursive.
 *
 * Time complexity: O(n) [where n is the number of nodes in the Binary Tree]
 * Space complexity: O(h) [where h is the height of the Binary Tree]
 *
 * 3. Depth-first search, iterative.
 *
 * Time complexity: O(n) [where n is the number of nodes in the Binary Tree]
 * Space complexity: O(h) [where h is the height of the Binary Tree]
 */

std::vector<int> rightSideView(TreeNode* root)
{
    std::vector<int> result;

    if(root==nullptr)
    {
        return result;
    }

    std::queue<TreeNode*> Q;

    Q.emplace(root);

    while(!Q.empty())
    {
        auto qSize=Q.size();

        for(auto count=0;count<qSize;++count)
        {
            auto node=Q.front();

            Q.pop();

            if(count==qSize-1)
            {
                result.emplace_back(node->val);
            }

            if(node->left!=nullptr)
            {
                Q.emplace(node->left);
            }

            if(node->right!=nullptr)
            {
                Q.emplace(node->right);
            }
        }
    }

    return result;
}

void dfs(TreeNode* root, std::vector<int> & path, std::size_t level)
{
    if(root==nullptr)
    {
        return;
    }

    if(level==path.size())
    {
        path.emplace_back(root->val);
    }

    dfs(root->right, path, level+1);

    dfs(root->left, path, level+1);
}

std::vector<int> rightSideView(TreeNode* root)
{
    std::vector<int> result;

    if(root==nullptr)
    {
        return result;
    }

    std::size_t level=0;

    dfs(root, result, level);

    return result;
}

std::vector<int> rightSideView(TreeNode* root)
{
    std::vector<int> result;

    if(root==nullptr)
    {
        return result;
    }

    std::size_t level=0;

    std::stack<std::pair<TreeNode*, std::size_t>> stk;

    stk.emplace(std::make_pair(root, level));

    while(!stk.empty())
    {
        auto current=stk.top();

        stk.pop();

        if(current.second==result.size())
        {
            result.emplace_back(current.first->val);
        }

        if(current.first->left!=nullptr)
        {
            stk.emplace(std::make_pair(current.first->left, current.second+1));
        }

        if(current.first->right!=nullptr)
        {
            stk.emplace(std::make_pair(current.first->right, current.second+1));
        }
    }

    return result;
}