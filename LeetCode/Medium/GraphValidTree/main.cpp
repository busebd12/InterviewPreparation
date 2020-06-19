#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

/*
 * Solutions:
 *
 * 1. Recursion + DFS. In order for an undirected graph to be a valid tree the graph must be connected and acyclic.
 * We use depth-first search to check for a cycle. If there is a cyle, then the graph is not a valid tree. If there
 * is no cycle, we have to make sure that all the vertices were visited. If not, then it is not a valid tree.
 *
 * Time complexity: O(V + E)
 * Space complexity: O(V + E)
 *
 * 2. Iterative DFS version of the first solution.
 *
 * Time complexity: O(V + E)
 * Space complexity: O(V + E)
 *
 * 3. Breadth-first search version of the first solution.
 *
 * Time complexity: O(V + E)
 * Space complexity: O(V + E)
 */

bool dfs(std::unordered_map<int, std::vector<int>> & graph, std::vector<bool> & visited, int parent, int node)
{
    visited[node]=true;

    for(const auto & neighbour : graph[node])
    {
        if(!visited[neighbour])
        {
            if(!dfs(graph, visited, node, neighbour))
            {
                return false;
            }
        }
        else
        {
            if(neighbour!=parent)
            {
                return false;
            }
        }
    }

    return true;
}

bool validTree(int n, std::vector<std::vector<int>> & edges)
{
    if(edges.empty() && n > 1)
    {
        return false;
    }

    std::unordered_map<int, std::vector<int>> graph;

    for(const auto & edge : edges)
    {
        graph[edge[0]].emplace_back(edge[1]);

        graph[edge[1]].emplace_back(edge[0]);
    }

    std::vector<bool> visited(n, false);

    int parent=-1;

    int node=0;

    bool isTree=dfs(graph, visited, parent, node);

    for(int vertex=0;vertex<n&&isTree;vertex++)
    {
        if(!visited[vertex])
        {
            isTree=false;

            break;
        }
    }

    return isTree;
}

bool dfs(std::unordered_map<int, std::vector<int>> & graph, std::vector<bool> & visited, int parent, int node)
{
    std::stack<std::pair<int, int>> stk;

    stk.push(std::make_pair(parent, node));

    visited[node]=true;

    while(!stk.empty())
    {
        auto current=stk.top();

        stk.pop();

        for(const auto & neighbour : graph[current.second])
        {
            if(!visited[neighbour])
            {
                visited[neighbour]=true;

                stk.push(std::make_pair(current.second, neighbour));
            }
            else
            {
                if(neighbour!=current.first)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

bool validTree(int n, std::vector<std::vector<int>> & edges)
{
    if(edges.empty() && n > 1)
    {
        return false;
    }

    std::unordered_map<int, std::vector<int>> graph;

    for(const auto & edge : edges)
    {
        graph[edge[0]].emplace_back(edge[1]);

        graph[edge[1]].emplace_back(edge[0]);
    }

    std::vector<bool> visited(n, false);

    int parent=-1;

    int node=0;

    bool isTree=dfs(graph, visited, parent, node);

    for(int vertex=0;vertex<n&&isTree;vertex++)
    {
        if(!visited[vertex])
        {
            isTree=false;

            break;
        }
    }

    return isTree;
}

bool bfs(std::unordered_map<int, std::vector<int>> & graph, std::vector<bool> & visited, int parent, int node)
{
    std::queue<std::pair<int, int>> Q;

    Q.emplace(std::make_pair(parent, node));

    visited[node]=true;

    while(!Q.empty())
    {
        auto current=Q.front();

        Q.pop();

        for(const auto & neighbour : graph[current.second])
        {
            if(!visited[neighbour])
            {
                visited[neighbour]=true;

                Q.emplace(std::make_pair(current.second, neighbour));
            }
            else
            {
                if(neighbour!=current.first)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

bool validTree(int n, std::vector<std::vector<int>> & edges)
{
    if(edges.empty() && n > 1)
    {
        return false;
    }

    std::unordered_map<int, std::vector<int>> graph;

    for(const auto & edge : edges)
    {
        graph[edge[0]].emplace_back(edge[1]);

        graph[edge[1]].emplace_back(edge[0]);
    }

    std::vector<bool> visited(n, false);

    int parent=-1;

    int node=0;

    bool isTree=bfs(graph, visited, parent, node);

    for(int vertex=0;vertex<n&&isTree;vertex++)
    {
        if(!visited[vertex])
        {
            isTree=false;

            break;
        }
    }

    return isTree;
}