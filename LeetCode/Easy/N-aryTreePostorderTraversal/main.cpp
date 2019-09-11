#include "../Node.h"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
 * Approaches:
 *
 * 1) Recursive. In a depth-first manner, visit each child node of the current node
 * and then add the root node's value to our result vector.
 *
 * Time complexity: O(n) [where n is the number of nodes in the n-ary tree]
 * Space complexity: O(n) recursive stack space
 *
 * 2) Iterative versiono of the first solution. We use an extra stack to
 * keep the correct ordering of our results.
 *
 * Time complexity: O(n) [where n is the number of nodes in the n-ary tree]
 * Space complexity: O(n)
 *
 * 3) Almost the same as the second solution, except we reverse our result vector
 * to get the correct ordering instead of using a stack.
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

    for(Node* child : root->children)
    {
        traverse(child, result);
    }

    result.emplace_back(root->val);
}

vector<int> postorder(Node* root)
{
    vector<int> result;

    if(root==nullptr)
    {
        return result;
    }

    traverse(root, result);

    return result;
}

vector<int> postorder(Node* root)
{
    vector<int> result;

    if(root==nullptr)
    {
        return result;
    }

    stack<Node*> stk;

    stack<int> reversed;

    stk.push(root);

    while(!stk.empty())
    {
        Node* current=stk.top();

        stk.pop();

        reversed.push(current->val);

        if(!current->children.empty())
        {
            for(Node* child : current->children)
            {
                stk.push(child);
            }
        }
    }

    while(!reversed.empty())
    {
        int value=reversed.top();

        reversed.pop();

        result.push_back(value);
    }

    return result;
}

vector<int> postorder(Node* root)
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
            for(Node* child : current->children)
            {
                stk.push(child);
            }
        }
    }

    reverse(result.begin(), result.end());

    return result;
}