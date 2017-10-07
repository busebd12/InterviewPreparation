int minDepth(TreeNode* root)
{
    if(!root)
    {
        return 0;
    }
    
    if(!root->right)
    {
        return 1+minDepth(root->left);
    }
    
    if(!root->left)
    {
        return 1+minDepth(root->right);
    }
    
    return 1+min(minDepth(root->right), minDepth(root->left));
}