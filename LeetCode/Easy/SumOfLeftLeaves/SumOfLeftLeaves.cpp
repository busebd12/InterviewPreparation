int sumOfLeftLeaves(TreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }
    
    if(root->left && root->left->right==nullptr && root->left->left==nullptr)
    {
        return root->left->val + sumOfLeftLeaves(root->right);
    }
    
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}