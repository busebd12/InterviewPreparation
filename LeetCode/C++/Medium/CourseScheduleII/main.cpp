#include <iostream>
#include <queue>
#include <stack>
#include <vector>

/*
 * Solutions:
 *
 * 1. Topological sorting - Khan's algorithm. See this page --> https://en.wikipedia.org/wiki/Topological_sorting#Kahn's_algorithm
 *
 * Time complexity: O(V + E) [where V is the number of vertices and E is the number of edges]
 * Space complexity: O(V + E)
 *
 * 2. Topological sorting - depth first search. See this page --> https://en.wikipedia.org/wiki/Topological_sorting#Depth-first_search
 *
 * Time complexity: O(V + E) [where V is the number of vertices and E is the number of edges]
 * Space complexity: O(V + E)
 *
 * 3. Iterative version of the second solution.
 *
 * Time complexity: O(V + E) [where V is the number of vertices and E is the number of edges]
 * Space complexity: O(V + E)
*/

std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>> & prerequisites)
{
    std::vector<int> result;

    std::vector<std::vector<int>> graph(numCourses, std::vector<int>());

    std::vector<int> indegrees(numCourses, 0);

    for(const auto & element : prerequisites)
    {
        graph[element[1]].emplace_back(element[0]);

        indegrees[element[0]]++;
    }

    std::queue<int> Q;

    for(auto vertex=0;vertex<numCourses;++vertex)
    {
        if(!indegrees[vertex])
        {
            Q.emplace(vertex);
        }
    }

    while(!Q.empty())
    {
        auto vertex=Q.front();

        result.emplace_back(vertex);

        Q.pop();

        numCourses--;

        for(const auto & neighbour : graph[vertex])
        {
            indegrees[neighbour]--;

            if(!indegrees[neighbour])
            {
                Q.emplace(neighbour);
            }
        }
    }

    if(numCourses > 0)
    {
        result.clear();
    }

    return result;
}

bool dfs(const std::vector<std::vector<int>> & graph, std::vector<int> & visited, std::vector<int> & result, int vertex)
{
    if(visited[vertex])
    {
        return visited[vertex]==2;
    }

    visited[vertex]=1;

    for(const auto & neighbour : graph[vertex])
    {
        if(!dfs(graph, visited, result, neighbour))
        {
            return false;
        }
    }

    visited[vertex]=2;

    result.emplace_back(vertex);

    return true;
}


std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>> & prerequisites)
{
    std::vector<int> result;

    std::vector<std::vector<int>> graph(numCourses, std::vector<int>());

    for(const auto & element : prerequisites)
    {
        graph[element[1]].emplace_back(element[0]);
    }

    std::vector<int> visited(numCourses, 0);

    for(auto vertex=0;vertex<numCourses;++vertex)
    {
        if(!visited[vertex])
        {
            if(!dfs(graph, visited, result, vertex))
            {
                break;
            }
        }
    }

    if(static_cast<int>(result.size()) < numCourses)
    {
        result.clear();
    }
    else
    {
        std::reverse(result.begin(), result.end());
    }

    return result;
}

std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>> & prerequisites)
{
    std::vector<int> result;

    std::vector<std::vector<int>> graph(numCourses, std::vector<int>());

    std::vector<int> visited(numCourses, 0);

    for(const auto & element : prerequisites)
    {
        graph[element[1]].emplace_back(element[0]);
    }

    for(auto vertex=0;vertex<numCourses;++vertex)
    {
        if(!visited[vertex])
        {
            bool cycle=false;

            std::stack<int> stk;

            stk.push(vertex);

            while(!stk.empty())
            {
                auto current=stk.top();

                if(!visited[current] || visited[current]==1)
                {
                    if(!visited[current])
                    {
                        visited[current]=1;
                    }

                    int neighboursAdded=0;

                    for(const auto & neighbour : graph[current])
                    {
                        if(visited[neighbour]==1)
                        {
                            cycle=true;

                            break;
                        }
                        else if(visited[neighbour]==2)
                        {
                            continue;
                        }
                        else
                        {
                            stk.push(neighbour);

                            neighboursAdded++;
                        }
                    }

                    if(cycle)
                    {
                        break;
                    }

                    if(!neighboursAdded)
                    {
                        visited[current]=2;

                        result.emplace_back(current);

                        stk.pop();
                    }
                }
                else
                {

                    stk.pop();
                }
            }
        }
    }

    if(static_cast<int>(result.size()) < numCourses)
    {
        result.clear();
    }
    else
    {
        std::reverse(result.begin(), result.end());
    }

    return result;
}