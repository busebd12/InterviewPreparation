#include "../TreeNode.h"
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

/*
 * Approaches:
 *
 * 1. Recursive pre-order traversal.
 *
 * Time complexity: O(n) [where n is the number of nodes in the Binary Tree]
 * Space complexity: O(n) recursive stack space
 *
 *
 * 2. Recursive in-order traversal.
 *
 * Time complexity: O(n) [where n is the number of nodes in the Binary Tree]
 * Space complexity: O(n) recursive stack space
 *
 *
 * 3. Recursive post-order traversal.
 *
 * Time complexity: O(n) [where n is the number of nodes in the Binary Tree]
 * Space complexity: O(n) recursive stack space
 *
 * 4. Iterative pre-order traversal.
 *
 * Time complexity: O(n) [where n is the number of nodes in the Binary Tree]
 * Space complexity: O(n)
 *
 *
 * 5. Iterative in-order traversal.
 *
 * Time complexity: O(n) [where n is the number of nodes in the Binary Tree]
 * Space complexity: O(n)
 *
 *
 * 6. Iterative post-order traversal.
 *
 * Time complexity: O(n) [where n is the number of nodes in the Binary Tree]
 * Space complexity: O(n)
 *
 *
 * 7. Level-order traversal.
 *
 * Time complexity: O(n) [where n is the number of nodes in the Binary Tree]
 * Space complexity: O(n)
 */

void preOrderTraversal(TreeNode* root, const int & value, bool & isUnivalued)
{
    if(root==nullptr)
    {
        return;
    }

    if(root->val!=value)
    {
        isUnivalued=false;

        return;
    }

    preOrderTraversal(root->left, value, isUnivalued);

    preOrderTraversal(root->right, value, isUnivalued);
}

bool isUnivalTree(TreeNode* root)
{
    if(root==nullptr)
    {
        return false;
    }

    const int value=root->val;

    bool isUnivalued=true;

    preOrderTraversal(root, value, isUnivalued);

    return isUnivalued;
}

void inOrderTraversal(TreeNode* root, const int & value, bool & isUnivalued)
{
    if(root==nullptr)
    {
        return;
    }

    inOrderTraversal(root->left, value, isUnivalued);

    if(root->val!=value)
    {
        isUnivalued=false;

        return;
    }

    inOrderTraversal(root->right, value, isUnivalued);
}

bool isUnivalTree(TreeNode* root)
{
    if(root==nullptr)
    {
        return false;
    }

    const int value=root->val;

    bool isUnivalued=true;

    inOrderTraversal(root, value, isUnivalued);

    return isUnivalued;
}

void postOrderTraversal(TreeNode* root, const int & value, bool & isUnivalued)
{
    if(root==nullptr)
    {
        return;
    }

    postOrderTraversal(root->left, value, isUnivalued);

    postOrderTraversal(root->right, value, isUnivalued);

    if(root->val!=value)
    {
        isUnivalued=false;

        return;
    }
}

bool isUnivalTree(TreeNode* root)
{
    if(root==nullptr)
    {
        return false;
    }

    const int value=root->val;

    bool isUnivalued=true;

    postOrderTraversal(root, value, isUnivalued);

    return isUnivalued;
}

bool isUnivalTree(TreeNode* root)
{
    if(root==nullptr)
    {
        return false;
    }

    int value=root->val;

    stack<TreeNode*> stk;

    stk.push(root);

    while(!stk.empty())
    {
        TreeNode* current=stk.top();

        stk.pop();

        if(current==nullptr)
        {
            continue;
        }

        if(current->val!=value)
        {
            return false;
        }

        stk.push(current->left);

        stk.push(current->right);
    }

    return true;
}

bool isUnivalTree(TreeNode* root)
{
    if(root==nullptr)
    {
        return false;
    }

    int value=root->val;

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

            TreeNode* current=stk.top();

            stk.pop();

            if(current->val!=value)
            {
                return false;
            }

            root=current->right;
        }
    }

    return true;
}

bool isUnivalTree(TreeNode* root)
{
    if(root==nullptr)
    {
        return false;
    }

    stack<TreeNode*> stk1;

    int value=root->val;

    stk1.push(root);

    while(!stk1.empty())
    {
        TreeNode* current=stk1.top();

        stk1.pop();

        if(current->right!=nullptr)
        {
            stk1.push(current->right);
        }

        if(current->left!=nullptr)
        {
            stk1.push(current->left);
        }

        if(current==nullptr)
        {
            continue;
        }

        if(current->val!=value)
        {
            return false;
        }
    }

    return true;
}

bool isUnivalTree(TreeNode* root)
{
    if(root==nullptr)
    {
        return false;
    }

    queue<TreeNode*> Q;

    Q.push(root);

    int value=root->val;

    while(!Q.empty())
    {
        int qSize=int(Q.size());

        for(int count=0;count<qSize;++count)
        {
            TreeNode* current=Q.front();

            Q.pop();

            if(current->val!=value)
            {
                return false;
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
    }

    return true;
}