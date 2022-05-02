#include <cmath>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Solution 1:

Inspired by these resources

Video --> https://www.youtube.com/watch?v=4ZlRH0eK-qQ

Post --> https://leetcode.com/problems/min-cost-to-connect-all-points/discuss/1235458/Easy-concise-Prim's-Algorithm-C%2B%2B-using-setpriority_queue

Time complexity: O(V^2 + (V * E * log(V)))
Space complexity: O(V + E + V)
*/

class Solution
{   
    public:
        int getManhattanDistance(vector<int> & point1, vector<int> & point2)
        {
            return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1]);
        }
    
        int minCostConnectPoints(vector<vector<int>> & points)
        {
            int result=0;
            
            int n=points.size();
            
            //Graph where each vertex is a point and the edge connecting two points has a weight of the Manhattan distance between the two points
            unordered_map<int, vector<pair<int, int>>> graph;
            
            for(int i=0;i<n;i++) //O(V^2)
            {
                for(int j=i+1;j<n;j++)
                {
                    int manhattanDistance=getManhattanDistance(points[i], points[j]);
                    
                    //Create edge connecting the points points[i] and points[j]
                    graph[i].emplace_back(j, manhattanDistance);
                    
                    //Create edge connecting the points points[j] and points[i]
                    graph[j].emplace_back(i, manhattanDistance);
                }
            }
            
            //Minimum heap of pairs where each pair is {Manhattan distance, vertex}
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

            //To keep track of whether or not we have visited a point
            vector<bool> visited(n, false); //O(V)
            
            //Start building the minimum spanning tree with vertex points[0]
            minHeap.emplace(0, 0);
            
            while(!minHeap.empty()) //O(V * E * log(V))
            {
                auto [manhattanDistance, vertex]=minHeap.top();
                
                minHeap.pop();
                
                //If we've already visited this vertex, then skip all its neighbouring vertices
                if(visited[vertex]==true)
                {
                    continue;
                }
                
                //Mark the current vertex as visited
                visited[vertex]=true;
                
                //Add the Manhattan distance to the result
                result+=manhattanDistance;
                
                //Iterate through all the neighbours of the current vertex
                for(auto & [neighbour, neighbourManhattanDistance] : graph[vertex]) //O(E)
                {
                    //If we haven't visited the neighbour
                    if(visited[neighbour]==false)
                    {
                        //Add the neighbour and manhattan distance to the minimum heap
                        minHeap.emplace(neighbourManhattanDistance, neighbour); //O(log(V))
                    }
                }
            }
            
            return result;
        }
};

/*
Solution 2: same as the first solution except that a vector<vector<pair<int, int>>> is used instead of an unordered_map<int, vector<pair<int, int>>>

Inspired by these resources

Video --> https://www.youtube.com/watch?v=4ZlRH0eK-qQ

Post --> https://leetcode.com/problems/min-cost-to-connect-all-points/discuss/1235458/Easy-concise-Prim's-Algorithm-C%2B%2B-using-setpriority_queue

Time complexity: O(V^2 + (V * E * log(V)))
Space complexity: O(V + E + V)
*/

class Solution
{   
    public:
        int getManhattanDistance(vector<int> & point1, vector<int> & point2)
        {
            return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1]);
        }
    
        int minCostConnectPoints(vector<vector<int>> & points)
        {
            int result=0;
            
            int n=points.size();
            
            //Graph where each vertex is a point and the edge connecting two points has a weight of the Manhattan distance between the two points
            vector<vector<pair<int, int>>> graph(n);
            
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    int manhattanDistance=getManhattanDistance(points[i], points[j]);
                    
                    //Create edge connecting the points points[i] and points[j]
                    graph[i].emplace_back(j, manhattanDistance);
                    
                    //Create edge connecting the points points[j] and points[i]
                    graph[j].emplace_back(i, manhattanDistance);
                }
            }
            
            //Minimum heap of pairs where each pair is {Manhattan distance, vertex}
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
            
            //To keep track of whether or not we have visited a point
            vector<bool> visited(n, false);
            
            //Start building the minimum spanning tree with vertex points[0]
            minHeap.emplace(0, 0);
            
            while(!minHeap.empty())
            {
                auto [manhattanDistance, vertex]=minHeap.top();
                
                minHeap.pop();
                
                //If we've already visited this vertex, then skip all its neighbouring vertices
                if(visited[vertex]==true)
                {
                    continue;
                }
                
                //Mark the current vertex as visited
                visited[vertex]=true;
                
                //Add the Manhattan distance to the result
                result+=manhattanDistance;
                
                //Iterate through all the neighbours of the current vertex
                for(auto & [neighbour, neighbourManhattanDistance] : graph[vertex])
                {
                    //If we haven't visited the neighbour
                    if(visited[neighbour]==false)
                    {
                        //Add the neighbour and manhattan distance to the minimum heap
                        minHeap.emplace(neighbourManhattanDistance, neighbour);
                    }
                }
            }
            
            return result;
        }
};