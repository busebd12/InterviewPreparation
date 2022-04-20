#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: inspired from this post --> https://leetcode.com/problems/evaluate-division/discuss/985648/100-faster-C%2B%2B-solution-using-DFS

Time complexity: O(V + E) [where V is the number of vertices and E is the number of edges]
Space complexity: O(V + E)
*/

class Solution
{
    public:
        double dfs(unordered_map<string, vector<pair<string, double>>> & graph, unordered_set<string> & visitedNodes, string startingNode, string endingNode)
        {
            //If neither of the nodes exist in the graph, no evaluation possible
            if(!graph.count(startingNode) || !graph.count(endingNode))
            {   
                return -1.0;
            }
            
            //If startingNode equals endingNode, then we have reached the end of the traversal
            if(startingNode==endingNode)
            {   
                return 1.0;
            }
            
            //Mark the startingNode as visited to prevent an infinite loop
            visitedNodes.insert(startingNode);
            
            //Loop through all neighbours of the startingNode
            for(auto neighbour : graph[startingNode])
            {
                string node=neighbour.first;
                
                double weight=neighbour.second;
                
                //If we haven't visited this neighbour
                if(!visitedNodes.count(node))
                {
                    //Continue our dfs search with this neighbour node
                    double subproblem=dfs(graph, visitedNodes, node, endingNode);
                    
                    //If the dfs was successful and we found the endingNode
                    if(subproblem!=-1.0)
                    {   
                        return subproblem * weight;
                    }
                }
            }
            
            return -1.0;
        }
    
        vector<double> calcEquation(vector<vector<string>> & equations, vector<double> & values, vector<vector<string>> & queries)
        {
            vector<double> result;
            
            //Directed graph
            unordered_map<string, vector<pair<string, double>>> graph;
            
            int n=equations.size();
            
            for(int i=0;i<n;i++)
            {
                string node1=equations[i][0];
                
                string node2=equations[i][1];
                
                double weight=values[i];
                
                //The important thing to realize is that this is a graph problem and the two variables in the equation are nodes, and the result of the equation is the weight of the edge between the two nodes
                //For the equation a/b=2.0:
                //a/b=2.0 ---> the edge between node a and b has a weight of 2.0
                //b/a=1/2.0 ---> the edge between node b and a has a weight of 1/2.0
                
                //For the equation b/c=3.0:
                //b/c=3.0 ---> the edge btween node b and c has a weight of 3.0
                //c/b=1/3.0 ---> the edge between node c and b has a weight of 1/3.0
                
                //So, if our query is then a/c, how do we evaluate it?
                //Well, how do we connect node a and node c?
                //We have an edge connecting node a and b that has a weight of 2.0
                //We also have an edge connection node b and c that has a weight of 3.0
                //So, going from a to c looks like a---> b ---> c, which is just connecting the two existing edges. To get the value, just multiply the weights of the edges as we traverse (i.e. 2.0 * 3.0 = 6.0)

                graph[node1].emplace_back(node2, weight);
                
                graph[node2].emplace_back(node1, 1/weight);
            }
            
            for(auto query : queries)
            {   
                string startingNode=query[0];
                
                string endingNode=query[1];
                
                unordered_set<string> visitedNodes;
                
                double value=dfs(graph, visitedNodes, startingNode, endingNode);
                
                result.emplace_back(value);
            }
            
            return result;
        }
};