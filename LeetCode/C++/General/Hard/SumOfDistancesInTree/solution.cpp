#include <vector>
using namespace std;

/*
Solution: inspired by this video --> https://www.youtube.com/watch?v=OCGPug-KirQ

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    private:
        vector<vector<int>> graph;

        vector<int> nodesInSubtreeIncludingRoot;

        int sumOfDistancesFromZero=0;
    
    public:
        vector<int> sumOfDistancesInTree(int n, vector<vector<int>> & edges)
        {
            vector<int> result;

            result.resize(n, 0);
            
            buildGraph(edges, n);

            nodesInSubtreeIncludingRoot.resize(n, 0);

            int parent=-1;

            int current=0;

            int depth=0;

            countNodesInSubtrees(parent, current, depth);

            parent=-1;

            current=0;

            int dist=sumOfDistancesFromZero;

            calculateDistances(result, n, parent, current, dist);

            return result;
        }

        void buildGraph(vector<vector<int>> & edges, int n)
        {
            graph.resize(n, vector<int>());

            for(vector<int> edge : edges)
            {
                int u=edge[0];

                int v=edge[1];

                graph[u].push_back(v);

                graph[v].push_back(u);
            }
        }

        int countNodesInSubtrees(int parent, int current, int depth)
        {
            int nodesInSubtree=1;

            for(int child : graph[current])
            {
                if(child!=parent)
                {
                    nodesInSubtree+=countNodesInSubtrees(current, child, depth + 1);

                    sumOfDistancesFromZero+=(depth + 1);
                }
            }

            nodesInSubtreeIncludingRoot[current]=nodesInSubtree;

            return nodesInSubtree;
        }

        void calculateDistances(vector<int> & result, int n, int parent, int current, int dist)
        {
            result[current]=dist;

            for(int child : graph[current])
            {
                if(child!=parent)
                {
                    calculateDistances(result, n, current, child, dist + (n - nodesInSubtreeIncludingRoot[child]) - nodesInSubtreeIncludingRoot[child]);
                }
            }
        }
};