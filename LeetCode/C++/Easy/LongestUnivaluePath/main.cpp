#include "../TreeNode.h"
#include <iostream>
#include <numeric>
#include <limits>
using namespace std;

/*
 * Approach:
 *
 * The longest univalue path of a tree is longest univalue path among all of its nodes.
 * The longest univalue path of a single node is the sum of the longest univalue path of each of its children
 * nodes plus one. Then, for each node, the the longest univalue Path can be calculated by combining the longest
 * univalue path of its 2 children. We can use a variable, longestPath, to hold the max value and compare with each intermediate result.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(n) recursive stack space
 */

int dfs(TreeNode* root, int & longestPath)
{
    if(root==nullptr)
    {
        return 0;
    }

    int left=dfs(root->left, longestPath);

    int right=dfs(root->right, longestPath);

    int leftPath=0;

    int rightPath=0;

    if(root->left!=nullptr && root->left->val==root->val)
    {
        leftPath=left + 1;
    }

    if(root->right!=nullptr && root->right->val==root->val)
    {
        rightPath=right + 1;
    }

    longestPath=max(longestPath, leftPath + rightPath);

    return max(leftPath, rightPath);
}

int longestUnivaluePath(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    int longestPath=numeric_limits<int>::min();

    dfs(root, longestPath);

    return longestPath;
}