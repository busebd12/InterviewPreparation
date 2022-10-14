#include <algorithm>
#include <deque>
#include <limits>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

/*
Inspired by this post --> https://leetcode.com/problems/shortest-path-with-alternating-colors/discuss/1370454/Easy-C%2B%2B-BFS-solution-oror-commented-oror-93-faster
*/

class Solution
{
    public:
        vector<int> shortestAlternatingPaths(int n, vector<vector<int>> & redEdges, vector<vector<int>> & blueEdges)
        {
            vector<int> result(n, -1);
            
            unordered_map<int, vector<int>> redGraph;
            
            for(vector<int> & edge : redEdges)
            {
                int a=edge[0];
                
                int b=edge[1];
                
                redGraph[a].emplace_back(b);
            }
            
            unordered_map<int, vector<int>> blueGraph;
            
            for(vector<int> & edge : blueEdges)
            {
                int u=edge[0];
                
                int v=edge[1];
                
                blueGraph[u].emplace_back(v);
            }
            
            //Each pair represents the distance to reach a node from an incoming blue or red edge
            vector<pair<int, int>> distances(n, pair<int, int>(numeric_limits<int>::max(), numeric_limits<int>::max()));
            
            //pair.first will hold distances for red edges
            distances[0].first=0;
            
            //pair.second will hold distances for blue edges
            distances[0].second=0;
            
            //queue of pairs - each pair is {node, color}
            deque<pair<int, int>> queue;
            
            //Start from 0; 1 means red
            queue.emplace_back(0, 1);
            
            //Start from 0; -1 means blue
            queue.emplace_back(0, -1);
            
            int currentDistance=0;
            
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    auto [node, currentColor]=queue.front();
                    
                    queue.pop_front();
                    
                    //Last edge in the path was red, so we need to check the blue graph for the next edge
                    if(currentColor==1)
                    {
                        for(int & neighbour : blueGraph[node])
                        {
                            if(distances[neighbour].second > currentDistance + 1)
                            {
                                distances[neighbour].second=currentDistance + 1;
                                
                                queue.emplace_back(neighbour, -1);
                            }
                        }
                    }
                    //Else, the last edge in the path was blue, so we need to check the red graph for the next edge
                    else
                    {
                        for(int & neighbour : redGraph[node])
                        {
                            if(distances[neighbour].first > currentDistance + 1)
                            {
                                distances[neighbour].first=currentDistance + 1;
                                
                                queue.emplace_back(neighbour, 1);
                            }
                        }
                    }
                }
                
                currentDistance+=1;
            }
            
            for(int node=0;node<n;node++)
            {
                int length=min(distances[node].first, distances[node].second);
                
                if(length!=numeric_limits<int>::max())
                {
                    result[node]=length;
                }
            }
            
            return result;
        }
};