#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
using namespace std;

class Solution
{
    private:
        unordered_map<int, pair<bool, vector<int>>> graph;
    
        unordered_set<int> visited;
    
    public:
        int findClosestLeaf(TreeNode* root, int k)
        {
            int result=0;
            
            buildGraph(root);
            
            deque<int> queue;
            
            queue.emplace_back(k);
            
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                bool done=false;
                
                for(int count=0;count<qSize;count++)
                {
                    int nodeValue=queue.front();
                    
                    queue.pop_front();
                    
                    if(graph[nodeValue].first==true)
                    {
                        result=nodeValue;
                        
                        done=true;
                        
                        break;
                    }
                    
                    for(int child : graph[nodeValue].second)
                    {
                        if(visited.find(child)==end(visited))
                        {
                            visited.insert(child);
                            
                            queue.push_back(child);
                        }
                    }
                }
                
                if(done==true)
                {
                    break;
                }
            }
            
            return result;
        }
    
        void buildGraph(TreeNode* root)
        {
            deque<TreeNode*> nodeQueue;
            
            nodeQueue.emplace_back(root);
            
            while(!nodeQueue.empty())
            {
                int qSize=nodeQueue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    TreeNode* node=nodeQueue.front();
                    
                    nodeQueue.pop_front();
                    
                    if(graph.find(node->val)==end(graph))
                    {
                        graph.emplace(node->val, make_pair(true, vector<int>()));
                    }
                    
                    if(node->left!=nullptr)
                    {
                        if(graph.find(node->left->val)==end(graph))
                        {
                            graph.emplace(node->left->val, make_pair(true, vector<int>()));
                        }
                        
                        graph[node->val].second.emplace_back(node->left->val);
                        
                        graph[node->val].first=false;
                        
                        graph[node->left->val].second.emplace_back(node->val);
                        
                        nodeQueue.emplace_back(node->left);
                    }
                    
                    if(node->right!=nullptr)
                    {
                        if(graph.find(node->right->val)==end(graph))
                        {
                            graph.emplace(node->right->val, make_pair(true, vector<int>()));
                        }
                        
                        graph[node->val].second.emplace_back(node->right->val);
                        
                        graph[node->val].first=false;
                        
                        graph[node->right->val].second.emplace_back(node->val);
                        
                        nodeQueue.emplace_back(node->right);
                    }
                }
            }
        }
};