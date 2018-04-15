#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    TreeNode* left;

    TreeNode* right;

    int val;

    explicit TreeNode(int x): left(nullptr), right(nullptr), val(x) {}
};

void insert(TreeNode* & root, int value)
{
    queue<TreeNode*> q;

    q.emplace(root);

    while(!q.empty())
    {
        TreeNode* current=q.front();

        q.pop();

        if(current->left==nullptr)
        {
            current->left=new TreeNode(value);

            break;
        }
        else
        {
            q.emplace(current->left);
        }

        if(current->right==nullptr)
        {
            current->right=new TreeNode(value);

            break;
        }
        else
        {
            q.emplace(current->right);
        }
    }
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
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

    int count=0;

    while(true)
    {
        int nodesInCurrentLevel=int(nodes.size());

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

        if(count%2==1)
        {
            reverse(begin(level), end(level));
        }

        result.emplace_back(level);

        ++count;

        level.clear();
    }

    return result;
}