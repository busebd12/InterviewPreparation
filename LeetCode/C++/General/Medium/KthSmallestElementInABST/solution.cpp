#include <deque>
using namespace std;

/*
Solution: see comments.

Time complexity: O(k)
Space complexity: O(k)

*/

class Solution
{
    public:
        int kthSmallest(TreeNode* root, int k)
        {
            int result=0;
            
            deque<TreeNode*> stack;
            
            TreeNode* current=root;
            
            //Just do an in-order traversal of the Binary Search Tree and decrement k by one each time we remove a node from the stack.
            //When k reaches zero, we have found the kth smallest value in the tree.
            while(!stack.empty() || current!=nullptr)
            {
                while(current!=nullptr)
                {
                    stack.emplace_back(current);
                    
                    current=current->left;
                }
                
                current=stack.back();
                
                stack.pop_back();
                
                k-=1;
                
                if(k==0)
                {
                    result=current->val;
                    
                    break;
                }
                
                current=current->right;
            }
            
            return result;
        }
};