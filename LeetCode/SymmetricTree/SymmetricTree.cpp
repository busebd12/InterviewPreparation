bool isSymmetricHelper(TreeNode* p, TreeNode* q)
{
    if(!p && !q)
    {
        return true;
    }

    if(!p && q)
    {
        return false;
    }

    if(p && !q)
    {
        return false;
    }

    return (p->val==q->val && isSymmetricHelper(p->right, q->left) && isSymmetricHelper(p->left, q->right));
}

bool isSymmetric(TreeNode* root)
{
    if(!root)
    {
        return true;
    }
    
    return isSymmetricHelper(root->right, root->left);
}