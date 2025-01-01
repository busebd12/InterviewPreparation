#include <deque>
#include <vector>
using namespace std;

class Solution
{
    public:
        long long countPairs(int n, vector<vector<int>> & edges)
        {
            long long result=0;

            vector<vector<int>> graph(n, vector<int>());

            for(vector<int> & edge : edges)
            {
                int u=edge[0];

                int v=edge[1];

                graph[u].push_back(v);

                graph[v].push_back(u);
            }

            vector<bool> visited(n, false);

            deque<long long> connectedComponentSizes;

            long long total=0;

            long long connectedComponents=0;

            for(int node=0;node<n;node++)
            {
                if(visited[node]==false)
                {
                    long long nodes=0;
                    
                    countNodesInConnectedComponent(graph, visited, nodes, node);

                    connectedComponentSizes.push_back(nodes);

                    total+=nodes;

                    connectedComponents+=1;
                }
            }

            if(connectedComponents==1)
            {
                return result;
            }

            while(connectedComponentSizes.size() > 1)
            {
                long long componentSize=connectedComponentSizes.front();

                connectedComponentSizes.pop_front();

                long long pairs=componentSize * (total - componentSize);

                result+=pairs;

                total-=componentSize;
            }

            return result;
        }

        void countNodesInConnectedComponent(vector<vector<int>> & graph, vector<bool> & visited, long long & nodes, int node)
        {
            if(visited[node]==true)
            {
                return;
            }

            visited[node]=true;

            nodes+=1;

            for(int neighbour : graph[node])
            {
                countNodesInConnectedComponent(graph, visited, nodes, neighbour);
            }
        }
};

class Solution
{
    public:
        long long countPairs(int n, vector<vector<int>> & edges)
        {
            long long result=0;

            vector<vector<int>> graph(n, vector<int>());

            for(vector<int> & edge : edges)
            {
                int u=edge[0];

                int v=edge[1];

                graph[u].push_back(v);

                graph[v].push_back(u);
            }

            deque<long long> connectedComponentSizes;

            vector<bool> visited(n, false);

            long long total=0;

            long long connectedComponents=0;

            for(int node=0;node<n;node++)
            {
                if(visited[node]==false)
                {
                    long long nodes=0;
                    
                    countNodesInConnectedComponent(graph, visited, nodes, node);

                    connectedComponentSizes.push_back(nodes);

                    total+=nodes;

                    connectedComponents+=1;
                }
            }

            if(connectedComponents==1)
            {
                return result;
            }

            while(connectedComponentSizes.size() > 1)
            {
                long long componentSize=connectedComponentSizes.front();

                connectedComponentSizes.pop_front();

                long long pairs=componentSize * (total - componentSize);

                result+=pairs;

                total-=componentSize;
            }

            return result;
        }

        void countNodesInConnectedComponent(vector<vector<int>> & graph, vector<bool> & visited, long long & nodes, int node)
        {
            deque<int> stack;

            stack.push_back(node);

            while(!stack.empty())
            {
                int current=stack.back();

                stack.pop_back();

                if(visited[current]==true)
                {
                    continue;
                }

                visited[current]=true;

                nodes+=1;

                for(int neighbour : graph[current])
                {
                    stack.push_back(neighbour);
                }
            }
        }
};

class Solution
{
    public:
        long long countPairs(int n, vector<vector<int>> & edges)
        {
            long long result=0;

            vector<vector<int>> graph(n, vector<int>());

            for(vector<int> & edge : edges)
            {
                int u=edge[0];

                int v=edge[1];

                graph[u].push_back(v);

                graph[v].push_back(u);
            }

            deque<long long> connectedComponentSizes;

            vector<bool> visited(n, false);

            long long total=0;

            long long connectedComponents=0;

            for(int node=0;node<n;node++)
            {
                if(visited[node]==false)
                {
                    long long nodes=0;
                    
                    countNodesInConnectedComponent(graph, visited, nodes, node);

                    connectedComponentSizes.push_back(nodes);

                    total+=nodes;

                    connectedComponents+=1;
                }
            }

            if(connectedComponents==1)
            {
                return result;
            }

            while(connectedComponentSizes.size() > 1)
            {
                long long componentSize=connectedComponentSizes.front();

                connectedComponentSizes.pop_front();

                long long pairs=componentSize * (total - componentSize);

                result+=pairs;

                total-=componentSize;
            }

            return result;
        }

        void countNodesInConnectedComponent(vector<vector<int>> & graph, vector<bool> & visited, long long & nodes, int node)
        {
            deque<int> queue;

            queue.push_back(node);
            
            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    int current=queue.front();

                    queue.pop_front();

                    if(visited[current]==true)
                    {
                        continue;
                    }

                    visited[current]=true;

                    nodes+=1;

                    for(int neighbour : graph[current])
                    {
                        queue.push_back(neighbour);
                    }
                }
            }
        }
};