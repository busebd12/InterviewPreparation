#include <deque>
#include <vector>
using namespace std;

/*
Solution 1: store all the values in the binary search tree in a list. Calculate the appropriate sums for each value. Replace the node
values with the appropriate sum.

Time complexity: O(n^2) [where n is the number of nodes]
Space complexity: O(n)
*/

class Solution
{
    private:
        vector<int> values;
    
        vector<int> sums;
    
    public:
    
        TreeNode* convertBST(TreeNode* root)
        {
            inOrderTraversal(root);
            
            generateSums();
            
            return replaceValues(root);
        }
    
        void inOrderTraversal(TreeNode* root)
        {
            TreeNode* node=root;
            
            deque<TreeNode*> stack;
            
            while(!stack.empty() || node!=nullptr)
            {
                if(node!=nullptr)
                {
                    stack.emplace_back(node);
                    
                    node=node->left;
                }
                else
                {
                    node=stack.back();
                    
                    stack.pop_back();
                    
                    values.emplace_back(node->val);
                    
                    node=node->right;
                }
            }
        }
    
        void generateSums()
        {
            int n=values.size();
            
            sums.resize(n, 0);
            
            for(int i=0;i<n;i++)
            {
                int sum=values[i];
                
                for(int j=i+1;j<n;j++)
                {
                    sum+=values[j];
                }
                
                sums[i]=sum;
            }
        }
    
        TreeNode* replaceValues(TreeNode* root)
        {
            int index=0;
            
            TreeNode* node=root;
            
            deque<TreeNode*> stack;
            
            while(!stack.empty() || node!=nullptr)
            {
                if(node!=nullptr)
                {
                    stack.emplace_back(node);
                    
                    node=node->left;
                }
                else
                {
                    node=stack.back();
                    
                    stack.pop_back();
                    
                    node->val=sums[index];
                    
                    index++;
                    
                    node=node->right;
                }
            }
            
            return root;
        }
};

/*
Solution 2: inspired by this post --> https://leetcode.com/problems/convert-bst-to-greater-tree/discuss/100516/Java-Three-O(n)-Methods%3A-Recursive-Iterative-and-Morris-Traversal

Time complexity: O(n)
Space complexity: O(h)
*/
class Solution
{
    private:
        int sum;
    
    public:
        Solution()
        {
            sum=0;
        }
    
        TreeNode* convertBST(TreeNode* root)
        {
            if(root==nullptr)
            {
                return nullptr;
            }
            
            convertBST(root->right);
            
            int temp=root->val;
            
            root->val+=sum;
            
            sum+=temp;
            
            convertBST(root->left);
            
            return root;
        }
};

/*
Solution 3: inspired by this post --> https://leetcode.com/problems/convert-bst-to-greater-tree/discuss/100516/Java-Three-O(n)-Methods%3A-Recursive-Iterative-and-Morris-Traversal

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        TreeNode* convertBST(TreeNode* root)
        {
            if(root==nullptr)
            {
                return nullptr;
            }
            
            int sum=0;
            
            deque<TreeNode*> stack;
            
            TreeNode* node=root;
            
            while(!stack.empty() || node!=nullptr)
            {
                while(node!=nullptr)
                {
                    stack.emplace_back(node);
                    
                    node=node->right;
                }
                
                node=stack.back();
                
                stack.pop_back();
                
                int temp=node->val;
                
                node->val+=sum;
                
                sum+=temp;
                
                node=node->left;
            }
            
            return root;
        }
};