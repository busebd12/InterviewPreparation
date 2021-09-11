#include <cmath>
#include <iostream>
#include <vector>

/*
 * Solution: inspired from this video --> https://www.youtube.com/watch?v=CsGP_s_3GWg and this post --> https://leetcode.com/problems/critical-connections-in-a-network/discuss/550835/C%2B%2B-DFS-100sc-short
 *
 * Time complexity: O(V + E) [where V is the number of vertices in the graph and E is the number of edges]
 * Space complexity: O(E)
 */

void dfs(std::vector<std::vector<int>> & graph, std::vector<std::vector<int>> & bridges, std::vector<bool> & visited, std::vector<int> & timestamps, int parentVertex, int currentVertex, int timestamp)
{
    visited[currentVertex]=true;

    timestamps[currentVertex]=timestamp;

    for(const auto & child : graph[currentVertex])
    {
        if(child==parentVertex)
        {
            continue;
        }

        if(!visited[child])
        {
            dfs(graph, bridges, visited, timestamps, currentVertex, child, timestamp + 1);
        }

        timestamps[currentVertex]=std::min(timestamps[currentVertex], timestamps[child]);

        if(timestamp < timestamps[child])
        {
            std::vector<int> bridge{currentVertex, child};

            bridges.emplace_back(bridge);
        }
    }
}

std::vector<std::vector<int>> criticalConnections(int n, std::vector<std::vector<int>> & connections)
{
    std::vector<std::vector<int>> bridges;

    if(connections.empty() || n <= 0)
    {
        return bridges;
    }

    std::vector<std::vector<int>> graph(n, std::vector<int>());

    for(const auto & edges : connections)
    {
        graph[edges[0]].emplace_back(edges[1]);

        graph[edges[1]].emplace_back(edges[0]);
    }

    std::vector<bool> visited(n, false);

    std::vector<int> timestamps(n, 0);

    int startingVertex=0;

    int parentVertex=-1;

    int timestamp=1;

    dfs(graph, bridges, visited, timestamps, parentVertex, startingVertex, timestamp);

    return bridges;
}