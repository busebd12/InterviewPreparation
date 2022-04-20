#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

/*
Time complexity: O(n + (n * log n)) [where n is the number of nodes in the Binary Search Tree]
Space complexity: O(n)
*/

class Solution
{
    private:
        vector<int> values;
    
        vector<TreeNode*> nodes;
    
    public:
        void recoverTree(TreeNode* root)
        {
            inOrderTraversal(root);
            
            doRecovery();
        }
    
        void inOrderTraversal(TreeNode* root)
        {
            TreeNode* node=root;
            
            deque<TreeNode*> stack;
            
            while(!stack.empty() || node!=nullptr)
            {
                while(node!=nullptr)
                {
                    stack.emplace_back(node);
                    
                    node=node->left;
                }
                
                node=stack.back();
                
                stack.pop_back();
                
                values.emplace_back(node->val);
                
                nodes.emplace_back(node);
                
                node=node->right;
            }
        }
    
        void doRecovery()
        {
            //Sort TreeNode values to get the correct ordering
            sort(begin(values), end(values));
            
            //Iterate through the sorted values and make the necessary swaps within the Binary Search Tree
            for(int index=0;index<values.size();index++)
            {
                nodes[index]->val=values[index];
            }
        }
};