#include "../Node.h"
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

/*
 * Approaches:
 *
 * 1) Recursive, depth-first traversal. The maximum depth of any node is 1 + maximum depth of its children nodes.
 *
 * Time complexity: O(n) [where n is the number of nodes in the n-ary tree]
 * Space complexity: O(n)
 *
 * 2) Iterative, breadth-first traversal. The max depth is equal to the deepest level of the tree.
 *
 * Time complexity: O(n) [where n is the number of nodes in the n-ary tree]
 * Space complexity: O(n)
 *
 * 3) Iterative, depth-first traversal. We use two stacks, one to keep track of the nodes and another to
 * keep track of the depths.
 *
 * Time complexity: O(n) [where n is the number of nodes in the n-ary tree]
 * Space complexity: O(n)
 *
 * 4) Iterative, depth-first traversal. Similar to solution number three, but we use a stack of pairs instead of two stacks.
 *
 * Time complexity: O(n) [where n is the number of nodes in the n-ary tree]
 * Space complexity: O(n)
 */

int dfs(Node* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    if(root->children.empty())
    {
        return 1;
    }

    int maxChildDepth=-1;

    for(Node* node : root->children)
    {
        maxChildDepth=max(maxChildDepth, dfs(node));
    }

    return 1 + maxChildDepth;
}

int maxDepth(Node* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    if(root->children.empty())
    {
        return 1;
    }

    return dfs(root);
}

int maxDepth(Node* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    queue<Node*> Q;

    Q.push(root);

    int depth=0;

    while(true)
    {
        int qSize=int(Q.size());

        if(qSize==0)
        {
            break;
        }

        for(int count=0;count<qSize;++count)
        {
            Node* current=Q.front();

            Q.pop();

            if(!current->children.empty())
            {
                for(Node* node : current->children)
                {
                    if(node!=nullptr)
                    {
                        Q.push(node);
                    }
                }
            }
        }

        depth++;
    }

    return depth;
}

int maxDepth(Node* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    stack<Node*> nodes;

    stack<int> depths;

    nodes.push(root);

    depths.push(int(1));

    int result=-1;

    while(!nodes.empty())
    {
        Node* current=nodes.top();

        nodes.pop();

        int currentDepth=depths.top();

        result=max(result, currentDepth);

        depths.pop();

        if(!current->children.empty())
        {
            for(Node* node : current->children)
            {
                nodes.push(node);

                depths.push(currentDepth + 1);
            }
        }
    }

    return result;
}

int maxDepth(Node* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    stack<pair<Node*, int>> stk;

    stk.push(make_pair(root, 1));

    int result=-1;

    while(!stk.empty())
    {
        pair<Node*, int> current=stk.top();

        stk.pop();

        int currentDepth=current.second;

        result=max(result, currentDepth);

        if(!current.first->children.empty())
        {
            for(Node* node : current.first->children)
            {
                stk.push(make_pair(node, currentDepth+1));
            }
        }
    }

    return result;
}