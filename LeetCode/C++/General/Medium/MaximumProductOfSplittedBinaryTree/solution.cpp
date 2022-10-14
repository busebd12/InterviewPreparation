#include <algorithm>

/*
Solution: inspired by this post --> https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/discuss/1408057/Thinking-process-C%2B%2B-implementation-with-Pictures
*/

class Solution
{
    private:
        const int MOD=1000000007;
        
        long long int result=0;
    
        int total=0;
    
    public:
        int maxProduct(TreeNode* root)
        {
            total=createSumTree(root);
            
            getMaxProduct(root);
            
            result=result % MOD;
            
            return result;
        }
    
        int createSumTree(TreeNode* root)
        {
            if(root==nullptr)
            {
                return 0;
            }

            if(root->left==nullptr and root->right==nullptr)
            {
                return root->val;
            }

            int leftSubtreeSum=createSumTree(root->left);

            int rightSubtreeSum=createSumTree(root->right);

            root->val=root->val + leftSubtreeSum + rightSubtreeSum;

            return root->val;
        }
    
        void getMaxProduct(TreeNode* root)
        {
            if(root==nullptr)
            {
                return;
            }
            
            if(root->left!=nullptr)
            {
                long long int rest=total - root->left->val;
                
                long long int leftSubtreeSum=root->left->val;
                
                long long int removeLeftLink=rest * leftSubtreeSum;
                
                result=max(result, removeLeftLink);
            }
            
            if(root->right!=nullptr)
            {
                long long int rest=total - root->right->val;
                
                long long int rightSubtreeSum=root->right->val;
                
                long long int removeRightLink=rest * rightSubtreeSum;
                
                result=max(result, removeRightLink);
            }
            
            getMaxProduct(root->left);
            
            getMaxProduct(root->right);
        }
};