#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;

    TreeNode *left;

    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void getPaths(vector<vector<int>> & paths, vector<int> path, TreeNode* root, int sum)
{
    if(root==nullptr)
    {
        return;
    }
    else
    {
        path.emplace_back(root->val);

        if(sum==root->val && root->left==nullptr && root->right==nullptr)
        {
            paths.emplace_back(path);

            path.clear();
        }

        getPaths(paths, path, root->left, sum-root->val);

        getPaths(paths, path, root->right, sum-root->val);
    }
}

vector<vector<int>> pathSum(TreeNode* root, int sum)
{
    vector<vector<int>> paths;

    if(root==nullptr)
    {
        return paths;
    }

    vector<int> path;

    getPaths(paths, path, root, sum);

    return paths;
}