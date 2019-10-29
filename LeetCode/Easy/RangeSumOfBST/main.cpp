#include "../TreeNode.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;


/*
 * Approaches:
 *
 * 1) While doing a level-order traversal of the tree, we add each root value that falls in our desired range to our int rangeSum.
 * Return rangeSum after our traversal finishes.
 *
 * Time complexity: O(n) [where n is the number of nodes in the BST]
 * Space complexity: O(n)
 *
 *
 * 2) Recursive depth-first search. As we traverse through the tree, we handle the following cases:
 *
 * a) Current node is null, return.
 * b) Current root node value falls into our desired range. Add the root node's value to our rangeSum variable and then
 * recurse for the left and right subtrees.
 * c) Root node value too small (root->val < L). Recurse for the right subtree.
 * d) Root value too large (root->val > R). Recurse for the left subtree.
 *
 * After we are done, return our result.
 *
 * Time complexity: O(h) [where h is the height of the BST]
 * Space complexity: O(h) recursive stack space
 *
 *
 * 3) Variation of the second solution but similar logic.
 *
 * Time complexity: O(h) [where h is the height of the BST]
 * Space complexity: O(h) recursive stack space
 *
 *
 * 4) Iterative depth-first search using a stack.
 *
 * Time complexity: O(h) [where h is the height of the BST]
 * Space complexity: O(h)
 */

void levelOrderTraversal(TreeNode* root, int L, int R, int & rangeSum)
{
    queue<TreeNode*> Q;

    Q.push(root);

    while(!Q.empty())
    {
        int qSize=int(Q.size());

        for(int count=0;count<qSize;++count)
        {
            TreeNode* current=Q.front();

            Q.pop();

            if(current->val >= L && current->val <= R)
            {
                rangeSum+=current->val;
            }

            if(current->left!=nullptr)
            {
                Q.emplace(current->left);
            }

            if(current->right!=nullptr)
            {
                Q.emplace(current->right);
            }
        }
    }
}

int rangeSumBST(TreeNode* root, int L, int R)
{
    int rangeSum=0;

    levelOrderTraversal(root, L, R, rangeSum);

    return rangeSum;
}

void dfs(TreeNode* root, int L, int R, int & rangeSum)
{
    if(root==nullptr)
    {
        return;
    }
    else if(root->val >= L && root->val <= R)
    {
        rangeSum+=root->val;

        dfs(root->left, L, R, rangeSum);

        dfs(root->right, L, R, rangeSum);
    }
    else if(root->val < L)
    {
        dfs(root->right, L, R, rangeSum);
    }
    else if(root->val > R)
    {
        dfs(root->left, L, R, rangeSum);
    }
}

int rangeSumBST(TreeNode* root, int L, int R)
{
    int rangeSum=0;

    dfs(root, L, R, rangeSum);

    return rangeSum;
}

int dfs(TreeNode* root, int L, int R)
{
    if(root==nullptr)
    {
        return 0;
    }

    if(root->val < L)
    {
        return dfs(root->right, L, R);
    }

    if(root->val > R)
    {
        return dfs(root->left, L, R);
    }

    return root->val + dfs(root->left, L, R) + dfs(root->right, L, R);
}

int rangeSumBST(TreeNode* root, int L, int R)
{
    return dfs(root, L, R);
}

int rangeSumBST(TreeNode* root, int L, int R)
{
    int rangeSum=0;

    stack<TreeNode*> stk;

    stk.push(root);

    while(!stk.empty())
    {
        TreeNode* current=stk.top();

        stk.pop();

        if(current==nullptr)
        {
            continue;
        }

        if(current->val >= L && current->val <= R)
        {
            rangeSum+=current->val;

            stk.push(current->left);

            stk.push(current->right);
        }
        else if(current->val < L)
        {
            stk.push(current->right);
        }
        else if(current->val > R)
        {
            stk.push(current->left);
        }
    }

    return rangeSum;
}