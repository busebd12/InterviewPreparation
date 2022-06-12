#include <deque>
using namespace std;

/*
Solution: get the depth of the binary tree and then do level order traversal to calculate the sum.

Time complexity: O(n) [where n is the number of nodes in the tree]
Space complexity: O(h + n) [where h is the height of the tree and n is the total number of nodes in the tree]
*/

class Solution
{
    public:
        int getTreeDepth(TreeNode* root)
        {
            if(root==nullptr)
            {
                return 0;
            }
            
            int leftSubtreeHeight=getTreeDepth(root->left);
            
            int rightSubtreeHeight=getTreeDepth(root->right);
            
            return 1 + max(leftSubtreeHeight, rightSubtreeHeight);
        }
    
        int deepestLeavesSum(TreeNode* root)
        {   
            int result=0;
            
            int deepestLevel=getTreeDepth(root);
            
            deque<TreeNode*> queue;
            
            queue.emplace_back(root);
            
            int level=1;
            
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    auto node=queue.front();
                    
                    queue.pop_front();
                    
                    if(level==deepestLevel)
                    {
                        result+=node->val;
                    }
                    
                    if(node->left!=nullptr)
                    {
                        queue.emplace_back(node->left);
                    }
                    
                    if(node->right!=nullptr)
                    {
                        queue.emplace_back(node->right);
                    }
                }
                
                level+=1;
            }
            
            return result;
        }
};