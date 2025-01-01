#include <deque>
#include <utility>
#include <vector>
using namespace std;

/*
Time complexity: O(V + E) [where V is the number of vertices and E is the number of edges]
Space complexity: O(V + E)
*/

class Solution
{
    public:
        int treeDiameter(vector<vector<int>> & edges)
        {
            int result=0;

            int n=edges.size() + 1;

            vector<vector<int>> graph(n, vector<int>());

            for(const vector<int> & edge : edges)
            {
                int u=edge[0];

                int v=edge[1];

                graph[u].push_back(v);

                graph[v].push_back(u);
            }

            int source=0;

            //Find the distance to the farthest node from 0 in the graph - call it A
            pair<int, int> firstFarthestNode=bfs(graph, n, source);

            //Find the distance to the farthest node from node A - call it B
            pair<int, int> secondFarthestNode=bfs(graph, n, firstFarthestNode.first);

            //The diameter will be the distance between A and B
            int diameter=secondFarthestNode.second;

            result+=diameter;

            return result;
        }

        pair<int, int> bfs(vector<vector<int>> & graph, int n, int source)
        {
            int distance=0;

            int farthestNode=-1;
            
            vector<bool> visited(n, false);

            deque<int> queue;

            visited[source]=true;

            queue.push_back(source);

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    int node=queue.front();

                    queue.pop_front();

                    farthestNode=node;

                    for(const int & neighbour : graph[node])
                    {
                        if(visited[neighbour]==false)
                        {
                            visited[neighbour]=true;
                            
                            queue.push_back(neighbour);
                        }
                    }
                }

                distance+=1;
            }

            //We need to do distance - 1 because the diameter is the number of edges between nodes in the path,
            //not the nodes themselves. When you have n nodes in a path, there will be n-1 edges between the nodes.
            return make_pair(farthestNode, distance - 1);
        }
};