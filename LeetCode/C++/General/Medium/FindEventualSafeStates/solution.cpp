#include <deque>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: topological sort starting from the safe sites and working backwards.

Time complexity: O(V + E)
Space complexity: O(V + E)
*/

class Solution
{
    public:
        vector<int> eventualSafeNodes(vector<vector<int>> & graph)
        {
            vector<int> result;

            int n=graph.size();

            unordered_map<int, vector<int>> hashmap;

            vector<bool> isSafe(n, false);

            vector<int> outdegree(n, 0);

            for(int from=0;from<n;from++)
            {
                if(!graph[from].empty())
                {
                    for(const int & to : graph[from])
                    {
                        if(hashmap.find(to)==hashmap.end())
                        {
                            hashmap.emplace(to, vector<int>());
                        }

                        hashmap[to].push_back(from);

                        outdegree[from]+=1;
                    }
                }
            }

            deque<int> queue;

            for(int vertex=0;vertex<n;vertex++)
            {
                if(outdegree[vertex]==0)
                {
                    queue.push_back(vertex);
                }
            }

            while(!queue.empty())
            {
                int node=queue.front();

                queue.pop_front();

                isSafe[node]=true;

                for(int neighbour : hashmap[node])
                {
                    outdegree[neighbour]-=1;

                    if(outdegree[neighbour]==0)
                    {
                        queue.push_back(neighbour);
                    }
                }
            }

            for(int vertex=0;vertex<n;vertex++)
            {
                if(isSafe[vertex]==true)
                {
                    result.push_back(vertex);
                }
            }

            return result;
        }
};