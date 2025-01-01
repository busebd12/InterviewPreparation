#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Time complexity: O(V + E) [where E is the number of edges and V is the number of vertices]
Space complexity: O(V + E)
*/

class Solution
{
    public:
        int closestMeetingNode(vector<int> & edges, int node1, int node2)
        {
            int result=-1;

            unordered_map<int, int> graph;

            int e=edges.size();

            //Build graph
            for(int u=0;u<e;u++)
            {
                int v=edges[u];

                graph.emplace(u, v);
            }

            int dist=numeric_limits<int>::max();

            vector<int> node1Distances(e, numeric_limits<int>::max());

            //Calculate distances to all other nodes from node1
            dfs(graph, node1Distances, e, node1);

            node1Distances[node1]=0;

            vector<int> node2Distances(e, numeric_limits<int>::max());

            //Calculate distances to all other nodes from node2
            dfs(graph, node2Distances, e, node2);

            node2Distances[node2]=0;

            for(int node=0;node<e;node++)
            {   
                int maxDistanceBetweenNodes=max(node1Distances[node], node2Distances[node]);

                if(maxDistanceBetweenNodes < dist)
                {
                    dist=maxDistanceBetweenNodes;

                    result=node;
                }
            }

            return result;
        }

        void dfs(unordered_map<int, int> & graph, vector<int> & distances, int e, int source)
        {
            int pathLength=0;
            
            distances[source]=0;

            vector<bool> visited(e, false);

            pathLength+=1;

            while(graph[source]!=-1 and visited[graph[source]]==false)
            {
                distances[graph[source]]=pathLength;

                visited[graph[source]]=true;

                source=graph[source];

                pathLength+=1;
            }
        }
};