#include <deque>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<vector<int>> findLeaves(TreeNode* root)
        {
            vector<vector<int>> result;
            
            //Hashtable that maps each node to its outdegree - the number of child nodes it has
            unordered_map<TreeNode*, int> outdegreeMap;
            
            //Hashtable that maps each node to its parent
            unordered_map<TreeNode*, TreeNode*> childToParentMap;
            
            deque<TreeNode*> queue;
            
            queue.emplace_back(root);
            
            //Use level order traversal of the tree to create child-to-parent mappings and determine the outdegree of each node
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    auto node=queue.front();
                    
                    queue.pop_front();
                    
                    //If the node has no children, then its outdegree is zero
                    if(node->left==nullptr && node->right==nullptr)
                    {
                        outdegreeMap[node]=0;
                    }
                    //If the node only has a left child, the outdegree is one
                    else if(node->left!=nullptr && node->right==nullptr)
                    {
                        outdegreeMap[node]=1;
                        
                        //Create child to parent mapping
                        childToParentMap[node->left]=node;
                        
                        queue.emplace_back(node->left);
                    }
                    //If the node only has a right child, the outdegree is one
                    else if(node->left==nullptr && node->right!=nullptr)
                    {
                        outdegreeMap[node]=1;
                        
                        //Create child to parent mapping
                        childToParentMap[node->right]=node;
                        
                        queue.emplace_back(node->right);
                    }
                    //If the node has two children the outdegree is two
                    else
                    {
                        outdegreeMap[node]=2;
                        
                        //Create child to parent mapping
                        childToParentMap[node->left]=node;
                        
                        childToParentMap[node->right]=node;
                        
                        queue.emplace_back(node->left);
                        
                        queue.emplace_back(node->right);
                    }
                }
            }
            
            //At this point, the outdegree of each node has been determined.
            //We are now going to use topological sort to find the leaf nodes in the requested manner
            for(auto & [node, outdegree] : outdegreeMap)
            {
                //If the outdegree of a node is zero, then it is a leaf
                if(outdegree==0)
                {
                    queue.emplace_back(node);
                }
            }
            
            while(!queue.empty())
            {
                //List of the current level of leaf nodes
                vector<int> level;
                
                int qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    auto node=queue.front();
                    
                    queue.pop_front();
                    
                    level.emplace_back(node->val);
                    
                    //Need this check since the root node doesn't have a parent node
                    if(node!=root)
                    {
                        //Decrement the outdegree of the current node's parent
                        outdegreeMap[childToParentMap[node]]--;
                        
                        //If the outdegree of the current node's parent becomes zero, then it is part of the next level of leaf nodes
                        if(outdegreeMap[childToParentMap[node]]==0)
                        {
                            queue.emplace_back(childToParentMap[node]);
                        }
                    }
                }
                
                result.emplace_back(level);
            }
            
            return result;
        }
};