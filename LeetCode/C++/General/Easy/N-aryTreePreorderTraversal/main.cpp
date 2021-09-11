#include "../Node.h"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
 * Approaches:
 *
 * 1) Recursive. Add the current root's value to our output vector. Then, do a depth-first traversal
 * for each of the current node's children nodes.
 *
 * Time complexity: O(n) [where n is the number of nodes in the n-ary tree]
 * Space complexity: O(n)
 *
 * 2) Iterative version of the first solution.
 *
 * Time complexity: O(n) [where n is the number of nodes in the n-ary tree]
 * Space complexity: O(n)
 */

void traverse(Node* root, vector<int> & result)
{
    if(root==nullptr)
    {
        return;
    }

    result.emplace_back(root->val);

    for(Node* node : root->children)
    {
        traverse(node, result);
    }
}

vector<int> preorder(Node* root)
{
    vector<int> result;

    if(root==nullptr)
    {
        return result;
    }

    traverse(root, result);

    return result;
}

vector<int> preorder(Node* root)
{
    vector<int> result;

    if(root==nullptr)
    {
        return result;
    }

    stack<Node*> stk;

    stk.push(root);

    while(!stk.empty())
    {
        Node* current=stk.top();

        stk.pop();

        result.emplace_back(current->val);

        if(!current->children.empty())
        {
            int childrenSize=int(current->children.size());

            for(int i=childrenSize-1;i>=0;--i)
            {
                stk.push(current->children[i]);
            }
        }
    }

    return result;
}