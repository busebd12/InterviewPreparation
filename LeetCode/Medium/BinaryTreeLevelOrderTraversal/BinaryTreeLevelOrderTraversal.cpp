#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;

    TreeNode *left;

    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void add(TreeNode* & root, int value)
{
    queue<TreeNode*> q;

    q.emplace(root);

    while(!q.empty())
    {
        TreeNode* current=q.front();

        q.pop();

        if(current->left!=nullptr)
        {
            q.emplace(current->left);
        }
        else
        {
            current->left=new TreeNode(value);

            break;
        }

        if(current->right!=nullptr)
        {
            q.emplace(current->right);
        }
        else
        {
            current->right=new TreeNode(value);

            break;
        }
    }
}

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> result;

    if(root==nullptr)
    {
        return result;
    }

    if(root!=nullptr && root->right==nullptr && root->left==nullptr)
    {
        vector<int> v;

        v.emplace_back(root->val);

        result.emplace_back(v);

        return result;
    }

    queue<TreeNode*> nodes;

    nodes.emplace(root);

    vector<int> level;

    while(true)
    {
        int nodesInCurrentLevel=nodes.size();

        if(nodesInCurrentLevel==0)
        {
            break;
        }

        while(nodesInCurrentLevel > 0)
        {
            TreeNode* current=nodes.front();

            nodes.pop();

            level.emplace_back(current->val);

            if(current->left!=nullptr)
            {
                nodes.emplace(current->left);
            }

            if(current->right!=nullptr)
            {
                nodes.emplace(current->right);
            }

            --nodesInCurrentLevel;
        }

        result.emplace_back(level);

        level.clear();
    }

    return result;
}