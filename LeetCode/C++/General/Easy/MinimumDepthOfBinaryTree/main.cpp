#include "../TreeNode.h"
#include <iostream>
#include <queue>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * 1) Depth first traversal. Calculate the min depth for the left and right subtrees recursively.
 * If one of the subtrees has a depth of 0, return one plus the depth of the other subtree.
 * Else, return one plus the minimum of the depths of the two subtrees.
 *
 * Time complexity: O(n) [where n is the number of noes in the binary tree]
 * Space complexity: O(1)
 *
 * 2) Level order (breadth first) traversal.
 * Traverse the tree level-by-level, and once we reach a node that has no children,
 * we know we've reached the min level, so return the level.
 * Else, return the level after we finished iterating over all the nodes.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(n) [where n is the number of nodes in the binary tree]
 */

int minDepth(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    if(root->left==nullptr && root->right==nullptr)
    {
        return 1;
    }

    int left=minDepth(root->left);

    int right=minDepth(root->right);

    if(left==0)
    {
        return 1 + right;
    }
    else if(right==0)
    {
        return 1 + left;
    }
    else
    {
        return 1 + min(left, right);
    }
}

int minDepth(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    queue<TreeNode*> nodes;

    nodes.push(root);

    int depth=1;

    while(!nodes.empty())
    {
        int qSize=int(nodes.size());

        for(int i=0;i<qSize;++i)
        {
            TreeNode* current=nodes.front();

            nodes.pop();

            if(current->left==nullptr && current->right==nullptr)
            {
                return depth;
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

        depth++;
    }

    return depth;
}