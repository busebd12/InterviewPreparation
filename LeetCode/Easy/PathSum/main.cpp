#include "../TreeNode.h"
#include <iostream>
#include <stack>
using namespace std;

/*
 * Apporoaches, from top-to-bottom:
 *
 * 1) Recursive depth-first search.
 * If we reach a node that is nullptr, return false.
 * If we reach a leaf node and subtracting the root value from the sum would give us zero, return true, path found!
 * Else, subtract the root value from the sum and recurse for the left and right subtrees.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(n) [where n is the number of nodes in the binary tree]
 *
 * 2) Iterative depth-first search.
 * We use two stacks, one to keep track of the sum, and one to keep track of the nodes, as we traverse the tree.
 * Same base case checks as the recursive approach.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(n) [where n is the number of nodes in the binary tree]
 */

bool helper(TreeNode* root, int sum)
{
    if(root==nullptr)
    {
        return false;
    }

    if(root->left==nullptr && root->right==nullptr)
    {
        return (sum-root->val)==0;
    }

    sum-=root->val;

    return helper(root->left, sum) || helper(root->right, sum);
}

bool hasPathSum(TreeNode* root, int sum)
{
    if(root==nullptr)
    {
        return false;
    }

    return helper(root, sum);
}

bool hasPathSum(TreeNode* root, int sum)
{
    if(root==nullptr)
    {
        return false;
    }

    stack<TreeNode*> nodes;

    stack<int> sums;

    nodes.push(root);

    sums.push(sum);

    while(!nodes.empty())
    {
        TreeNode* node=nodes.top();

        nodes.pop();

        int currentSum=sums.top();

        sums.pop();

        int result=currentSum - node->val;

        if(node->left==nullptr && node->right==nullptr)
        {
            if(result==0)
            {
                return true;
            }
        }

        if(node->left!=nullptr)
        {
            nodes.push(node->left);

            sums.push(result);
        }

        if(node->right!=nullptr)
        {
            nodes.push(node->right);

            sums.push(result);
        }
    }

    return false;
}