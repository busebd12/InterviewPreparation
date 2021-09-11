#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

/*
 * Solutions:
 *
 * 1. Recursive Depth-First Search + std::unordered_map<int, std::vector<int>> to store the graph.
 *
 * Time complexity: O(V + E) [where V is the number of verticies and E is the number of edges]
 * Space complexity: O(V + E)
 *
 * 2. Recursive Depth-First Search + std::vector<std::vector<int>> to store the graph.
 *
 * Time complexity: O(V + E) [where V is the number of verticies and E is the number of edges]
 * Space complexity: O(V + E)
 *
 * 3. Iterative Depth-First Sear + std::unordered_map<int, std::vector<int>> to store the graph.
 *
 * Time complexity: O(V + E) [where V is the number of verticies and E is the number of edges]
 * Space complexity: O(V + E)
 *
 * 4. Iterative Depth-First Search + std::vector<std::vector<int>> to store the graph.
 *
 * Time complexity: O(V + E) [where V is the number of verticies and E is the number of edges]
 * Space complexity: O(V + E)
 *
 * 5. Bread-First Search + std::unordered_map<int, std::vector<int>> to store the graph.
 *
 * Time complexity: O(V + E) [where V is the number of verticies and E is the number of edges]
 * Space complexity: O(V + E)
 *
 * 6. Breadth-First Search + std::vector<std::vector<int>> to store the graph.
 *
 * Time complexity: O(V + E) [where V is the number of verticies and E is the number of edges]
 * Space complexity: O(V + E)
 */
void dfs(std::unordered_map<int, std::vector<int>> & graph, std::vector<bool> & visited, int vertex)
{
    visited[vertex]=true;

    for(const auto & neighbour : graph[vertex])
    {
        if(!visited[neighbour])
        {
            dfs(graph, visited, neighbour);
        }
    }
}

int countComponents(int n, std::vector<std::vector<int>> & edges)
{
    int connectedComponents=0;

    if(edges.empty())
    {
        return n;
    }

    if(n==0)
    {
        return connectedComponents;
    }

    std::vector<bool> visited(n, false);

    std::unordered_map<int, std::vector<int>> graph;

    for(const auto & edge : edges)
    {
        graph[edge[0]].emplace_back(edge[1]);

        graph[edge[1]].emplace_back(edge[0]);
    }

    for(int vertex=0;vertex<n;vertex++)
    {
        if(!visited[vertex])
        {
            dfs(graph, visited, vertex);

            connectedComponents++;
        }
    }

    return connectedComponents;
}

void dfs(std::vector<std::vector<int>> & graph, std::vector<bool> & visited, int vertex)
{
    visited[vertex]=true;

    for(const auto & neighbour : graph[vertex])
    {
        if(!visited[neighbour])
        {
            dfs(graph, visited, neighbour);
        }
    }
}

int countComponents(int n, std::vector<std::vector<int>> & edges)
{
    int connectedComponents=0;

    if(edges.empty())
    {
        return n;
    }

    if(n==0)
    {
        return connectedComponents;
    }

    std::vector<bool> visited(n, false);

    std::vector<std::vector<int>> graph(n, std::vector<int>());

    for(const auto & edge : edges)
    {
        graph[edge[0]].emplace_back(edge[1]);

        graph[edge[1]].emplace_back(edge[0]);
    }

    for(int vertex=0;vertex<n;vertex++)
    {
        if(!visited[vertex])
        {
            dfs(graph, visited, vertex);

            connectedComponents++;
        }
    }

    return connectedComponents;
}

void dfs(std::unordered_map<int, std::vector<int>> & graph, std::vector<bool> & visited, int vertex)
{
    std::stack<int> stk;

    stk.push(vertex);

    visited[vertex]=true;

    while(!stk.empty())
    {
        auto currentVertex=stk.top();

        stk.pop();

        for(const auto & neighbour : graph[currentVertex])
        {
            if(!visited[neighbour])
            {
                visited[neighbour]=true;

                stk.push(neighbour);
            }
        }
    }
}

int countComponents(int n, std::vector<std::vector<int>> & edges)
{
    int connectedComponents=0;

    if(edges.empty())
    {
        return n;
    }

    if(n==0)
    {
        return connectedComponents;
    }

    std::vector<bool> visited(n, false);

    std::unordered_map<int, std::vector<int>> graph;

    for(const auto & edge : edges)
    {
        graph[edge[0]].emplace_back(edge[1]);

        graph[edge[1]].emplace_back(edge[0]);
    }

    for(int vertex=0;vertex<n;vertex++)
    {
        if(!visited[vertex])
        {
            dfs(graph, visited, vertex);

            connectedComponents++;
        }
    }

    return connectedComponents;
}

void dfs(std::vector<std::vector<int>> & graph, std::vector<bool> & visited, int vertex)
{
    std::stack<int> stk;

    stk.push(vertex);

    visited[vertex]=true;

    while(!stk.empty())
    {
        auto currentVertex=stk.top();

        stk.pop();

        for(const auto & neighbour : graph[currentVertex])
        {
            if(!visited[neighbour])
            {
                visited[neighbour]=true;

                stk.push(neighbour);
            }
        }
    }
}

int countComponents(int n, std::vector<std::vector<int>> & edges)
{
    int connectedComponents=0;

    if(edges.empty())
    {
        return n;
    }

    if(n==0)
    {
        return connectedComponents;
    }

    std::vector<bool> visited(n, false);

    std::vector<std::vector<int>> graph(n, std::vector<int>());

    for(const auto & edge : edges)
    {
        graph[edge[0]].emplace_back(edge[1]);

        graph[edge[1]].emplace_back(edge[0]);
    }

    for(int vertex=0;vertex<n;vertex++)
    {
        if(!visited[vertex])
        {
            dfs(graph, visited, vertex);

            connectedComponents++;
        }
    }

    return connectedComponents;
}

void bfs(std::unordered_map<int, std::vector<int>> & graph, std::vector<bool> & visited, int vertex)
{
    std::queue<int> Q;

    Q.emplace(vertex);

    visited[vertex]=true;

    while(!Q.empty())
    {
        auto qSize=Q.size();

        for(auto count=0;count<qSize;count++)
        {
            auto currentVertex=Q.front();

            Q.pop();

            for(const auto & neighbour : graph[currentVertex])
            {
                if(!visited[neighbour])
                {
                    Q.emplace(neighbour);

                    visited[neighbour]=true;
                }
            }
        }
    }
}

int countComponents(int n, std::vector<std::vector<int>> & edges)
{
    int connectedComponents=0;

    if(edges.empty())
    {
        return n;
    }

    if(n==0)
    {
        return connectedComponents;
    }

    std::vector<bool> visited(n, false);

    std::unordered_map<int, std::vector<int>> graph;

    for(const auto & edge : edges)
    {
        graph[edge[0]].emplace_back(edge[1]);

        graph[edge[1]].emplace_back(edge[0]);
    }

    for(int vertex=0;vertex<n;vertex++)
    {
        if(!visited[vertex])
        {
            bfs(graph, visited, vertex);

            connectedComponents++;
        }
    }

    return connectedComponents;
}

void bfs(std::vector<std::vector<int>> & graph, std::vector<bool> & visited, int vertex)
{
    std::queue<int> Q;

    Q.emplace(vertex);

    visited[vertex]=true;

    while(!Q.empty())
    {
        auto qSize=Q.size();

        for(auto count=0;count<qSize;count++)
        {
            auto currentVertex=Q.front();

            Q.pop();

            for(const auto & neighbour : graph[currentVertex])
            {
                if(!visited[neighbour])
                {
                    Q.emplace(neighbour);

                    visited[neighbour]=true;
                }
            }
        }
    }
}

int countComponents(int n, std::vector<std::vector<int>> & edges)
{
    int connectedComponents=0;

    if(edges.empty())
    {
        return n;
    }

    if(n==0)
    {
        return connectedComponents;
    }

    std::vector<bool> visited(n, false);

    std::vector<std::vector<int>> graph(n, std::vector<int>());

    for(const auto & edge : edges)
    {
        graph[edge[0]].emplace_back(edge[1]);

        graph[edge[1]].emplace_back(edge[0]);
    }

    for(int vertex=0;vertex<n;vertex++)
    {
        if(!visited[vertex])
        {
            bfs(graph, visited, vertex);

            connectedComponents++;
        }
    }

    return connectedComponents;
}