#include <iostream>
using namespace std;

struct TreeNode
{
    int val;

    TreeNode *left;

    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode* root)
{
    if(root==nullptr)
    {
        return;
    }

    TreeNode* node=root;

    while(node)
    {
        if(node->left)
        {
            TreeNode* rightMost=node->left;

            //find the right most node in the left subtree
            while(rightMost->right)
            {
                rightMost=rightMost->right;
            }

            //attach the right subtree to the right most node in the left subtree
            rightMost->right=node->right;

            //make the right subtree the left subtree
            node->right=node->left;

            node->left=nullptr;
        }

        node=node->right;
    }
}