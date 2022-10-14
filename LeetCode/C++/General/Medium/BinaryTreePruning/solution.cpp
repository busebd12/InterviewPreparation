#include "./TreeNode.h"
using namespace std;

class Solution
{
    public:
        TreeNode* pruneTree(TreeNode* root)
        {
            if(root==nullptr)
            {
                return nullptr;
            }
            
            root=helper(root);
            
            return root;
        }
        
        TreeNode* helper(TreeNode* root)
        {
            if(root==nullptr)
            {
                return root;
            }
            
            //Prune left subtree
            root->left=helper(root->left);
            
            //Prune right subtree
            root->right=helper(root->right);
            
            //If we reach a leaf node that is a zero, then we want to get rid of it by setting it to nullptr
            if(root->val==0 and root->left==nullptr and root->right==nullptr)
            {
                return nullptr;
            }
            
            //Otherwise, just return the root node as it is
            return root;
        }
};