#include "../TreeNode.h"
#include <iostream>
#include <stack>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * 1) For each node in the tree, calculate the depth of its left and right subtrees.
 * If the height difference is more than one, return false. Once we've looped through the
 * entire tree, return true.
 *
 * Time complexity: O(n^2) [where n is the number of nodes in the binary tree]
 * Space complexity: O(n) [where n is the number of nodes in the binary tree]
 *
 * 2) Based on DFS. Instead of calculating the depth, explicitly, for each child node,
 * we return the height of the current node in DFS recursion.
 * When the sub tree of the current node (inclusive) is balanced, the function getDepth() returns a non-negative value as the height.
 * Otherwise, -1 is returned.
 * According to the height of the two children, the parent node could check if the sub tree is balanced, and decides its return value.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

int getHeight(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    return 1 + max(getHeight(root->left), getHeight(root->right));
}

bool isBalanced(TreeNode* root)
{
    if(root==nullptr)
    {
        return true;
    }

    stack<TreeNode*> nodes;

    nodes.push(root);

    while(!nodes.empty())
    {
        TreeNode* current=nodes.top();

        nodes.pop();

        int leftSubtreeHeight=getHeight(current->left);

        int rightSubtreeHeight=getHeight(current->right);

        int result=abs((leftSubtreeHeight - rightSubtreeHeight));

        if(result > 1)
        {
            return false;
        }

        if(current->left!=nullptr)
        {
            nodes.emplace(current->left);
        }

        if(current->right!=nullptr)
        {
            nodes.emplace(current->right);
        }
    }

    return true;
}

int getDepth(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    int left=getDepth(root->left);

    int right=getDepth(root->right);

    if(left==-1 || right==-1 || abs(left - right) > 1)
    {
        return -1;
    }

    return 1 + max(left, right);
}

bool isBalanced(TreeNode* root)
{
    if(root==nullptr)
    {
        return true;
    }

    int depth=getDepth(root);

    return (depth==-1) ? false : true;
}