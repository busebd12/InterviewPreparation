#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>

/*
 * Solution: for each node in the undirected graph, use Dijkstra's algorithm to find all the cities within the given threshold distance.
 *
 * Time complexity: O(V * (E * V log V)) [where E is the number of edges and V is the number of vertices in the undirected graph]
 * Space complexity: O(V)
 */

class Solution
{
    public:
        int dijkstra(std::vector<std::vector<std::pair<int, int>>> & graph, int & n, int distanceThreshold, int startingNode)
        {
            int count=0;

            std::unordered_set<int> cities;

            std::vector<int> distances(n + 1, std::numeric_limits<int>::max());

            auto comparator=[] (const std::tuple<int, int, int> & t1, const std::tuple<int, int, int> & t2) {return std::get<0>(t1) > std::get<0>(t2);};

            std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, decltype(comparator)> minHeap(comparator);

            distances[startingNode]=0;

            minHeap.emplace(std::make_tuple(0, startingNode, distanceThreshold));

            while(!minHeap.empty())
            {
                int u=std::get<1>(minHeap.top());

                int remainingDistance=std::get<2>(minHeap.top());

                minHeap.pop();

                for(const auto & neighbour : graph[u])
                {
                    int v=neighbour.first;

                    int w=neighbour.second;

                    if(distances[u] + w < distances[v])
                    {
                        distances[v]=distances[u] + w;

                        if(w <= remainingDistance)
                        {
                            if(!cities.count(v))
                            {
                                cities.insert(v);

                                count++;
                            }

                            minHeap.emplace(std::make_tuple(distances[v], v, remainingDistance - w));
                        }
                    }
                }
            }

            return count;
        }

        int findTheCity(int n, std::vector<std::vector<int>> & edges, int distanceThreshold)
        {
            int result=-1;

            int totalCities=-1;

            std::vector<std::vector<std::pair<int, int>>> graph(n + 1, std::vector<std::pair<int, int>>());

            for(const auto & edge : edges)
            {
                int u=edge[0];

                int v=edge[1];

                int w=edge[2];

                graph[u].emplace_back(std::make_pair(v, w));

                graph[v].emplace_back(std::make_pair(u, w));
            }

            for(int node=0;node<n;node++)
            {
                if(result==-1)
                {
                    result=node;

                    totalCities=dijkstra(graph, n, distanceThreshold, node);
                }
                else
                {
                    int cities=dijkstra(graph, n, distanceThreshold, node);

                    if(cities < totalCities)
                    {
                        totalCities=cities;

                        result=node;
                    }
                    else if(cities==totalCities)
                    {
                        result=std::max(result, node);
                    }
                }
            }

            return result;
        }
};