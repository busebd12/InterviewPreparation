#include "../TreeNode.h"
#include <iostream>
#include <stack>

/*
 * Solution: if a binary search tree is valid, then any values to the left of the root node must be smaller than the root node,
 * and any values to the right of the root node must be greater than the root node. Thus, if we do an in-order traversal
 * of the binary search tree, then all nodes must be in increasing order. If any node is smaller than the node that came
 * before it, then we know that the binary search tree is not valid.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary search tree]
 * Space complexity: O(n)
 */

bool isValidBST(TreeNode* root)
{
    if(root==nullptr)
    {
        return true;
    }

    TreeNode* previous=nullptr;

    std::stack<TreeNode*> stk;

    while(!stk.empty() || root!=nullptr)
    {
        while(root!=nullptr)
        {
            stk.push(root);

            root=root->left;
        }

        root=stk.top();

        stk.pop();

        if(previous!=nullptr && root->val <= previous->val)
        {
            return false;
        }

        previous=root;

        root=root->right;
    }

    return true;
}