#include <deque>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
    public:
        int findCircleNum(vector<vector<int>> & isConnected)
        {
            int result=0;
            
            int n=isConnected.size();
            
            unordered_map<int, vector<int>> graph;
            
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(isConnected[i][j]==1)
                    {
                        if(i==j)
                        {
                            if(graph.find(i)==end(graph))
                            {
                                graph.emplace(i, vector<int>());
                            
                                graph[i].push_back(j);
                            }
                        }
                        else
                        {
                            if(graph.find(i)==end(graph))
                            {
                                graph.emplace(i, vector<int>());
                            }
                            
                            graph[i].push_back(j);
                            
                            if(graph.find(j)==end(graph))
                            {
                                graph.emplace(j, vector<int>());
                            }
                            
                            graph[j].push_back(i);
                        }
                    }
                }
            }
            
            vector<bool> visited(n, false);
            
            for(int node=0;node<n;node++)
            {
                if(visited[node]==false)
                {
                    dfs(graph, visited, node);
                    
                    result+=1;
                }
            }
            
            return result;
        }
    
        void dfs(unordered_map<int, vector<int>> & graph, vector<bool> & visited, int node)
        {
            if(visited[node]==true)
            {
                return;
            }
            
            visited[node]=true;
            
            for(int & neighbour : graph[node])
            {
                dfs(graph, visited, neighbour);
            }
        }
};

class Solution
{
    public:
        int findCircleNum(vector<vector<int>> & isConnected)
        {
            int result=0;
            
            int n=isConnected.size();
            
            unordered_map<int, vector<int>> graph;
            
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(isConnected[i][j]==1)
                    {
                        if(i==j)
                        {
                            if(graph.find(i)==end(graph))
                            {
                                graph.emplace(i, vector<int>());
                            
                                graph[i].push_back(j);
                            }
                        }
                        else
                        {
                            if(graph.find(i)==end(graph))
                            {
                                graph.emplace(i, vector<int>());
                            }
                            
                            graph[i].push_back(j);
                            
                            if(graph.find(j)==end(graph))
                            {
                                graph.emplace(j, vector<int>());
                            }
                            
                            graph[j].push_back(i);
                        }
                    }
                }
            }
            
            vector<bool> visited(n, false);
            
            for(int node=0;node<n;node++)
            {
                if(visited[node]==false)
                {
                    dfs(graph, visited, node);
                    
                    result+=1;
                }
            }
            
            return result;
        }
    
        void dfs(unordered_map<int, vector<int>> & graph, vector<bool> & visited, int node)
        {
            deque<int> stack;
            
            stack.push_back(node);
            
            visited[node]=true;
            
            while(!stack.empty())
            {
                int current=stack.back();
                
                stack.pop_back();
                
                for(int & neighbour : graph[current])
                {
                    if(visited[neighbour]==false)
                    {
                        visited[neighbour]=true;
                        
                        stack.push_back(neighbour);
                    }
                }
            }
        }
};