#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode* root, vector<int> & traversal)
{
    if(root==nullptr)
    {
        return;
    }

    traversal.emplace_back(root->val);

    helper(root->left, traversal);

    helper(root->right, traversal);
}

vector<int> preorderTraversalRecursive(TreeNode* root)
{
    vector<int> traversal;

    if(root==nullptr)
    {
        return traversal;
    }

    helper(root, traversal);

    return traversal;
}

vector<int> preorderTraversalIterative(TreeNode* root)
{
    vector<int> traversal;

    if(root==nullptr)
    {
        return traversal;
    }

    stack<TreeNode*> s;

    s.push(root);

    while(!s.empty())
    {
        TreeNode* node=s.top();

        traversal.emplace_back(node->val);

        s.pop();

        if(node->right!=nullptr)
        {
            s.push(node->right);
        }

        if(node->left!=nullptr)
        {
            s.push(node->left);
        }
    }

    return traversal;
}