#include <vector>
using namespace std;

/*
Time complexity: O(n^2) [where n is the length of nums]
Space complexity: O(n) [recursive stack space used]
*/

class Solution
{
    public:
        TreeNode* constructMaximumBinaryTree(vector<int> & nums)
        {
            TreeNode* result=nullptr;
            
            int n=nums.size();

            int left=0;

            int right=n-1;

            result=buildTree(nums, left, right);

            return result;
        }

        TreeNode* buildTree(vector<int> & nums, int left, int right)
        {
            TreeNode* root=nullptr;

            if(left > right)
            {
                return root;
            }

            int maxValue=nums[left];

            int maxValueIndex=left;

            for(int index=left;index<=right;index++)
            {
                if(nums[index] > maxValue)
                {
                    maxValue=nums[index];

                    maxValueIndex=index;
                }
            }

            root=new TreeNode(maxValue);

            root->left=buildTree(nums, left, maxValueIndex - 1);

            root->right=buildTree(nums, maxValueIndex + 1, right);

            return root;
        }
};