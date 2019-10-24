#include "../TreeNode.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Perform a recursive in-order traversal of the BST and store the value for each root node in a vector<int> traversal.
 * Then, iterate over the traversal vector and build the increasing order search tree.
 *
 * Time complexity: O(n) [where n is the number of nodes in the Binary Search Tree]
 * Space complexity: O(n)
 *
 *
 * 2) Perform a recrusive in-order traversal of the BST and construct the increasing order BST as we go.
 *
 * Time complexity: O(n * m) [where n is the number of nodes in the BST and m is the number of nodes in the increasing order BST]
 * Space complexity: O(n recursive stack space + m)
 *
 * 3) Iterative version of the second solution.
 *
 * Time complexity: O(n * m) [where n is the number of nodes in the BST and m is the number of nodes in the increasing order BST]
 * Space complexity: O(n + m)
 */

void inOrderTraversal(TreeNode* root, vector<int> & traversal)
{
    if(root==nullptr)
    {
        return;
    }

    inOrderTraversal(root->left, traversal);

    traversal.emplace_back(root->val);

    inOrderTraversal(root->right, traversal);
}

void addAtEnd(TreeNode* & result, const int & value)
{
    if(result==nullptr)
    {
        result=new TreeNode(value);
    }
    else
    {
        TreeNode* current=result;

        while(current->right!=nullptr)
        {
            current=current->right;
        }

        current->right=new TreeNode(value);
    }
}

TreeNode* increasingBST(TreeNode* root)
{
    if(root==nullptr)
    {
        return root;
    }

    TreeNode* result=nullptr;

    vector<int> traversal;

    inOrderTraversal(root, traversal);

    for(const int & value : traversal)
    {
        addAtEnd(result, value);
    }

    return result;
}

void inOrderTraversal(TreeNode* root, TreeNode* & result)
{
    if(root==nullptr)
    {
        return;
    }

    inOrderTraversal(root->left, result);

    if(result==nullptr)
    {
        result=new TreeNode(root->val);
    }
    else
    {
        TreeNode* current=result;

        while(current->right!=nullptr)
        {
            current=current->right;
        }

        current->right=new TreeNode(root->val);
    }

    inOrderTraversal(root->right, result);
}

TreeNode* increasingBST(TreeNode* root)
{
    if(root==nullptr)
    {
        return root;
    }

    TreeNode* result=nullptr;

    inOrderTraversal(root, result);

    return result;
}

TreeNode* increasingBST(TreeNode* root)
{
    if(root==nullptr)
    {
        return root;
    }

    TreeNode* result=nullptr;

    stack<TreeNode*> stk;

    while(true)
    {
        if(root!=nullptr)
        {
            stk.push(root);

            root=root->left;
        }
        else
        {
            if(stk.empty())
            {
                break;
            }

            root=stk.top();

            stk.pop();

            if(result==nullptr)
            {
                result=new TreeNode(root->val);
            }
            else
            {
                TreeNode* current=result;

                while(current->right!=nullptr)
                {
                    current=current->right;
                }

                current->right=new TreeNode(root->val);
            }

            root=root->right;
        }
    }

    return result;
}