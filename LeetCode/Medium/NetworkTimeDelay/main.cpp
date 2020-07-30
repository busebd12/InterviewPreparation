#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

/*
 * Solutions:
 *
 * 1. Use Dijkstra's algorithm + min heap so that the neighbour of the current node which has the smallest
 * distance away from the current node is always at the top of the heap. See the following videos on Dijkstra's algorithm:
 * https://www.youtube.com/watch?v=XB4MIexjvY0 and https://www.youtube.com/watch?v=smHnz2RHJBY
 *
 * Time complexity: O(E + V * log(V)) [where E is the number of edges and V is the number of vertices in the graph]
 * Space complexity: O(V)
 *
 * 2. Use Bellman-Ford's algorithm. See the following video on Bellman-Ford's algorithm: https://www.youtube.com/watch?v=FtN3BYH2Zes
 *
 * Time complexity: O(V * E) [where V is the number of vertices and E is the number of edges]
 * Space complexity: O(V) [where V is the number of vertices]
 */

class Solution
{
    public:
        int networkDelayTime(std::vector<std::vector<int>> & times, int N, int K)
        {
            std::vector<std::vector<std::pair<int, int>>> graph(N + 1, std::vector<std::pair<int, int>>());

            for(const auto & time : times)
            {
                int u=time[0];

                int v=time[1];

                int w=time[2];

                graph[u].emplace_back(std::make_pair(v, w));
            }

            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;

            std::vector<int> distances(N + 1, std::numeric_limits<int>::max());

            distances[K]=0;

            minHeap.emplace(std::make_pair(0, K));

            while(!minHeap.empty())
            {
                int u=minHeap.top().second;

                minHeap.pop();

                for(auto & neighbour : graph[u])
                {
                    int v=neighbour.first;

                    int w=neighbour.second;

                    if(distances[u] + w < distances[v])
                    {
                        distances[v]=distances[u] + w;

                        minHeap.emplace(std::make_pair(distances[v], v));
                    }
                }
            }

            int result=*(std::max_element(distances.begin() + 1, distances.end()));

            return result==std::numeric_limits<int>::max() ? -1 : result;
        }
};


class Solution
{
    public:
        int networkDelayTime(vector<vector<int>> & times, int N, int K)
        {
            std::vector<int> distances(N + 1, std::numeric_limits<int>::max());

            distances[K]=0;

            for(int node=0;node<N;node++)
            {
                for(const auto & edge : times)
                {
                    int u=edge[0];

                    int v=edge[1];

                    int w=edge[2];

                    if(distances[u]!=std::numeric_limits<int>::max() && distances[v] > distances[u] + w)
                    {
                        distances[v]=distances[u] + w;
                    }
                }
            }

            int result=*(std::max_element(distances.begin() + 1, distances.end()));

            return result==std::numeric_limits<int>::max() ? -1 : result;
        }
};