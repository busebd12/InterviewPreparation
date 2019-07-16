#include "../TreeNode.h"
#include <iostream>
#include <queue>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * 1) Recursive:
 * Base cases: both roots are null, right root is null and left root is not null, left root is null and right root is not null
 * Recursive step: check if both root values are the same and recurse for the appropriate left and right subtrees.
 *
 * Time complexity: O(n) [where n is the number of nodes in the tree]
 *
 * Space complexity: O(1)
 *
 *
 * 2) Iterative Breadth-first search
 * Use a queue to hold the nodes of the tree. Bases cases are the same.
 * Only "trick" is that we only add nodes to the queue if both root nodes are not null and have the same value.
 *
 * Time complexity: O(n) [where n is the number of nodes in the tree]
 *
 * Space complexity: O(n) [where n is the number of nodes in the tree]
 */

bool helper(TreeNode* L, TreeNode* R)
{
    if(L==nullptr && R==nullptr)
    {
        return true;
    }

    if(R==nullptr && L!=nullptr)
    {
        return false;
    }

    if(L==nullptr && R!=nullptr)
    {
        return false;
    }

    return L->val==R->val && helper(L->left, R->right) && helper(L->right, R->left);
}

bool isSymmetric(TreeNode* root)
{
    if(root==nullptr)
    {
        return true;
    }

    return helper(root->left, root->right);
}

bool isSymmetric(TreeNode* root)
{
    if(root==nullptr)
    {
        return true;
    }

    queue<TreeNode*> Q;

    Q.emplace(root->left);

    Q.emplace(root->right);

    while(!Q.empty())
    {
        TreeNode* L=Q.front();

        Q.pop();

        TreeNode* R=Q.front();

        Q.pop();

        if(L==nullptr && R==nullptr)
        {
            continue;
        }

        if(L!=nullptr && R==nullptr)
        {
            return false;
        }

        if(L==nullptr && R!=nullptr)
        {
            return false;
        }

        if(L!=nullptr && R!=nullptr)
        {
            if(L->val!=R->val)
            {
                return false;
            }

            Q.emplace(L->left);

            Q.emplace(R->right);

            Q.emplace(L->right);

            Q.emplace(R->left);
        }
    }

    return true;
}