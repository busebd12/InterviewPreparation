#include <deque>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the number of nodes in the N-ary tree]
Space complexity: O(n)
*/

class Solution
{
    public:
        vector<vector<int>> levelOrder(Node* root)
        {
            vector<vector<int>> result;
            
            if(root==nullptr)
            {
                return result;
            }
            
            deque<Node*> queue;
            
            queue.push_back(root);
            
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                vector<int> level;
                
                for(int count=0;count<qSize;count++)
                {
                    Node* current=queue.front();
                    
                    queue.pop_front();
                    
                    level.push_back(current->val);
                    
                    for(Node* child : current->children)
                    {
                        queue.push_back(child);
                    }
                }
                
                result.push_back(level);
            }
            
            return result;
        }
};