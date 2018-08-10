#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;

    TreeNode *left;

    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void add(TreeNode* & root, int number)
{
    queue<TreeNode*> q;

    q.emplace(root);

    while(!q.empty())
    {
        auto current=q.front();

        q.pop();

        if(current->left==nullptr)
        {
            current->left=new TreeNode(number);

            break;
        }
        else
        {
            q.emplace(current->left);
        }

        if(current->right==nullptr)
        {
            current->right=new TreeNode(number);

            break;
        }
        else
        {
            q.emplace(current->right);
        }
    }
}

void helper(TreeNode* root, string path, int & totalSum)
{
    if(root==nullptr)
    {
        return;
    }

    path+=('0' + root->val);

    if(root->left==nullptr && root->right==nullptr)
    {
        totalSum+=stoi(path);

        return;
    }

    helper(root->left, path, totalSum);

    helper(root->right, path, totalSum);
}

int sumNumbers(TreeNode* root)
{
    int totalSum=0;

    if(root==nullptr)
    {
        return totalSum;
    }

    string path="";

    helper(root, path, totalSum);

    return totalSum;
}