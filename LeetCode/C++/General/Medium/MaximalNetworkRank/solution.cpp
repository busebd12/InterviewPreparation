#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

/*
Time complexity: O(r + n^2) [where r is the length of roads and n is the number of cities]
Space complexity: O(n)
*/

class Solution
{
    public:
        int maximalNetworkRank(int n, vector<vector<int>> & roads)
        {
            int result=0;
            
            if(roads.empty())
            {
                return result;
            }
            
            //Used to store the indegree (the number of roads coming INto) of a city
            vector<int> indegree(n, 0);
            
            //Map each city to a list of other cities connected to it by roads
            vector<unordered_set<int>> graph(n, unordered_set<int>());
            
            //Iterate through the roads, build the graph, and calculate the indegree for each city
            for(vector<int> road : roads)
            {
                int cityA=road[0];
                
                int cityB=road[1];
                
                //Create the edge from city A to city B
                graph[cityA].insert(cityB);
                
                //Update the indegree for city A
                indegree[cityA]+=1;
                
                //Create the edge from city B to city A
                graph[cityB].insert(cityA);
                
                //Update the indegree for city B
                indegree[cityB]+=1;
            }
            
            //Iterate through all possible pairs of cities
            for(int cityA=0;cityA<n;cityA++)
            {
                for(int cityB=cityA + 1;cityB<n;cityB++)
                {
                    //Calculate the network rank for city A and city B
                    int networkRank=indegree[cityA] + indegree[cityB];
                    
                    //Check to see if there's a edge between city A and city B
                    bool cityAToCityB=graph[cityA].find(cityB)!=end(graph[cityA]);
                    
                    //Check to see if there's an edge between city B and city A
                    bool cityBToCityA=graph[cityB].find(cityA)!=end(graph[cityB]);
                    
                    //Remove any duplicate edges between the two cities
                    if(cityAToCityB==true or cityBToCityA==true)
                    {
                        networkRank-=1;
                    }
                    
                    //Update the result
                    result=max(result, networkRank);
                }
            }
            
            return result;
        }
};