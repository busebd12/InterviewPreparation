int getHeight(TreeNode* currentRoot)
{
    if(currentRoot==NULL)
    {
        return 0;
    }
    
    return 1+max(getHeight(currentRoot->right), getHeight(currentRoot->left));
}

bool isBalanced(TreeNode* root)
{
    if(!root)
    {
        return true;
    }
    
    int leftSubtreeHeight=getHeight(root->left);
    
    int rightSubtreeHeight=getHeight(root->right);
    
    return abs(leftSubtreeHeight-rightSubtreeHeight) <= 1 && isBalanced(root->right) && isBalanced(root->left);
}