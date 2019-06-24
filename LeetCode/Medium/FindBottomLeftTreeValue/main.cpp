#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findBottomLeftValueV1(TreeNode* root)
{
    vector<vector<int>> result;

    TreeNode* answer=root;

    if(root==nullptr)
    {
        return -1;
    }

    if(root->right==nullptr && root->left==nullptr)
    {
        return root->val;
    }

    queue<TreeNode*> nodes;

    nodes.emplace(root);

    vector<int> level;

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

            nodesInCurrentLevel--;
        }

        result.emplace_back(level);

        level.clear();
    }

    int n=int(result.size());

    return result[n-1][0];
}

int findBottomLeftValueV2(TreeNode* root)
{
    vector<vector<int>> result;

    TreeNode* answer=root;

    if(root==nullptr)
    {
        return -1;
    }

    if(root->right==nullptr && root->left==nullptr)
    {
        return root->val;
    }

    queue<TreeNode*> nodes;

    nodes.emplace(root);

    while(!nodes.empty())
    {
        auto current=nodes.front();

        nodes.pop();

        answer=current;

        if(current->right!=nullptr)
        {
            nodes.emplace(current->right);
        }

        if(current->left!=nullptr)
        {
            nodes.emplace(current->left);
        }
    }

    return answer->val;
}