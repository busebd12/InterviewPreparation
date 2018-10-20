#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int calculateLeftHeight(TreeNode* root)
{
    int height=0;

    while(root!=nullptr)
    {
        root=root->left;

        height++;
    }

    return height;
}

int calculateRightHeight(TreeNode* root)
{
    int height=0;

    while(root!=nullptr)
    {
        root=root->right;

        height++;
    }

    return height;
}

int countNodes(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }

    if(root!=nullptr && root->left==nullptr && root->right==nullptr)
    {
        return 1;
    }

    int leftSubtreeHeight=calculateLeftHeight(root);

    int rightSubtreeHeight=calculateRightHeight(root);

    if(leftSubtreeHeight==rightSubtreeHeight)
    {
        return static_cast<int>(pow(2, leftSubtreeHeight))-1;
    }

    return countNodes(root->right) + countNodes(root->left) + 1;
}