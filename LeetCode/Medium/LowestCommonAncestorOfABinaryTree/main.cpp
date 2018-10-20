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

bool findPath(TreeNode* root, TreeNode* target, vector<int> & path)
{
    if(root==nullptr)
    {
        return false;
    }

    path.emplace_back(root->val);

    if(root==target)
    {
        return true;
    }

    if(findPath(root->left, target, path) || findPath(root->right, target, path))
    {
        return true;
    }

    path.pop_back();

    return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root==nullptr)
    {
        return nullptr;
    }

    if(p==nullptr || q==nullptr)
    {
        return nullptr;
    }

    bool pIsInTree=false;

    bool qIsInTree=false;

    vector<int> pPath;

    vector<int> qPath;

    if(findPath(root, p, pPath))
    {
        pIsInTree=true;
    }

    if(findPath(root, q, qPath))
    {
        qIsInTree=true;
    }

    if(!pIsInTree || !qIsInTree)
    {
        return nullptr;
    }

    int length=static_cast<int>(min(pPath.size(), qPath.size()));

    TreeNode* result=nullptr;

    int index=0;

    for(int i=0;i<length;++i)
    {
        if(pPath[i]==qPath[i])
        {
            index=i;
        }
    }

    result=new TreeNode(pPath[index]);

    return result;
}