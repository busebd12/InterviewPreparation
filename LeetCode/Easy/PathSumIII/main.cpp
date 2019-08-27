#include "../TreeNode.h"
#include <iostream>
using namespace std;

/*
 Approaches:
    1) For each node, visit it recursively twice. The first time, subtract the current node's value from the sum.
    The second time, don't subtract the nodes value from the sum. Recurse for the left and right subtrees.

    Time complexity: O(n) [where n is the number of nodes in the tree]
    Space complexity: O(n) recursive stack space

    2) Check for paths starting from the root, the right subtree, and the left subtree

    Time complexity: O(3n-1) [where n is the number of nodes in the tree]
    Space complexity: O(3n-1) recursive stack space
 */

int helper(TreeNode* root, int sum, bool traverseRoot)
{
    if(root==nullptr)
    {
        return 0;
    }

    int result=0;

    if(root->val==sum)
    {
        result++;
    }

    if(root->left!=nullptr)
    {
        if(traverseRoot)
        {
            result+=helper(root->left, sum, true);
        }

        result+=helper(root->left, sum-root->val, false);
    }

    if(root->right!=nullptr)
    {
        if(traverseRoot)
        {
            result+=helper(root->right, sum, true);
        }

        result+=helper(root->right, sum-root->val, false);
    }

    return result;
}

int pathSum(TreeNode* root, int sum)
{
    bool traverseRoot=true;

    return helper(root, sum, traverseRoot);
}

int dfs(TreeNode* root, int sum)
{
    int count=0;

    if(root==nullptr)
    {
        return count;
    }

    if(root->val==sum)
    {
        ++count;
    }

    count+=dfs(root->left, sum-root->val);

    count+=dfs(root->right, sum-root->val);

    return count;
}

int pathSum(TreeNode* root, int sum)
{
    if(root==nullptr)
    {
        return 0;
    }

    return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}