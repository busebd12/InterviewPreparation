#include "../TreeNode.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

/*
 * Approaches:
 *
 * 1) Do an in-order traversal of the Binary Search Tree and store the result in a vecotr.
 * Then, for each element in the vector, add up all elements greater than it and map the result
 * to the current number. Finally, change the tree using the hashtable.
 *
 * Time complexity: O(n-squared) [where n is the number of nodes in the Binary Search Tree]
 * Space complexity: O(n)
 *
 * 2) The big brain play is to use a modified version of in-order traversal where we visited the right subtree,
 * the root value, and then the left subtree. If we traverse the tree in this way, we get values in descending order.
 * So, we just keep a running total of the root values as we traverse the tree in this way and each time we see a
 * root value, update it accordingly.
 *
 * Time complexity: O(n) [where n is the number of nodes in the Binary Search Tree]
 * Space complexity: O(n) recursive stack space
 *
 * 3) Iterative version of the second solution.
 *
 * Time complexity: O(n) [where n is the number of nodes in the Binary Search Tree]
 * Space complexity: O(n)
 */

void convert(TreeNode* & root, unordered_map<int, int> & hashtable)
{
    if(root==nullptr)
    {
        return;
    }

    root->val=hashtable[root->val];

    convert(root->left, hashtable);

    convert(root->right, hashtable);
}

void inOrderTraversal(TreeNode* root, vector<int> & sequence)
{
    if(root==nullptr)
    {
        return;
    }

    inOrderTraversal(root->left, sequence);

    sequence.emplace_back(root->val);

    inOrderTraversal(root->right, sequence);
}

TreeNode* convertBST(TreeNode* root)
{
    if(root==nullptr)
    {
        return root;
    }

    vector<int> sequence;

    inOrderTraversal(root, sequence);

    unordered_map<int, int> hashtable;

    for(int i=0;i<sequence.size();++i)
    {
        int sum=sequence[i];

        for(int j=0;j<sequence.size();++j)
        {
            if(sequence[j] > sequence[i])
            {
                sum+=sequence[j];
            }
        }

        hashtable[sequence[i]]=sum;
    }

    convert(root, hashtable);

    return root;
}

void flippedInOrderTraversal(TreeNode* root, int & sum)
{
    if(root==nullptr)
    {
        return;
    }

    flippedInOrderTraversal(root->right, sum);

    root->val=(sum+=root->val);

    flippedInOrderTraversal(root->left, sum);
}

TreeNode* convertBST(TreeNode* root)
{
    if(root==nullptr)
    {
        return root;
    }

    int sum=0;

    flippedInOrderTraversal(root, sum);

    return root;
}

TreeNode* convertBST(TreeNode* root)
{
    if(root==nullptr)
    {
        return root;
    }

    int sum=0;

    stack<TreeNode*> stk;

    TreeNode* node=root;

    int runningTotal=0;

    while(!stk.empty() || node!=nullptr)
    {
        while(node!=nullptr)
        {
            stk.push(node);

            node=node->right;
        }

        node=stk.top();

        stk.pop();

        runningTotal+=node->val;

        node->val=runningTotal;

        node=node->left;
    }

    return root;
}