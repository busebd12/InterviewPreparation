#include "../TreeNode.h"
#include <deque>
#include <iostream>
#include <queue>
#include <vector>

/*
 * Solutions:
 *
 * 1. Do a level-order traversal and then reverse every other level before adding the level to the traversal.
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary tree]
 * Space complexity: O(n)
 *
 * 2. Use a deque instead of a regular queue for the level-order traversal. We use the double-endedness
 * of the deque to achieve the reversal of the necessary levels.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root)
{
    std::vector<std::vector<int>> traversal;

    if(root==nullptr)
    {
        return traversal;
    }

    std::queue<TreeNode*> Q;

    Q.push(root);

    bool flip=false;

    while(!Q.empty())
    {
        int qSize=int(Q.size());

        std::vector<int> level;

        for(int count=0;count<qSize;++count)
        {
            TreeNode* current=Q.front();

            Q.pop();

            level.emplace_back(current->val);

            if(current->left!=nullptr)
            {
                Q.emplace(current->left);
            }

            if(current->right!=nullptr)
            {
                Q.emplace(current->right);
            }
        }

        if(flip)
        {
            std::reverse(level.begin(), level.end());

            flip=false;
        }
        else
        {
            flip=true;
        }

        traversal.push_back(level);
    }

    return traversal;
}

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root)
{
    std::vector<std::vector<int>> traversal;

    if(root==nullptr)
    {
        return traversal;
    }

    std::deque<TreeNode*> dq;

    dq.push_back(root);

    bool zig=true;

    while(!dq.empty())
    {
        int dqSize=int(dq.size());

        std::vector<int> level;

        for(int count=0;count<dqSize;++count)
        {
            TreeNode* current=nullptr;

            if(zig)
            {
                current=dq.front();

                dq.pop_front();

                level.emplace_back(current->val);

                if(current->left!=nullptr)
                {
                    dq.push_back(current->left);
                }

                if(current->right!=nullptr)
                {
                    dq.push_back(current->right);
                }
            }
            else
            {
                current=dq.back();

                dq.pop_back();

                level.emplace_back(current->val);

                if(current->right!=nullptr)
                {
                    dq.push_front(current->right);
                }

                if(current->left!=nullptr)
                {
                    dq.push_front(current->left);
                }
            }
        }

        traversal.push_back(level);

        if(zig)
        {
            zig=false;
        }
        else
        {
            zig=true;
        }
    }

    return traversal;
}