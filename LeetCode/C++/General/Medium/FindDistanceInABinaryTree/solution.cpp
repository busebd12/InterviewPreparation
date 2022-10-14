#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the number of nodes in the binary tree]
Space complexity: O(n)
*/

class Solution
{
    private:
        unordered_map<int, vector<int>> graph;
    
        unordered_set<int> visited;
    
    public:
        int findDistance(TreeNode* root, int p, int q)
        {
            int result=0;
            
            buildGraph(root);
            
            deque<int> queue;
            
            queue.push_back(p);
            
            visited.insert(p);
            
            bool done=false;
            
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    int current=queue.front();
                    
                    queue.pop_front();
                    
                    if(current==q)
                    {
                        done=true;
                        
                        break;
                    }
                    
                    for(int & neighbour : graph[current])
                    {
                        if(visited.find(neighbour)==end(visited))
                        {
                            visited.insert(neighbour);
                            
                            queue.push_back(neighbour);
                        }
                    }
                }
                
                if(done==true)
                {
                    break;
                }
                
                result+=1;
            }
            
            return result;
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
                    
                    if(node->left!=nullptr)
                    {
                        graph[node->left->val].emplace_back(node->val);
                        
                        graph[node->val].emplace_back(node->left->val);
                        
                        queue.emplace_back(node->left);
                    }
                    
                    if(node->right!=nullptr)
                    {
                        graph[node->right->val].emplace_back(node->val);
                        
                        graph[node->val].emplace_back(node->right->val);
                        
                        queue.emplace_back(node->right);
                    }
                }
            }
        }
};