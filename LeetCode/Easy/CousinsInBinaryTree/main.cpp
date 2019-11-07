#include "../TreeNode.h"
#include <iostream>
#include <queue>
using namespace std;

/*
 * Approach: use level order traversal to get the parent and depth of each input node in the Binary Tree.
 * Then, check to make sure that the depth of the two nodes is the same and that the two nodes have different parents.
 *
 * Time complexity: O(n) [where n is the number of nodes in the Binary Tree]
 * Space complexity: O(n)
 */

int getNodeLevel(TreeNode* root, const int & number)
{
    queue<TreeNode*> Q;

    Q.push(root);

    int level=0;

    bool done=false;

    while(!Q.empty())
    {
        int qSize=int(Q.size());

        for(int count=0;count<qSize;++count)
        {
            TreeNode* current=Q.front();

            Q.pop();

            if(current->val==number)
            {
                done=true;
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

        if(done)
        {
            break;
        }

        level++;
    }

    return level;
}

void getNodeParent(TreeNode* root, TreeNode* & parent, const int & number)
{
    queue<TreeNode*> Q;

    Q.push(root);

    bool done=false;

    while(!Q.empty())
    {
        int qSize=int(Q.size());

        for(int count=0;count<qSize;++count)
        {
            TreeNode* current=Q.front();

            Q.pop();

            if(current->left!=nullptr)
            {
                if(current->left->val==number)
                {
                    parent=current;

                    done=true;
                }

                Q.emplace(current->left);
            }

            if(current->right!=nullptr)
            {
                if(current->right->val==number)
                {
                    parent=current;

                    done=true;
                }

                Q.emplace(current->right);
            }
        }

        if(done)
        {
            break;
        }
    }
}

bool isCousins(TreeNode* root, int x, int y)
{
    if(root==nullptr)
    {
        return false;
    }

    int xLevel=getNodeLevel(root, x);

    int yLevel=getNodeLevel(root, y);

    TreeNode* xParent=nullptr;

    getNodeParent(root, xParent, x);

    TreeNode* yParent=nullptr;

    getNodeParent(root, yParent, y);

    return xLevel==yLevel && xParent->val!=yParent->val;
}