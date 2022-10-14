#include <algorithm>
#include <deque>
#include <map>
#include <tuple>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<vector<int>> verticalTraversal(TreeNode* root)
        {
            vector<vector<int>> result;
            
            map<int, vector<pair<int, int>>> hashmap;
            
            deque<tuple<TreeNode*, int, int>> queue;
            
            queue.emplace_back(root, 0, 0);
            
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    auto [node, row, column]=queue.front();
                    
                    queue.pop_front();
                    
                    if(hashmap.find(column)==end(hashmap))
                    {
                        hashmap.emplace(column, vector<pair<int, int>>());
                    }
                    
                    hashmap[column].emplace_back(row, node->val);
                    
                    if(node->left!=nullptr)
                    {
                        queue.emplace_back(node->left, row + 1, column - 1);
                    }
                    
                    if(node->right!=nullptr)
                    {
                        queue.emplace_back(node->right, row + 1, column + 1);
                    }
                }
            }
            
            auto compareLikeThis=[] (pair<int, int> & lhs, pair<int, int> & rhs)
            {
                if(lhs.first!=rhs.first)
                {
                    return lhs.first < rhs.first;
                }
                else
                {
                    return lhs.second < rhs.second;
                }
            };
            
            for(auto & [column, pairs] : hashmap)
            {
                vector<int> level;
                
                sort(begin(pairs), end(pairs), compareLikeThis);
                
                for(auto & [row, value] : pairs)
                {   
                    level.push_back(value);
                }
                
                result.push_back(level);
            }
            
            return result;
        }
};