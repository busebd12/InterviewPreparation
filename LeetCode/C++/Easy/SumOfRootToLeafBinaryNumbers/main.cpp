#include "../TreeNode.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1. We traverse the tree recursively using the pre-order traversal algorithm and build all the different
 * root-to-leaf paths as we go. Once we have finished building a path, we calculate the sum of the path and add it to our sum variable.
 * Return the sum variable as our answer.
 *
 * Time complexity: O(n-squared) [where n is the number of nodes in our Binary Tree]
 * Space complexity: O(h) recursive stack space [where h is the height of the tree] + O(p) [where p is the number of root-to-leaf paths]
 *
 * 2. Similar approach to the first solution but we calculate the sum of each root-to-leaf path as we traverse the tree.
 * After we have calculated the path sum, we add it to our sum variable. Return our sum variable.
 *
 * Time complexity: O(n) [where n is the number of nodes in our binary tree]
 * Space complexity: O(h) recursive stack space [where h is the height of our binary tree]
 *
 * 3. Iterative version of the second solution using a stack.
 *
 * Time complexity: O(n) [where n is the number of nodes in our binary tree]
 * Space complexity: O(h) [where h is the height of the binary tree]
 */

int getSum(const vector<int> & path)
{
    int total=0;

    for(const int & number : path)
    {
        total=((total * 2) + number);
    }

    return total;
}

void preOrderTraversal(TreeNode* root, vector<int> path, int & sum)
{
    if(root==nullptr)
    {
        return;
    }
    else if(root->left==nullptr && root->right==nullptr)
    {
        path.emplace_back(root->val);

        sum+=getSum(path);
    }
    else
    {
        path.emplace_back(root->val);

        preOrderTraversal(root->left, path, sum);

        preOrderTraversal(root->right, path, sum);
    }
}

int sumRootToLeaf(TreeNode* root)
{
    int sum=0;

    if(root==nullptr)
    {
        return sum;
    }

    vector<int> path;

    preOrderTraversal(root, path, sum);

    return sum;
}

void preOrderTraversal(TreeNode* root, int & sum, int pathSum)
{
    if(root==nullptr)
    {
        return;
    }

    pathSum=((pathSum * 2) + root->val);

    if(root->left==nullptr && root->right==nullptr)
    {
        sum+=pathSum;
    }

    preOrderTraversal(root->left, sum, pathSum);

    preOrderTraversal(root->right, sum, pathSum);
}

int sumRootToLeaf(TreeNode* root)
{
    int sum=0;

    if(root==nullptr)
    {
        return sum;
    }

    int pathSum=0;

    preOrderTraversal(root, sum, pathSum);

    return sum;
}

int sumRootToLeaf(TreeNode* root)
{
    int sum=0;

    if(root==nullptr)
    {
        return sum;
    }

    stack<pair<TreeNode*, int>> stk;

    stk.push(make_pair(root, root->val));

    while(!stk.empty())
    {
        pair<TreeNode*, int> current=stk.top();

        stk.pop();

        if(current.first->left==nullptr && current.first->right==nullptr)
        {
            sum+=current.second;
        }

        if(current.first->left!=nullptr)
        {
            int leftSum=current.second;

            leftSum=((leftSum * 2) + current.first->left->val);

            stk.push(make_pair(current.first->left, leftSum));
        }

        if(current.first->right!=nullptr)
        {
            int rightSum=current.second;

            rightSum=((rightSum * 2) + current.first->right->val);

            stk.push(make_pair(current.first->right, rightSum));
        }
    }

    return sum;
}