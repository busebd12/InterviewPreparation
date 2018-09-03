#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode* root, vector<int> & result, int currentDepth)
{
    if(root==nullptr)
    {
        return;
    }

    if(result.size()==currentDepth)
    {
        result.emplace_back(root->val);
    }

    helper(root->right, result, currentDepth+1);

    helper(root->left, result, currentDepth+1);
}

vector<int> rightSideView(TreeNode* root)
{
    vector<int> result;

    int currentDepth=0;

    helper(root, result, currentDepth);

    return result;
}