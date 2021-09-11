#include <iostream>
#include <queue>
#include <stack>
#include <vector>

/*
 * Solutions: all solutions inspired from this post --> https://leetcode.com/problems/possible-bipartition/discuss/654887/C%2B%2B-BFS-with-detailed-explanation
 *
 * 1. Recursive two-colour graph colouring.
 *
 * Time complexity: O(N + E) [where N is the number of nodes and E is the number of edges in the graph]
 * Space complexity: O(N)
 *
 * 2. Iterative version of the first solution.
 *
 * Time complexity: O(N + E) [where N is the number of nodes and E is the number of edges in the graph]
 * Space complexity: O(N)
 *
 * 3. Breadth-first search.
 *
 * Time complexity: O(N + E) [where N is the number of nodes and E is the number of edges in the graph]
 * Space complexity: O(N)
 */

class Solution
{
    public:
        bool dfs(std::vector<std::vector<int>> & graph, std::vector<int> & colours, int node, int colour)
        {
            if(colours[node]!=0)
            {
                if(colours[node]==colour)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }

            colours[node]=colour;

            for(const int & neighbour : graph[node])
            {
                if(!dfs(graph, colours, neighbour, -colour))
                {
                    return false;
                }
            }

            return true;
        }

        bool isBipartite(std::vector<std::vector<int>> & graph)
        {
            int n=int(graph.size());

            std::vector<int> colours(n, 0);

            for(int node=0;node<n;node++)
            {
                if(colours[node]==0)
                {
                    int startingColour=1;

                    if(!dfs(graph, colours, node, startingColour))
                    {
                        return false;
                    }
                }
            }

            return true;
        }
};


class Solution
{
    public:
        bool dfs(std::vector<std::vector<int>> & graph, std::vector<int> & colours, int node, int colour)
        {
            std::stack<int> stk;

            colours[node]=colour;

            stk.push(node);

            while(!stk.empty())
            {
                auto currentNode=stk.top();

                stk.pop();

                for(const auto & neighbour : graph[currentNode])
                {
                    if(colours[neighbour]==0)
                    {
                        if(colours[currentNode]==1)
                        {
                            colours[neighbour]=-1;
                        }
                        else
                        {
                            colours[neighbour]=1;
                        }

                        stk.push(neighbour);
                    }
                    else if(colours[currentNode]==colours[neighbour])
                    {
                        return false;
                    }
                }
            }

            return true;
        }

        bool isBipartite(std::vector<std::vector<int>> & graph)
        {
            int n=int(graph.size());

            std::vector<int> colours(n, 0);

            for(int node=0;node<n;node++)
            {
                if(colours[node]==0)
                {
                    int startingColour=1;

                    if(!dfs(graph, colours, node, startingColour))
                    {
                        return false;
                    }
                }
            }

            return true;
        }
};

class Solution
{
    public:
        bool bfs(std::vector<std::vector<int>> & graph, std::vector<int> & colours, int node, int colour)
        {
            std::queue<int> Q;

            colours[node]=colour;

            Q.emplace(node);

            while(!Q.empty())
            {
                auto currentNode=Q.front();

                Q.pop();

                for(const auto & neighbour : graph[currentNode])
                {
                    if(colours[neighbour]==0)
                    {
                        if(colours[currentNode]==1)
                        {
                            colours[neighbour]=-1;
                        }
                        else
                        {
                            colours[neighbour]=1;
                        }

                        Q.emplace(neighbour);
                    }
                    else if(colours[currentNode]==colours[neighbour])
                    {
                        return false;
                    }
                }
            }

            return true;
        }

        bool isBipartite(std::vector<std::vector<int>> & graph)
        {
            int n=int(graph.size());

            std::vector<int> colours(n, 0);

            for(int node=0;node<n;node++)
            {
                if(colours[node]==0)
                {
                    int startingColour=1;

                    if(!bfs(graph, colours, node, startingColour))
                    {
                        return false;
                    }
                }
            }

            return true;
        }
};