#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool contains(TreeNode* root, int key)
{
    if(root==nullptr)
    {
        return false;
    }
    else if(key < root->val)
    {
        return contains(root->left, key);
    }
    else if(key > root->val)
    {
        return contains(root->right, key);
    }
    else
    {
        return true;
    }
}

TreeNode* findMin(TreeNode* root)
{
    TreeNode* current=root;

    while(true)
    {
        if(current->left==nullptr)
        {
            break;
        }

        current=current->left;
    }

    return current;
}

void deleteNodeHelper(TreeNode* & root, int key)
{
    if(root==nullptr)
    {
        return;
    }

    if(key < root->val)
    {
        deleteNodeHelper(root->left, key);
    }
    else if(key > root->val)
    {
        deleteNodeHelper(root->right, key);
    }
    else if(root->left!=nullptr && root->right!=nullptr)
    {
        root->val=findMin(root->right)->val;

        deleteNodeHelper(root->right, root->val);
    }
    else
    {
        TreeNode* oldNode=root;

        root=(root->left!=nullptr) ? root->left : root->right;

        delete oldNode;
    }
}

TreeNode* deleteNode(TreeNode* root, int key)
{
    if(root==nullptr || !contains(root, key))
    {
        return root;
    }

    deleteNodeHelper(root, key);

    return root;
}