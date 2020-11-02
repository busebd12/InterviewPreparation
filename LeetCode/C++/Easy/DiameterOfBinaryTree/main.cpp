#include "../TreeNode.h"
#include <iostream>
using namespace std;

/*
 * Approach: For each node in the tree, the length of the longest path that passes
 * through it is the max of the height of its left subtree and right subtree.
 *
 * Time complexity: O(n)
 * Space complexity: O(n) recursive stack space
 */

int getHeight(TreeNode* root, int & result)
{
    if(root==nullptr)
    {
        return 0;
    }

    int leftSubtreeHeight=getHeight(root->left, result);

    int rightSubtreeHeight=getHeight(root->right, result);

    int totalHeight=leftSubtreeHeight + rightSubtreeHeight;

    if(totalHeight > result)
    {
        result=totalHeight;
    }

    return 1 + max(leftSubtreeHeight, rightSubtreeHeight);
}

int diameterOfBinaryTree(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    if(root->left==nullptr && root->right==nullptr)
    {
        return 0;
    }

    int result=0;

    getHeight(root, result);

    return result;
}