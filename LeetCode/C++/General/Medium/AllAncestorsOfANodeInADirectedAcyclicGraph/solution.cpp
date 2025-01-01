#include <deque>
#include <set>
#include <vecotr>
using namespace std;

/*
Time complexity: O(V + V + ((V + E) * log(V)) + (V * E))
Space complexity: O(V + E)
*/

class Solution
{
    public:
        vector<vector<int>> getAncestors(int n, vector<vector<int>> & edges)
        {
            vector<vector<int>> result(n, vector<int>());

            vector<vector<int>> graph(n, vector<int>());

            vector<int> indegree(n, 0);

            for(vector<int> edge : edges) //O(V)
            {
                int u=edge[0];

                int v=edge[1];

                graph[u].push_back(v);

                indegree[v]+=1;
            }

            deque<int> queue;

            for(int node=0;node<n;node++) //O(V)
            {
                if(indegree[node]==0)
                {
                    queue.push_back(node);
                }
            }

            vector<set<int>> uniqueAncestors(n, set<int>());

            while(!queue.empty()) //O((V + E) * log(V))
            {
                int ancestor=queue.front();

                queue.pop_front();

                for(int neighbour : graph[ancestor])
                {
                    uniqueAncestors[neighbour].insert(ancestor);

                    if(!uniqueAncestors[ancestor].empty())
                    {
                        for(int otherAncestor : uniqueAncestors[ancestor])
                        {
                            if(uniqueAncestors[neighbour].find(otherAncestor)==uniqueAncestors[neighbour].end())
                            {
                                uniqueAncestors[neighbour].insert(otherAncestor);
                            }
                        }
                    }

                    indegree[neighbour]-=1;

                    if(indegree[neighbour]==0)
                    {
                        queue.push_back(neighbour);
                    }
                }
            }

            for(int node=0;node<n;node++) //O(V)
            {
                if(!uniqueAncestors[node].empty())
                {
                    for(int ancestor : uniqueAncestors[node]) //O(E)
                    {
                        result[node].push_back(ancestor);
                    }
                }
            }

            return result;
        }
};