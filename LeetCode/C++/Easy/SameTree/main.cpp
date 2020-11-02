#include "../TreeNode.h"
#include <iostream>
using namespace std;

/*
 * Approach:
 * Recursively iterate through both trees.
 * Base cases: if both nodes are null, return true. if one node is not null and the other one is, return false. If both node values are not equal, return false.
 * Return both node values are equal and that both left and right subtrees of both trees are equal.
 *
 * Time complexity: O(m+n) [where m and n are the sizes of the two trees]
 *
 * Space complexity: O(1)
 */

bool helper(TreeNode* p, TreeNode* q)
{
    if((!p && !q))
    {
        return true;
    }

    if((p && !q) || (!p && q))
    {
        return false;
    }

    if(p->val!=q->val)
    {
        return false;
    }

    return p->val==q->val && (helper(p->left, q->left) && helper(p->right, q->right));
}

bool isSameTree(TreeNode* p, TreeNode* q)
{
    return helper(p, q);
}