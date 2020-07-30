#include <iostream>
#include <queue>
#include <stack>
#include <vector>

/*
 * Solutions: all solutions inspired from this post --> https://leetcode.com/problems/number-of-operations-to-make-network-connected/discuss/717403/C%2B%2B-or-DFS-or-Number-of-Islands-or-Detailed-explanation
 *
 * 1. Recursion + Depth-first search
 *
 * Time complexity: O(V + E) [where V is the number of vertices and E is the number of edges in the graph]
 * Space complexity: O(V)
 *
 * 2. Iterative version of the first solution.
 *
 * Time complexity: O(V + E) [where V is the number of vertices and E is the number of edges in the graph]
 * Space complexity: O(V)
 *
 * 3. Breadth-first search approach.
 *
 * Time complexity: O(V + E) [where V is the number of vertices and E is the number of edges in the graph]
 * Space complexity: O(V)
 */

class Solution
{
    public:
        void dfs(std::vector<std::vector<int>> & graph, std::vector<bool> & visited, int node)
        {
            visited[node]=true;

            for(const auto & neighbour : graph[node])
            {
                if(!visited[neighbour])
                {
                    dfs(graph, visited, neighbour);
                }
            }
        }

        int makeConnected(int n, std::vector<std::vector<int>> & connections)
        {
            int connectedComponents=0;

            int c=int(connections.size());

            if(c < n-1)
            {
                return -1;
            }

            std::vector<std::vector<int>> graph(n, std::vector<int>());

            std::vector<bool> visited(n, false);

            for(const auto & connection : connections)
            {
                int a=connection[0];

                int b=connection[1];

                graph[a].emplace_back(b);

                graph[b].emplace_back(a);
            }

            for(int node=0;node<n;node++)
            {
                if(!visited[node])
                {
                    dfs(graph, visited, node);

                    connectedComponents++;
                }
            }

            return connectedComponents - 1;
        }
};


class Solution
{
    public:
        void dfs(std::vector<std::vector<int>> & graph, std::vector<bool> & visited, int node)
        {
            std::stack<int> stk;

            stk.push(node);

            visited[node]=true;

            while(!stk.empty())
            {
                auto currentNode=stk.top();

                stk.pop();

                for(const auto & neighbour : graph[currentNode])
                {
                    if(!visited[neighbour])
                    {
                        visited[neighbour]=true;

                        stk.push(neighbour);
                    }
                }
            }
        }

        int makeConnected(int n, std::vector<std::vector<int>> & connections)
        {
            int connectedComponents=0;

            int c=int(connections.size());

            if(c < n-1)
            {
                return -1;
            }

            std::vector<std::vector<int>> graph(n, std::vector<int>());

            std::vector<bool> visited(n, false);

            for(const auto & connection : connections)
            {
                int a=connection[0];

                int b=connection[1];

                graph[a].emplace_back(b);

                graph[b].emplace_back(a);
            }

            for(int node=0;node<n;node++)
            {
                if(!visited[node])
                {
                    dfs(graph, visited, node);

                    connectedComponents++;
                }
            }

            return connectedComponents - 1;
        }
};

class Solution
{
    public:
        void bfs(std::vector<std::vector<int>> & graph, std::vector<bool> & visited, int node)
        {
            std::queue<int> Q;

            Q.emplace(node);

            visited[node]=true;

            while(!Q.empty())
            {
                auto currentNode=Q.front();

                Q.pop();

                for(const auto & neighbour : graph[currentNode])
                {
                    if(!visited[neighbour])
                    {
                        visited[neighbour]=true;

                        Q.emplace(neighbour);
                    }
                }
            }
        }

        int makeConnected(int n, std::vector<std::vector<int>> & connections)
        {
            int connectedComponents=0;

            int c=int(connections.size());

            if(c < n-1)
            {
                return -1;
            }

            std::vector<std::vector<int>> graph(n, std::vector<int>());

            std::vector<bool> visited(n, false);

            for(const auto & connection : connections)
            {
                int a=connection[0];

                int b=connection[1];

                graph[a].emplace_back(b);

                graph[b].emplace_back(a);
            }

            for(int node=0;node<n;node++)
            {
                if(!visited[node])
                {
                    bfs(graph, visited, node);

                    connectedComponents++;
                }
            }

            return connectedComponents - 1;
        }
};