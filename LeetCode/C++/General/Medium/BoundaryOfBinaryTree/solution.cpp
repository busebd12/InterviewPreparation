#include <deque>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n) [where n is the number of nodes in the binary tree]
Space complexity: O(h) [where h is the height of the binary tree]
*/

class Solution
{
    public:
        vector<int> boundaryOfBinaryTree(TreeNode* root)
        {
            vector<int> result;
            
            if(root==nullptr)
            {
                return result;
            }
            
            if(root->left==nullptr && root->right==nullptr)
            {
                result.emplace_back(root->val);
                
                return result;
            }
            
            deque<int> leftBoundary;
            
            //Get the left boundary
            if(root->left!=nullptr)
            {
                leftBoundary=getLeftBoundary(root->left);
            }
            
            deque<int> rightBoundary;
            
            //Get the right boundary
            if(root->right!=nullptr)
            {
                rightBoundary=getRightBoundary(root->right);
            }
            
            //Get the leaves
            deque<int> leaves=getLeaves(root);
            
            //Build boundary
            result.emplace_back(root->val);
            
            while(!leftBoundary.empty())
            {
                result.emplace_back(leftBoundary.front());
                
                leftBoundary.pop_front();
            }
            
            while(!leaves.empty())
            {
                result.emplace_back(leaves.front());
                
                leaves.pop_front();
            }
            
            //NOTE: we have to remove the right boundary nodes from the back of the deque to ensure that they are in reverse order
            while(!rightBoundary.empty())
            {
                result.emplace_back(rightBoundary.back());
                
                rightBoundary.pop_back();
            }
            
            return result;
        }
    
        deque<int> getLeftBoundary(TreeNode* leftSubtree)
        {
            deque<int> leftBoundary;
            
            deque<TreeNode*> queue;
            
            queue.emplace_back(leftSubtree);
            
            while(!queue.empty())
            {
                auto qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    auto node=queue.front();
                    
                    queue.pop_front();
                    
                    //If left child is nullptr
                    if(node->left==nullptr)
                    {
                        //If right child is not nullptr, then the right child is part of the left boundary
                        if(node->right!=nullptr)
                        {
                            queue.emplace_back(node->right);
                            
                            leftBoundary.emplace_back(node->val);
                        }
                    }
                    else
                    {
                        //If the left child is not null then the current node in the left subtree is not a leaf node and can be added to the left boundary
                        if(node->left!=nullptr)
                        {
                            leftBoundary.emplace_back(node->val);
                            
                            queue.emplace_back(node->left);
                        }
                    }
                }
            }
            
            return leftBoundary;
        }
    
        deque<int> getRightBoundary(TreeNode* rightSubtree)
        {
            deque<int> rightBoundary;
            
            deque<TreeNode*> queue;
            
            queue.emplace_back(rightSubtree);
            
            while(!queue.empty())
            {
                auto qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    auto node=queue.front();
                    
                    queue.pop_front();
                    
                    //If the right child is not nullptr, then the current node in the right subtree is not a leaf node and can be added to the right boundary
                    if(node->right!=nullptr)
                    {       
                        queue.emplace_back(node->right);
                        
                        rightBoundary.emplace_back(node->val);
                    }
                    else
                    {
                        //If the right child is nullptr, then if the left child is not nullptr, it can be included in the right boundary
                        if(node->left!=nullptr)
                        {
                            rightBoundary.emplace_back(node->val);
                            
                            queue.emplace_back(node->left);
                        }
                    }
                }
            }
            
            return rightBoundary;
        }
    
        deque<int> getLeaves(TreeNode* root)
        {
            deque<int> leaves;
            
            deque<TreeNode*> stack;
            
            TreeNode* current=root;
            
            //Do an in-order traversal of the tree to gather the leaves in the correct order
            while(!stack.empty() || current!=nullptr)
            {
                //Go as far left in the tree as you can
                while(current!=nullptr)
                {
                    stack.emplace_back(current);
                    
                    current=current->left;
                }
                
                current=stack.back();
                
                stack.pop_back();
                
                //If the current node is a leaf node
                if(current->left==nullptr && current->right==nullptr)
                {
                    leaves.emplace_back(current->val);
                }
                
                //Now, go right
                current=current->right;
            }
            
            return leaves;
        }
};