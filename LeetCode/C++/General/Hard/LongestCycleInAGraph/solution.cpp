#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
    public:
        int longestCycle(vector<int> & edges)
        {
            int result=-1;

            int n=edges.size();

            vector<vector<int>> graph(n, vector<int>());

            for(int u=0;u<n;u+=1)
            {
                int v=edges[u];

                if(v!=-1)
                {
                    graph[u].push_back(v);
                }
            }

            vector<bool> visited(n, false);

            for(int node=0;node<n;node+=1)
            {
                if(visited[node]==false)
                {
                    vector<int> path;

                    dfs(graph, path, visited, result, node);
                }
            }

            return result;
        }

        void dfs(vector<vector<int>> & graph, vector<int> & path, vector<bool> & visited, int & result, int node)
        {
            if(visited[node]==true)
            {
                int index=-1;

                for(int i=0;i<path.size();i+=1)
                {
                    if(path[i]==node)
                    {
                        index=i;

                        break;
                    }
                }

                if(index==-1)
                {
                    return;
                }

                int cycleLength=(path.size() - index);

                result=max(result, cycleLength);

                return;
            }

            visited[node]=true;

            path.push_back(node);

            for(int neighbour : graph[node])
            {
                dfs(graph, path, visited, result, neighbour);
            }
        }
};

class Solution
{
    public:
        int longestCycle(vector<int> & edges)
        {
            int result=-1;

            int n=edges.size();

            vector<bool> visited(n, false);

            for(int node=0;node<n;node+=1)
            {
                if(visited[node]==false)
                {
                    vector<int> path;

                    dfs(edges, path, visited, result, node);
                }
            }

            return result;
        }

        void dfs(vector<int> & edges, vector<int> & path, vector<bool> & visited, int & result, int node)
        {
            if(edges[node]==-1)
            {
                return;
            }
            
            if(visited[node]==true)
            {
                int index=-1;

                for(int i=0;i<path.size();i+=1)
                {
                    if(path[i]==node)
                    {
                        index=i;

                        break;
                    }
                }

                if(index==-1)
                {
                    return;
                }

                int cycleLength=(path.size() - index);

                result=max(result, cycleLength);

                return;
            }

            visited[node]=true;

            path.push_back(node);

            dfs(edges, path, visited, result, edges[node]);
        }
};