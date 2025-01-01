#include <vector>
using namespace std;

/*
Solution 1:

Time complexity: O(n + n^2) [where n is the number of nodes in the binary tree]
Space complexity: O(n)
*/

class Solution
{
    public:
        TreeNode* insertIntoMaxTree(TreeNode* root, int val)
        {
            TreeNode* result=nullptr;
            
            vector<int> values=inOrderTraversal(root);

            values.push_back(val);

            int n=values.size();

            int left=0;

            int right=n-1;

            result=buildTree(values, left, right);

            return result;
        }

        vector<int> inOrderTraversal(TreeNode* root)
        {
            vector<int> values;

            TreeNode* current=root;

            deque<TreeNode*> stack;

            while(!stack.empty() or current!=nullptr)
            {
                while(current!=nullptr)
                {
                    stack.push_back(current);

                    current=current->left;
                }

                current=stack.back();

                stack.pop_back();

                values.emplace_back(current->val);

                current=current->right;
            }

            return values;
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

/*
Solution 2: 

Time complexity: O(n) [where n is the number of nodes in the binary tree]
Space complexity: O(n) [recursive stack space used]
*/

class Solution
{
    public:
        TreeNode* insertIntoMaxTree(TreeNode* root, int val)
        {
            if(root==nullptr)
            {
                return new TreeNode(val);
            }

            if(val > root->val)
            {
                return new TreeNode(val, root, nullptr);
            }

            root->right=insertIntoMaxTree(root->right, val);

            return root;
    }
};