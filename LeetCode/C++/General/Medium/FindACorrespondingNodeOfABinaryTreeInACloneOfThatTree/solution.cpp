class Solution
{
    public:
        TreeNode* getNode(TreeNode* cloned, TreeNode* target)
        {
            if(cloned==nullptr)
            {
                return nullptr;
            }
            
            if(cloned->val==target->val)
            {
                return cloned;
            }
            
            TreeNode* left=getNode(cloned->left, target);
            
            TreeNode* right=getNode(cloned->right, target);
            
            return (left==nullptr) ? right : left;
        }
    
        TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
        {
            TreeNode* result=nullptr;
            
            result=getNode(cloned, target);
            
            return result;
        }
};

class Solution
{
    public:
        TreeNode* getNode(TreeNode* original, TreeNode* cloned, TreeNode* target)
        {
            if(original==nullptr)
            {
                return nullptr;
            }
            
            if(original==target)
            {
                return cloned;
            }
            
            TreeNode* left=getNode(original->left, cloned->left, target);
            
            TreeNode* right=getNode(original->right, cloned->right, target);
            
            return (left==nullptr) ? right : left;
        }
    
        TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
        {
            TreeNode* result=nullptr;
            
            result=getNode(original, cloned, target);
            
            return result;
        }
};