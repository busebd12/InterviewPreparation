#include "../TreeNode.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/*
 * Approaches:
 *
 * 1) Breadth-first search, aka level-order traversal, iterative
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary search tree]
 * Space complexity: O(n)
 *
 * 2) Depth-first search, recursive
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary search tree]
 * Space complexity: O(n)
 *
 * 3) Depth-first search, iterative
 *
 * Time complexity: O(n) [where n is the number of nodes in the binary search tree]
 * Space complexity: O(n)
 */

int closestValue(TreeNode* root, double target)
{
    if(root==nullptr)
    {
        return int(target);
    }

    queue<TreeNode*> nodes;

    nodes.push(root);

    pair<int, double> p(-1, -1);

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

            if(p.first==-1 && p.second==-1)
            {
                p.first=current->val;

                p.second=abs(double(current->val - target));
            }
            else
            {
                double difference=abs(double(current->val - target));

                if(difference < p.second)
                {
                    p.first=current->val;

                    p.second=difference;
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
    }

    return p.first;
}

void dfs(TreeNode* root, double target, pair<int, double> & p)
{
    if(root==nullptr)
    {
        return;
    }

    if(p.first==-1 && p.second==-1)
    {
        p.first=root->val;

        p.second=abs(double(root->val - target));
    }
    else
    {
        double difference=abs(double(root->val - target));

        if(difference < p.second)
        {
            p.second=difference;

            p.first=root->val;
        }
    }

    if(target > root->val)
    {
        dfs(root->right, target, p);
    }

    if(target < root->val)
    {
        dfs(root->left, target, p);
    }
}

int closestValue(TreeNode* root, double target)
{
    if(root==nullptr)
    {
        return int(target);
    }

    pair<int, double> p(-1, -1);

    dfs(root, target, p);

    return p.first;
}

int closestValue(TreeNode* root, double target)
{
    if(root==nullptr)
    {
        return int(target);
    }

    stack<TreeNode*> stk;

    stk.push(root);

    pair<int, double> p(-1, -1);

    while(!stk.empty())
    {
        TreeNode* current=stk.top();

        stk.pop();

        if(p.first==-1 && p.second==-1)
        {
            p.first=current->val;

            p.second=abs(double(current->val - target));
        }
        else
        {
            double difference=abs(double(current->val - target));

            if(difference < p.second)
            {
                p.first=current->val;

                p.second=difference;
            }
        }

        if(target > current->val)
        {
            if(current->right!=nullptr)
            {
                stk.push(current->right);
            }
        }

        if(target < current->val)
        {
            if(current->left!=nullptr)
            {
                stk.push(current->left);
            }
        }
    }

    return p.first;
}