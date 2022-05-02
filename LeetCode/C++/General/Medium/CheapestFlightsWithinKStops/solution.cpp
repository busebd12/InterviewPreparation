#include <deque>
#include <limits>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

/*
Solution 1: Breadth-first search. Inspired by this post --> https://leetcode.com/problems/cheapest-flights-within-k-stops/discuss/1925905/BFS-solution.-Beats-98-submissions!-Explanations-are-given.

Time complexity: O(V + E) [where V is the number of vertices and E is the number of edges in the graph]
Space complexity: O(V + V + E)
*/

class Solution
{
    public:
        int findCheapestPrice(int n, vector<vector<int>> & flights, int src, int dst, int k)
        {
            int result=numeric_limits<int>::max();
            
            unordered_map<int, vector<pair<int, int>>> graph;
            
            for(auto & flight : flights)
            {
                int source=flight[0];
                
                int destination=flight[1];
                
                int cost=flight[2];
                
                graph[source].emplace_back(destination, cost);
            }
            
            vector<int> costs(n, numeric_limits<int>::max());
            
            deque<tuple<int, int, int>> queue;
            
            queue.emplace_back(src, 0, 1);
            
            while(!queue.empty())
            {
                auto qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    auto [node, cost, stops]=queue.front();
                    
                    queue.pop_front();
                    
                    if(stops==k + 2)
                    {
                        continue;
                    }
                    
                    for(auto & [neighbour, weight] : graph[node])
                    {   
                        int nextCost=cost + weight;
                        
                        if(nextCost < costs[neighbour])
                        {
                            costs[neighbour]=nextCost;
                            
                            queue.emplace_back(neighbour, nextCost, stops + 1);
                        }
                    }
                }
            }
            
            return costs[dst]==numeric_limits<int>::max() ? -1 : costs[dst];
        }
};

/*
Solution 2: based on this post --> https://leetcode.com/problems/cheapest-flights-within-k-stops/discuss/662812/C%2B%2B-BFS-or-Bellman-Ford-Algo-or-Dijkstra-Algo

Time complexity: O(V * log(V) + E)
Space complexity: O(V + V + E)
*/

class Solution
{
    public:
        int findCheapestPrice(int n, vector<vector<int>> & flights, int src, int dst, int k)
        {
            int result=numeric_limits<int>::max();
            
            unordered_map<int, vector<pair<int, int>>> graph;
            
            for(auto & flight : flights)
            {
                int source=flight[0];
                
                int destination=flight[1];
                
                int cost=flight[2];
                
                graph[source].emplace_back(destination, cost);
            }
            
            vector<int> distances(n, numeric_limits<int>::max());
            
            auto compareLikeThis=[] (vector<int> & lhs, vector<int> & rhs)
            {
                return lhs[0] > rhs[0];
            };
            
            priority_queue<vector<int>, vector<vector<int>>, decltype(compareLikeThis)> minHeap(compareLikeThis);
            
            minHeap.emplace(vector<int>{0, src, 0});
            
            while(!minHeap.empty())
            {   
                auto current=minHeap.top();
                
                minHeap.pop();
                
                int currentCost=current[0];
                
                int currentNode=current[1];
                
                int currentStops=current[2];
                
                if(currentNode==dst)
                {
                    return currentCost;
                }
                
                if(currentStops > k)
                {
                    continue;
                }
                
                if(distances[currentNode] < currentStops)
                {
                    continue;
                }
                  
                distances[currentNode]=currentStops;

                for(auto & [neighbour, weight] : graph[currentNode])
                {   
                    minHeap.emplace(vector<int>{currentCost + weight, neighbour, currentStops + 1});
                }
            }
            
            return -1;
        }
};