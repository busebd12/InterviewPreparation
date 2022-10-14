#include <vector>
using namespace std;

/*
Time complexity: O(V + E) [where V is the number of vertices in the graph and E is the number of edges]
Space complexity: O(V + E)
*/

class Solution
{
    private:
        vector<vector<int>> graph;
        
        vector<bool> visited;
    
    public:
        bool leadsToDestination(int n, vector<vector<int>> & edges, int source, int destination)
        {
            int e=edges.size();
            
            graph.resize(n, vector<int>());
            
            visited.resize(n, false);
            
            for(int i=0;i<e;i++)
            {
                int u=edges[i][0];
                
                int v=edges[i][1];
                
                graph[u].push_back(v);
            }
            
            return dfs(source, destination);
        }
    
        bool dfs(int source, int destination)
        {   
            if(visited[source]==true)
            {
                return false;
            }
            
            if(graph[source].empty())
            {
                return source==destination;
            }
            
            visited[source]=true;
            
            for(int child : graph[source])
            {
                if(dfs(child, destination)==false)
                {
                    return false;
                }
            }
            
            visited[source]=false;
            
            return true;
        }
};