#include "../TreeNode.h"
#include <deque>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<int> inorderTraversal(TreeNode* root)
        {
            vector<int> result;
            
            inOrderTraversal(root, result);
            
            return result;
        }
    
        void inOrderTraversal(TreeNode* root, vector<int> & result)
        {
            if(root==nullptr)
            {
                return;
            }
            
            inOrderTraversal(root->left, result);
            
            result.emplace_back(root->val);
            
            inOrderTraversal(root->right, result);
        }
};

class Solution
{
    public:
        vector<int> inorderTraversal(TreeNode* root)
        {
            vector<int> result;
            
            inOrderTraversal(root, result);
            
            return result;
        }
    
        void inOrderTraversal(TreeNode* root, vector<int> & result)
        {
            if(root==nullptr)
            {
                return;
            }
            
            deque<TreeNode*> stack;
            
            TreeNode* current=root;
            
            while(!stack.empty() or current!=nullptr)
            {
                while(current!=nullptr)
                {
                    stack.emplace_back(current);
                    
                    current=current->left;
                }
                
                current=stack.back();
                
                stack.pop_back();
                
                result.emplace_back(current->val);
                
                current=current->right;
            }
        }
};