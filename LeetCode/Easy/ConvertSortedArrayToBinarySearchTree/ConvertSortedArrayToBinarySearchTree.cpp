TreeNode* sortedArrayToBST(vector<int> & nums, int start, int end)
{
    if(start >= end)
    {
        return NULL;
    }
    
    int middleIndex=(start+end)/2;
    
    TreeNode* root=new TreeNode(nums[middleIndex]);
    
    root->right=sortedArrayToBST(nums, middleIndex+1, end);
    
    root->left=sortedArrayToBST(nums, start, middleIndex);
    
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
    if(nums.size()==0)
    {
        return NULL;
    }
    
    return sortedArrayToBST(nums, 0, nums.size());
}