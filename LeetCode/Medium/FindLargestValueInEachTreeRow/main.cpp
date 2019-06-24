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

vector<int> largestValues(TreeNode* root)
{
    vector<int> result;

    if(root==nullptr)
    {
        return result;
    }

    if(root->right==nullptr && root->left==nullptr)
    {
        result.emplace_back(root->val);

        return result;
    }

    queue<TreeNode*> nodes;

    nodes.emplace(root);

    while(true)
    {
        int nodesInCurrentLevel=int(nodes.size());

        if(nodesInCurrentLevel==0)
        {
            break;
        }

        int maxInCurrentLevel=numeric_limits<int>::min();

        while(nodesInCurrentLevel > 0)
        {
            auto current=nodes.front();

            nodes.pop();

            if(current->val > maxInCurrentLevel)
            {
                maxInCurrentLevel=current->val;
            }

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

        result.emplace_back(maxInCurrentLevel);
    }

    return result;
}