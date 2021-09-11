#include "../TreeNode.h"
#include <iostream>
using namespace std;

/*
 * Approach: For each node in the Binary Search Tree, we check the following:
 * 1) if the current node is null, return
 *
 * 2) if the root value is less than the left boundary, then if the right subtree is not null, set the root
 * value to the right subtree and then recurse for the root, again. If the right subtree is null, then just
 * set the root to be null.
 *
 * 3) If the root value is larger than the right boundary, then if the left subtree is not null, set the root
 * to be its left-subtree and recurse for the root value. If the root's left subtree is null, then just set
 * root to nullptr
 *
 * 4) If the root value falls within our desired boundaries, then just recurse for the left and right subtrees.
 *
 * Time complexity: O(n)
 * Space complexity: O(n) recursive stack space
 */

void helper(TreeNode* & root, int L, int R)
{
    if(root==nullptr)
    {
        return;
    }

    if(root->val < L)
    {
        if(root->right!=nullptr)
        {
            root=root->right;

            helper(root, L, R);
        }
        else
        {
            root=nullptr;
        }
    }
    else if(root->val > R)
    {
        if(root->left!=nullptr)
        {
            root=root->left;

            helper(root, L, R);
        }
        else
        {
            root=nullptr;
        }
    }
    else
    {
        helper(root->left, L, R);

        helper(root->right, L, R);
    }
}

TreeNode* trimBST(TreeNode* root, int L, int R)
{
    helper(root, L, R);

    return root;
}