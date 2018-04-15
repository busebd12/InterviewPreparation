#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    TreeNode* left;

    TreeNode* right;

    int val;

    TreeNode(int x): val(x), left(nullptr), right(nullptr){};
};

vector<TreeNode*> constructTrees(int start, int end)
{
    vector<TreeNode*> trees;

    if(start > end)
    {
        trees.emplace_back(nullptr);

        return trees;
    }

    for(int i=start;i<=end;++i)
    {
        vector<TreeNode*> leftSubtree=constructTrees(start, i-1);

        vector<TreeNode*> rightSubtree=constructTrees(i+1, end);

        for(int j=0;j<leftSubtree.size();++j)
        {
            TreeNode* left=leftSubtree[j];

            for(int k=0;k<rightSubtree.size();++k)
            {
                TreeNode* right=rightSubtree[k];

                TreeNode* root=new TreeNode(i);

                root->right=right;

                root->left=left;

                trees.emplace_back(root);
            }
        }
    }

    return trees;
}

vector<TreeNode*> generateTrees(int n)
{
    vector<TreeNode*> result;

    if(n <= 0)
    {
        return result;
    }

    result=constructTrees(1, n);

    return result;
}