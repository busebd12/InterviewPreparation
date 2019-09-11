#include "../TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

/*
 * Approaches:
 *
 * 1) Using pre-order traversal, populate a vector with all the tree node values.
 * Then, find the minimum absolute difference.
 *
 * Time complexity: O(n-squared) [where n is the number of nodes in the Binary Search Tree]
 * Space complexity: O(n)
 *
 * 2) Recursive. Thanks to a Binary Tree's ordered property, an in-order traversal of the tree will yield
 * a sorted sequence of the nodes and we just have to keep track of the minimum absolute difference
 * as we go along.
 *
 * Time complexity: O(n) [where n is the number of nodes in the Binary Search Tree]
 * Space complexity: O(h) [where h is the height of the Binary Search Tree]
 *
 * 3) Iterative version of the second solution.
 *
 * Time complexity: O(n) [where n is the number of nodes in the Binary Search Tree]
 * Space complexity: O(h) [where h is the height of the Binary Search Tree]
 */

void dfs(TreeNode* root, vector<int> & values)
{
    if(root==nullptr)
    {
        return;
    }

    values.emplace_back(root->val);

    dfs(root->left, values);

    dfs(root->right, values);
}

int getMinimumDifference(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    int result=numeric_limits<int>::max();

    vector<int> values;

    dfs(root, values);

    for(int i=0;i<values.size();++i)
    {
        for(int j=0;j<values.size();++j)
        {
            if(j!=i)
            {
                int difference=abs(values[i] - values[j]);

                if(difference < result)
                {
                    result=difference;
                }
            }
        }
    }

    return result;
}

void inOrderTraversal(TreeNode* root, int & previous, int & result)
{
    if(root==nullptr)
    {
        return;
    }

    inOrderTraversal(root->left, previous, result);

    if(previous >= 0)
    {
        int difference=abs(root->val - previous);

        result=min(result, difference);
    }

    previous=root->val;

    inOrderTraversal(root->right, previous, result);
}

int getMinimumDifference(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    int result=numeric_limits<int>::max();

    int previous=-1;

    inOrderTraversal(root, previous, result);

    return result;
}

int getMinimumDifference(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    int result=numeric_limits<int>::max();

    int previous=-1;

    stack<TreeNode*> stk;

    while(!stk.empty() || root!=nullptr)
    {
        while(root!=nullptr)
        {
            stk.push(root);

            root=root->left;
        }

        TreeNode* current=stk.top();

        stk.pop();

        if(previous >= 0)
        {
            int difference=abs(current->val - previous);

            result=min(result, difference);
        }

        previous=current->val;

        root=current->right;
    }

    return result;
}