#include <algorithm>
#include <deque>
using namespace std;

/*
Solution: see comments.

Time complexity: O(h + n) [where h is the height of the binary tree and n is the number of nodes in the binary tree]
Space complexity: O(h + n)
*/

class Solution
{
    public:
        bool isCompleteTree(TreeNode* root)
        {
            //Get the maximum level in the binary tree
            int maxLevel=getMaxLevel(root);
            
            int level=0;
            
            deque<TreeNode*> queue;
            
            queue.emplace_back(root);
            
            bool noMoreLeafNodesAllowed=false;
            
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                int nodesInLevel=pow(2, level);
                
                //Make sure that each level, except for the last one, has the appropriate number of nodes in the level
                if(qSize!=nodesInLevel)
                {
                    return false;
                }
                
                for(int count=0;count<qSize;count++)
                {
                    TreeNode* node=queue.front();
                    
                    queue.pop_front();
                    
                    //If we are at the second to last level in the tree
                    if(level==maxLevel-2)
                    {
                        //If there are no more leaf nodes allowed in the last level
                        if(noMoreLeafNodesAllowed==true)
                        {
                            //Check to make sure the current node doesn't have any children
                            if(node->left!=nullptr or node->right!=nullptr)
                            {
                                return false;
                            }
                        }
                        //Else, so far, all the leaf nodes in the last level are following the completeness properties for a binary tree
                        else
                        {
                            //If the current node does not have a left child
                            if(node->left==nullptr)
                            {
                                //Since all nodes in the last level have to be filled in from left-to-right,
                                //if a node in the second to last level doesn't have a left child, then it can't have a right child
                                if(node->right!=nullptr)
                                {
                                    return false;
                                }
                                //If a node in the second to last level doesn't have any children, then nodes to the right of this node can't have any children
                                else
                                {
                                    noMoreLeafNodesAllowed=true;
                                }
                            }
                            //If the current node in the second to last level does have a left child
                            else
                            {
                                //If it doesn't have a right child, then there can be no more leaf nodes to the right
                                //of this left child since all leaf nodes must be filled in from left-to-right in the last level
                                if(node->right==nullptr)
                                {
                                    noMoreLeafNodesAllowed=true;
                                }
                            }
                        }
                    }
                    //Else, we are not at the second-to-last level, so just add the child nodes to the queue as normal
                    else
                    {
                        if(node->left!=nullptr)
                        {
                            queue.emplace_back(node->left);
                        }
                        
                        if(node->right!=nullptr)
                        {
                            queue.emplace_back(node->right);
                        }
                    }
                }
                
                level+=1;
            }
            
            return true;
        }
    
        int getMaxLevel(TreeNode* root)
        {
            if(root==nullptr)
            {
                return 0;
            }
            
            int leftSubtreeHeight=getMaxLevel(root->left);
            
            int rightSubtreeHeight=getMaxLevel(root->right);
            
            return max(leftSubtreeHeight, rightSubtreeHeight) + 1;
        }
};