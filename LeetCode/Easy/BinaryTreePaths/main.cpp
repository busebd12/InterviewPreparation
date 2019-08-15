#include "../TreeNode.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Depth-first search, recursive
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(n)
 *
 * 2) Depth-first search, iterative, using a stack
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

void dfs(TreeNode* root, vector<string> & paths, string path)
{
    if(root==nullptr)
    {
        return;
    }
    else if(root->left==nullptr && root->right==nullptr)
    {
        path+=to_string(root->val);

        paths.push_back(path);
    }
    else
    {
        path+=to_string(root->val);

        path+="->";

        dfs(root->left, paths, path);

        dfs(root->right, paths, path);
    }
}

vector<string> binaryTreePaths(TreeNode* root)
{
    vector<string> paths;

    if(root==nullptr)
    {
        return paths;
    }

    if(root->left==nullptr && root->right==nullptr)
    {
        paths.push_back(to_string(root->val));

        return paths;
    }

    string path="";

    dfs(root, paths, path);

    return paths;
}

vector<string> binaryTreePaths(TreeNode* root)
{
    vector<string> paths;

    if(root==nullptr)
    {
        return paths;
    }

    if(root->left==nullptr && root->right==nullptr)
    {
        paths.push_back(to_string(root->val));

        return paths;
    }

    stack<pair<TreeNode*, string>> stk;

    string path{};

    stk.push(make_pair(root, path));

    while(!stk.empty())
    {
        pair<TreeNode*, string> current=stk.top();

        stk.pop();

        current.second+=to_string(current.first->val);

        current.second+="->";

        if(current.first->right==nullptr && current.first->left==nullptr)
        {
            current.second.pop_back();

            current.second.pop_back();

            paths.push_back(current.second);
        }

        if(current.first->right!=nullptr)
        {
            stk.push(make_pair(current.first->right, current.second));
        }

        if(current.first->left!=nullptr)
        {
            stk.push(make_pair(current.first->left, current.second));
        }
    }

    return paths;
}