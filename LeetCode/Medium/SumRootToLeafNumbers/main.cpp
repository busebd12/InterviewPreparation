#include "../TreeNode.h"
#include <cmath>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

/*
 * Solutions:
 *
 * 1. Recursive pre-order traversal, building each root-to-leaf path as we go.
 * When we reach the end of a path, we sum up the path and add that sum to our
 * overall sum, result.
 *
 * Time complexity: O(n^2) [where n is the number of nodes in the binary tree]
 *
 * Space complexity average case: O(h + ph) [where h is the height of the binary tree and p is the number of root-to-leaf paths]
 * Space complexity worse case: O(n + pn) [where n is the height of the binary tree and p is the number of root-to-lear paths]
 *
 * 2. Iterative version of the first solution.
 *
 * Time complexity: O(n^2) [where n is the number of nodes in the binary tree]
 *
 * Space complexity average case: O(h + ph) [where h is the height of the binary tree and p is the number of root-to-leaf paths]
 * Space complexity worse case: O(n + pn) [where n is the height of the binary tree and p is the number of root-to-lear paths]
 *
 *
 * 3. Instead of building each path, we just maintain the sum of the path(s) as we traverse the tree. When we reach the end
 * of a root-to-leaf path, we add it to the overall sum, result.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 *
 * Space complexity average case: O(h) [where h is the height of the binary tree]
 * Space complexity worse case: O(n) [where n is the height of the binary tree]
 */

void preOrderTraversal(TreeNode* root, std::vector<int> path, int & result)
{
    if(root==nullptr)
    {
        return;
    }

    path.emplace_back(root->val);

    if(root->right==nullptr && root->left==nullptr)
    {
        int sum=0;

        int power=int(path.size()-1);

        for(auto & number : path)
        {
            int value=number * static_cast<int>(std::pow(10, power));

            sum+=value;

            power--;
        }

        result+=sum;
    }

    preOrderTraversal(root->left, path, result);

    preOrderTraversal(root->right, path, result);
}

int sumNumbers(TreeNode* root)
{
    int result=0;

    if(root==nullptr)
    {
        return result;
    }

    std::vector<int> path;

    preOrderTraversal(root, path, result);

    return result;
}

int sumNumbers(TreeNode* root)
{
    int result=0;

    if(root==nullptr)
    {
        return result;
    }

    std::stack<std::pair<TreeNode*, std::vector<int>>> stk;

    stk.push(std::make_pair(root, std::vector<int>()));

    while(!stk.empty())
    {
        auto element=stk.top();

        stk.pop();

        element.second.emplace_back(element.first->val);

        if(element.first->left==nullptr && element.first->right==nullptr)
        {
            int sum=0;

            int power=int(element.second.size()-1);

            for(auto & number : element.second)
            {
                int value=number * static_cast<int>(std::pow(10, power));

                sum+=value;

                power--;
            }

            result+=sum;
        }

        if(element.first->right!=nullptr)
        {
            stk.push(std::make_pair(element.first->right, element.second));
        }

        if(element.first->left!=nullptr)
        {
            stk.push(std::make_pair(element.first->left, element.second));
        }
    }

    return result;
}

void preOrderTraversal(TreeNode* root, int sum, int & result)
{
    if(root==nullptr)
    {
        return;
    }

    sum=sum*10 + root->val;

    if(root->right==nullptr && root->left==nullptr)
    {
        result+=sum;
    }

    preOrderTraversal(root->left, sum, result);

    preOrderTraversal(root->right, sum, result);
}

int sumNumbers(TreeNode* root)
{
    int result=0;

    if(root==nullptr)
    {
        return result;
    }

    int sum=0;

    preOrderTraversal(root, sum, result);

    return result;
}

int sumNumbers(TreeNode* root)
{
    int result=0;

    if(root==nullptr)
    {
        return result;
    }

    std::stack<std::pair<TreeNode*, int>> stk;

    stk.push(std::make_pair(root, 0));

    while(!stk.empty())
    {
        auto element=stk.top();

        stk.pop();

        element.second=element.second*10 + element.first->val;

        if(element.first->left==nullptr && element.first->right==nullptr)
        {
            result+=element.second;
        }

        if(element.first->right!=nullptr)
        {
            stk.push(std::make_pair(element.first->right, element.second));
        }

        if(element.first->left!=nullptr)
        {
            stk.push(std::make_pair(element.first->left, element.second));
        }
    }

    return result;
}