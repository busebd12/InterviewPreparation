#include <deque>
#include <vector>
using namespace std;

/*
Solution 1: Recursive depth-first search

Time complexity: O(n)
Space complexity: O(n) [recursive stack space]
*/

class Solution
{
    private:
        vector<vector<int>> graph;
    
    public:
        bool validPath(int n, vector<vector<int>> & edges, int source, int destination)
        {
            buildGraph(edges, n);

            vector<bool> visited(n, false);

            return helper(visited, source, destination);
        }

        void buildGraph(vector<vector<int>> & edges, int n)
        {
            graph.resize(n, vector<int>());

            for(vector<int> & edge : edges)
            {
                int u=edge[0];

                int v=edge[1];

                graph[u].push_back(v);

                graph[v].push_back(u);
            }
        }

        bool helper(vector<bool> & visited, int source, int destination)
        {
            if(visited[source]==true)
            {
                return false;
            }

            if(source==destination)
            {
                return true;
            }

            visited[source]=true;

            for(int neighbour : graph[source])
            {
                if(helper(visited, neighbour, destination)==true)
                {
                    return true;
                }
            }

            return false;
        }
};

/*
Solution 2: Iterative depth-first search

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    private:
        vector<vector<int>> graph;
    
    public:
        bool validPath(int n, vector<vector<int>> & edges, int source, int destination)
        {
            buildGraph(edges, n);

            vector<bool> visited(n, false);

            return helper(visited, source, destination);
        }

        void buildGraph(vector<vector<int>> & edges, int n)
        {
            graph.resize(n, vector<int>());

            for(vector<int> & edge : edges)
            {
                int u=edge[0];

                int v=edge[1];

                graph[u].push_back(v);

                graph[v].push_back(u);
            }
        }

        bool helper(vector<bool> & visited, int source, int destination)
        {
            deque<int> stack;

            stack.push_back(source);

            while(!stack.empty())
            {
                int node=stack.back();

                stack.pop_back();

                if(node==destination)
                {
                    return true;
                }

                if(visited[node]==true)
                {
                    continue;
                }

                visited[node]=true;

                for(int neighbour : graph[node])
                {
                    stack.push_back(neighbour);
                }
            }

            return false;
        }
};

/*
Solution 3: iterative breadth-first search

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    private:
        vector<vector<int>> graph;
    
    public:
        bool validPath(int n, vector<vector<int>> & edges, int source, int destination)
        {
            buildGraph(edges, n);

            vector<bool> visited(n, false);

            return helper(visited, source, destination);
        }

        void buildGraph(vector<vector<int>> & edges, int n)
        {
            graph.resize(n, vector<int>());

            for(vector<int> & edge : edges)
            {
                int u=edge[0];

                int v=edge[1];

                graph[u].push_back(v);

                graph[v].push_back(u);
            }
        }

        bool helper(vector<bool> & visited, int source, int destination)
        {
            deque<int> queue;

            queue.push_back(source);

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    int node=queue.front();

                    queue.pop_front();

                    if(node==destination)
                    {
                        return true;
                    }

                    if(visited[node]==true)
                    {
                        continue;
                    }

                    visited[node]=true;

                    for(int neighbour : graph[node])
                    {
                        queue.push_back(neighbour);
                    }
                }
            }

            return false;
        }
};