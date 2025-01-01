#include <vector>
using namespace std;

class Solution
{
    public:
        vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> & edges)
        {
            vector<int> result;

            vector<int> indegree(n, 0);

            for(vector<int> & edge : edges)
            {
                int u=edge[0];

                int v=edge[1];
                
                indegree[v]+=1;
            }

            for(int vertex=0;vertex<n;vertex+=1)
            {
                if(indegree[vertex]==0)
                {
                    result.push_back(vertex);
                }
            }

            return result;
        }
};