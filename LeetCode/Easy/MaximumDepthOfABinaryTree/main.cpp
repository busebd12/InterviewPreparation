#include "../TreeNode.h"
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * 1) Recursion: The height maximum height of the binary tree is just the height of the root node
 * plus the maximum height between the root node's left and right subtrees.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(1)
 *
 * 2) Iterative, Depth-first traversal: use one stack to keep track of the nodes and another to keep track of depth.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(n) [where n is the number of nodes in the binary tree]
 *
 * 3) Iterative, Breadth-first traversal: Just do a level order traversal and count the levels.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(n) [where n is the number of nodes in the binary tree]
 *
 */

int maxDepth(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int maxDepth(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    stack<TreeNode*> stk;

    stack<int> depth;

    stk.push(root);

    depth.push(1);

    int result=0;

    while(!stk.empty())
    {
        TreeNode* current=stk.top();

        stk.pop();

        int currentDepth=depth.top();

        depth.pop();

        result=max(result, currentDepth);

        if(current->left!=nullptr)
        {
            stk.push(current->left);

            depth.push(currentDepth + 1);
        }

        if(current->right!=nullptr)
        {
            stk.push(current->right);

            depth.push(currentDepth + 1);
        }
    }

    return result;
}

int maxDepth(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    queue<TreeNode*> Q;

    Q.push(root);

    int result=0;

    while(!Q.empty())
    {
        int qSize=int(Q.size());

        while(qSize > 0)
        {
            TreeNode* current=Q.front();

            Q.pop();

            if(current->left!=nullptr)
            {
                Q.emplace(current->left);
            }

            if(current->right!=nullptr)
            {
                Q.emplace(current->right);
            }

            qSize--;
        }

        result++;
    }

    return result;
}