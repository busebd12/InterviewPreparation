#include "../TreeNode.h"
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * 1) Using a queue, iterate through each node in the tree.
 * For each node, we check the different cases for ancestry: if the current has p and q as descendants,
 * if the current is p, or if the current node is q.
 *
 * Time complexity: O(n-sqaured) [where n is the number of nodes in the binary search tree]
 * Space complexity: O(n-sqaured)
 *
 * 2) Recursively search through the binary search tree using the properties of binary search trees.
 *
 * Time complexity: O(h) [where h is the height of the binary search tree]
 * Space complexity: O(h) [where h is the recursive stack space used]
 *
 * 3) Same logic as number two but just iteratively.
 *
 * Time complexity: O(h) [where h is the height of the binary search tree]
 * Space complexity: O(1)
 */
bool isDescendant(TreeNode* root, TreeNode* target)
{
    if(root==nullptr)
    {
        return false;
    }

    if(root->val==target->val)
    {
        return true;
    }

    return isDescendant(root->left, target) || isDescendant(root->right, target);
}


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root==nullptr)
    {
        return root;
    }

    if(root->left==nullptr && root->right==nullptr)
    {
        return root;
    }

    pair<int, TreeNode*> lca;

    queue<TreeNode*> nodes;

    nodes.push(root);

    lca.first=-1;

    lca.second=nullptr;

    int level=0;

    while(true)
    {
        int qSize=int(nodes.size());

        if(qSize==0)
        {
            break;
        }

        for(int count=0;count<qSize;++count)
        {
            TreeNode* current=nodes.front();

            nodes.pop();

            if(isDescendant(current, p) && isDescendant(current, q))
            {
                if(level > lca.first)
                {
                    lca.first=level;

                    lca.second=current;
                }
            }

            if(current->val==p->val)
            {
                if(isDescendant(p, q))
                {
                    if(level > lca.first)
                    {
                        lca.first=level;

                        lca.second=p;
                    }
                }
            }

            if(current->val==q->val)
            {
                if(isDescendant(q, p))
                {
                    if(level > lca.first)
                    {
                        lca.first=level;

                        lca.second=q;
                    }
                }
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

        level++;
    }

    return lca.second;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if((root->val > p->val) && (root->val > q->val))
    {
        return lowestCommonAncestor(root->left, p, q);
    }

    if((root->val < p->val) && (root->val < q->val))
    {
        return lowestCommonAncestor(root->right, p, q);
    }

    return root;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    TreeNode* current=root;

    while(true)
    {
        if(p->val < current->val && q->val < current->val)
        {
            current=current -> left;
        }
        else if(p->val > current->val && q->val > current->val)
        {
            current=current->right;
        }
        else
        {
            break;
        }
    }

    return current;
}