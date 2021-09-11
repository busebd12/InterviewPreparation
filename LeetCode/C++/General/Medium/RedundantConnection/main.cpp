#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

/*
 * Solutions:
 *
 * 1. Recursion + Depth-first search. The idea is to build the graph edge-by-edge and if the edge we are trying to add,
 * would create a cycle by being a duplicate of a path that already exists in the graph, then we know that this edge
 * is the redundant edge.
 *
 * Time complexity: O(n^2) [where N is the number of edges]
 * Space complexity: O(n)
 *
 * 2. Iterative version of the first solution.
 *
 * Time complexity: O(n^2)
 * Space complexity: O(n)
 *
 * 3. Breadth-first search, iterative solution.
 *
 * Time complexity: O(n^2)
 * Space complexity: O(n)
 *
 * 4. Disjoint sets + union + find solution. Based on this video: https://www.youtube.com/watch?v=wU6udHRIkcc
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

class Solution
{
    public:
        bool hasPath(std::unordered_map<int, std::vector<int>> & graph, int node, int target, int parent)
        {
            if(node==target)
            {
                return true;
            }

            if(!graph.count(node))
            {
                return false;
            }

            for(const auto & neighbour : graph[node])
            {
                if(neighbour==parent)
                {
                    continue;
                }

                if(hasPath(graph, neighbour, target, node))
                {
                    return true;
                }
            }

            return false;
        }

        std::vector<int> findRedundantConnection(std::vector<std::vector<int>> & edges)
        {
            std::vector<int> result(2, -1);

            int n=int(edges.size());

            std::unordered_map<int, std::vector<int>> graph;

            for(const auto & edge : edges)
            {
                int u=edge[0];

                int v=edge[1];

                int parent=-1;

                if(hasPath(graph, u, v, parent))
                {
                    result[0]=u;

                    result[1]=v;
                }
                else
                {
                    graph[u].emplace_back(v);

                    graph[v].emplace_back(u);
                }
            }

            return result;
        }
};


class Solution
{
    public:
        bool hasPath(std::unordered_map<int, std::vector<int>> & graph, int node, int target, int parent)
        {
            std::stack<std::pair<int, int>> stk;

            stk.push(std::make_pair(node, parent));

            while(!stk.empty())
            {
                auto current=stk.top();

                stk.pop();

                if(current.first==target)
                {
                    return true;
                }

                if(!graph.count(current.first))
                {
                    continue;
                }

                for(const auto & neighbour : graph[current.first])
                {
                    if(neighbour==current.second)
                    {
                        continue;
                    }

                    stk.push(std::make_pair(neighbour, current.first));
                }
            }

            return false;
        }

        std::vector<int> findRedundantConnection(std::vector<std::vector<int>> & edges)
        {
            std::vector<int> result(2, -1);

            int n=int(edges.size());

            std::unordered_map<int, std::vector<int>> graph;

            for(const auto & edge : edges)
            {
                int u=edge[0];

                int v=edge[1];

                int parent=-1;

                if(hasPath(graph, u, v, parent))
                {
                    result[0]=u;

                    result[1]=v;
                }
                else
                {
                    graph[u].emplace_back(v);

                    graph[v].emplace_back(u);
                }
            }

            return result;
        }
};


class Solution
{
    public:
        bool hasPath(std::unordered_map<int, std::vector<int>> & graph, int node, int target, int parent)
        {
            std::queue<std::pair<int, int>> Q;

            Q.emplace(std::make_pair(node, parent));

            while(!Q.empty())
            {
                auto current=Q.front();

                Q.pop();

                if(current.first==target)
                {
                    return true;
                }

                if(!graph.count(current.first))
                {
                    continue;
                }

                for(const auto & neighbour : graph[current.first])
                {
                    if(neighbour==current.second)
                    {
                        continue;
                    }

                    Q.emplace(std::make_pair(neighbour, current.first));
                }
            }

            return false;
        }

        std::vector<int> findRedundantConnection(std::vector<std::vector<int>> & edges)
        {
            std::vector<int> result(2, -1);

            int n=int(edges.size());

            std::unordered_map<int, std::vector<int>> graph;

            for(const auto & edge : edges)
            {
                int u=edge[0];

                int v=edge[1];

                int parent=-1;

                if(hasPath(graph, u, v, parent))
                {
                    result[0]=u;

                    result[1]=v;
                }
                else
                {
                    graph[u].emplace_back(v);

                    graph[v].emplace_back(u);
                }
            }

            return result;
        }
};

class Solution
{
    public:
        int findParent(std::vector<int> & disjointSets, int node)
        {
            int parent=node;

            while(disjointSets[parent] > 0)
            {
                parent=disjointSets[parent];
            }

            return parent;
        }

        void doUnion(std::vector<int> & disjointSets, int node1, int node2)
        {
            int node1Parent=findParent(disjointSets, node1);

            int node2Parent=findParent(disjointSets, node2);

            if(node1Parent!=node2Parent)
            {
                disjointSets[node2Parent]=node1Parent;
            }
        }

        std::vector<int> findRedundantConnection(std::vector<std::vector<int>> & edges)
        {
            std::vector<int> result(2, -1);

            int n=int(edges.size());

            std::vector<int> disjointSets(n+1, -1);

            for(const auto & edge : edges)
            {
                int u=edge[0];

                int v=edge[1];

                int uParent=findParent(disjointSets, u);

                int vParent=findParent(disjointSets, v);

                if(uParent==vParent)
                {
                    result[0]=u;

                    result[1]=v;
                }
                else
                {
                    doUnion(disjointSets, u, v);
                }
            }

            return result;
        }
};