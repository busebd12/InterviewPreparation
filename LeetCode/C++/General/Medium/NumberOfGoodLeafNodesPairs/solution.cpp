#include <unordered_map>
#include <unordered_multiset>
#include <vector>
using namespace std;

/*
Time complexity: O(n + l(n)) [where n is the total number of nodes in the binary tree and l is the total number of leaf nodes]
Space complexity: O(n + l)
*/

class Solution
{
    private:
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
    
        unordered_multiset<TreeNode*> leafNodes;
    
    public:
        int countPairs(TreeNode* root, int distance)
        {
            int result=0;
            
            //Build a graph mapping child nodes to parent nodes and parent nodes to child nodes
            buildGraph(root);
            
            //For each leaf node, do breadth-first traversal to see which other leaf nodes we can reach with a path of length <= distance
            for(TreeNode* leafNode : leafNodes)
            {
                unordered_set<TreeNode*> visited;
                
                visited.insert(leafNode);
                
                deque<TreeNode*> queue;
                
                queue.push_back(leafNode);
                
                int dist=0;
                
                bool done=false;
                
                while(!queue.empty())
                {
                    int qSize=queue.size();
                    
                    for(int count=0;count<qSize;count++)
                    {
                        TreeNode* current=queue.front();
                        
                        queue.pop_front();
                        
                        //If our path is longer than distance, stop the bread-first traversal
                        if(dist > distance)
                        {
                            done=true;
                            
                            break;
                        }
                        
                        //For each neighbour node connected to the current node
                        for(TreeNode* neighbour : graph[current])
                        {   
                            //If we haven't visited this node before
                            if(visited.find(neighbour)==end(visited))
                            {
                                visited.insert(neighbour);
                                
                                queue.push_back(neighbour);
                            }
                        }
                        
                        //If this node is a leaf node and is not the same leaf node we started the breadth-first traversal with
                        if(leafNodes.find(current)!=end(leafNodes) and current!=leafNode)
                        {
                            result+=1;
                        }
                    }
                    
                    if(done==true)
                    {
                        break;
                    }
                    
                    dist+=1;
                }
            }
            
            return result/2;
        }
    
        void buildGraph(TreeNode* root)
        {
            deque<TreeNode*> queue;
            
            queue.push_back(root);
            
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    TreeNode* node=queue.front();
                    
                    queue.pop_front();
                    
                    bool isLeafNode=true;
                    
                    if(node->left!=nullptr)
                    {
                        isLeafNode=false;
                        
                        //Map parent node to left child
                        graph[node].emplace_back(node->left);
                        
                        //Map left child to parent node
                        graph[node->left].emplace_back(node);
                        
                        queue.emplace_back(node->left);
                    }
                    
                    if(node->right!=nullptr)
                    {
                        isLeafNode=false;
                        
                        //Map parent node to right child
                        graph[node].emplace_back(node->right);
                        
                        //Map right child to parent node
                        graph[node->right].emplace_back(node);
                        
                        queue.emplace_back(node->right);
                    }
                    
                    if(isLeafNode==true)
                    {
                        leafNodes.insert(node);
                    }
                }
            }
        }
};