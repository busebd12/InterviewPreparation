#include "../TreeNode.h"
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

/*
 * Approaches:
 *
 * 1) Do the following:
 *
 * a) Using level order traversal, put all the numbers of the BST into a vector<int> levelOrder.
 * b) Sort the vector<int> levelOrder.
 * c) Loop through the vector<int> levelOrder and find the minimum distance between adjacent elements
 *
 * Time complexity: O(n log n) [where n is the number of elements in the BST]
 * Space complexity: O(n)
 *
 * 2) Recursive in-order traversal. Since the tree is a BST, in-order traversal will result in traversing the
 * elements of the BST in ascending order. Then, we just have to keep track of the previous number and find the
 * difference between that number and the current root value. Return the minimum of those differences.
 *
 * Time complexity: O(n) [where n is the number of elements in the BST]
 * Space complexity: O(n) recursive stack space
 *
 *
 * 3) Just the iterative version of the second solution.
 *
 * Time complexity: O(n) [where n is the number of elements in the BST]
 * Space complexity: O(n)
 */

void levelOrderTraversal(TreeNode* root, vector<int> & levelOrder)
{
    queue<TreeNode*> Q;

    Q.push(root);

    while(!Q.empty())
    {
        size_t qSize=Q.size();

        for(size_t count=0;count<qSize;++count)
        {
            TreeNode* current=Q.front();

            Q.pop();

            levelOrder.emplace_back(current->val);

            if(current->left!=nullptr)
            {
                Q.emplace(current->left);
            }

            if(current->right!=nullptr)
            {
                Q.emplace(current->right);
            }
        }
    }
}

int minDiffInBST(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    if(root->left==nullptr && root->right==nullptr)
    {
        return 0;
    }

    vector<int> levelOrder;

    levelOrderTraversal(root, levelOrder);

    sort(levelOrder.begin(), levelOrder.end());

    int result=numeric_limits<int>::max();

    size_t n=levelOrder.size();

    for(size_t index=1;index<n;++index)
    {
        result=min(result, levelOrder[index] - levelOrder[index-1]);
    }

    return result;
}

void inOrderTraversal(TreeNode* root, int & result, int & previous)
{
    if(root==nullptr)
    {
        return;
    }

    inOrderTraversal(root->left, result, previous);

    if(previous >= 0)
    {
        result=min(result, root->val - previous);
    }

    previous=root->val;

    inOrderTraversal(root->right, result, previous);
}

int minDiffInBST(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    if(root->left==nullptr && root->right==nullptr)
    {
        return 0;
    }

    int result=numeric_limits<int>::max();

    int previous=-1;

    inOrderTraversal(root, result, previous);

    return result;
}

int minDiffInBST(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    if(root->left==nullptr && root->right==nullptr)
    {
        return 0;
    }

    int result=numeric_limits<int>::max();

    TreeNode* previous=nullptr;

    stack<TreeNode*> stk;

    while(!stk.empty() || root!=nullptr)
    {
        while(root!=nullptr)
        {
            stk.push(root);

            root=root->left;
        }

        TreeNode* popped=stk.top();

        stk.pop();

        if(previous!=nullptr)
        {
            result=min(result, popped->val - previous->val);
        }

        previous=popped;

        root=popped->right;
    }

    return result;
}