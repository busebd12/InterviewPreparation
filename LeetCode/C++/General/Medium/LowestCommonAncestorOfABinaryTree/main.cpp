#include "../TreeNode.h"
#include <iostream>
#include <stack>

/*
 * Solution: we store the path from the root node to the p and q node in two stacks.
 * Then, we iterate through both stacks to find the deepest point where the paths intersect.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(h) [where h is the height of the tree]
 */

bool dfs(TreeNode* root, std::stack<TreeNode*> & stk, TreeNode* node)
{
    if(root==nullptr)
    {
        return false;
    }

    if(root->val==node->val)
    {
        stk.push(root);

        return true;
    }

    if(dfs(root->left, stk, node) || dfs(root->right, stk, node))
    {
        stk.push(root);

        return true;
    }

    return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root==nullptr)
    {
        return root;
    }

    TreeNode* result=nullptr;

    std::stack<TreeNode*> pStack;

    std::stack<TreeNode*> qStack;

    if(dfs(root, pStack, p) && dfs(root, qStack, q))
    {
        while(!pStack.empty() && !qStack.empty())
        {
            auto pNode=pStack.top();

            auto qNode=qStack.top();

            pStack.pop();

            qStack.pop();

            if(pNode->val==qNode->val)
            {
                result=pNode;
            }
        }
    }

    return result;
}