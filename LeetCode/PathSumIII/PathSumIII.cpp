int pathSum(TreeNode* root, int sum)
{
    if(root==nullptr)
    {
        return 0;
    }
    
    return pathSumFrom(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}

int pathSumFrom(TreeNode* node, int sum)
{
    if(node==nullptr)
    {
        return 0;
    }
    
    return (node->val==sum ? 1 : 0) + pathSumFrom(node->left, sum-node->val) + pathSumFrom(node->right, sum-node->val);
}