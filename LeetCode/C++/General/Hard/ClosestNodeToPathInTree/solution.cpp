#include <algorithm>
#include <deque>
#include <limits>
#include <vector>
using namespace std;

/*
Solution 1

Submission result: Time Limit Exceeded
*/

class Solution
{
    public:
        vector<int> closestNode(int n, vector<vector<int>> & edges, vector<vector<int>> & query)
        {
            vector<int> result;

            int q=query.size();

            result.resize(q, -1);

            vector<vector<int>> graph(n, vector<int>());

            //Build the undirected graph based on the given edges
            for(vector<int> & edge : edges)
            {
                int node1=edge[0];

                int node2=edge[1];

                graph[node1].push_back(node2);

                graph[node2].push_back(node1);
            }

            //Add the index of each query to each query
            for(int i=0;i<q;i++)
            {
                query[i].push_back(i);
            }

            //Iterate through each query
            for(vector<int> & q : query)
            {
                int source=q[0];

                int destination=q[1];

                int node=q[2];

                int index=q[3];

                deque<int> path;

                vector<bool> visited(n, false);

                //Generate the path from source node to destination node
                getPath(graph, path, visited, source, destination);

                path.push_front(source);

                int minDistance=numeric_limits<int>::max();

                //For each node in the path, find the distance between it and the target node given in the query
                for(int node2 : path)
                {
                    int distance=0;

                    vector<bool> visited2(n, false);

                    getDistance(graph, visited2, distance, node, node2);

                    if(distance < minDistance)
                    {
                        minDistance=distance;

                        result[index]=node2;
                    }
                }
            }

            return result;
        }

        bool getPath(vector<vector<int>> & graph, deque<int> & path, vector<bool> & visited, int source, int destination)
        {
            if(visited[source]==true)
            {
                return false;
            }

            visited[source]=true;

            if(source==destination)
            {
                return true;
            }

            for(int neighbour : graph[source])
            {
                if(getPath(graph, path, visited, neighbour, destination)==true)
                {
                    path.push_front(neighbour);
                    
                    return true;
                }
            }

            return false;
        }

        bool getDistance(vector<vector<int>> & graph, vector<bool> & visited, int & distance, int source, int destination)
        {
            if(visited[source]==true)
            {
                return false;
            }

            visited[source]=true;

            if(source==destination)
            {
                return true;
            }

            for(int neighbour : graph[source])
            {
                if(getDistance(graph, visited, distance, neighbour, destination)==true)
                {
                    distance+=1;
                    
                    return true;
                }
            }

            return false;
        }
};

/*
Solution 2:

Submission result: accepted.
*/

class Solution
{
    public:
        vector<int> closestNode(int n, vector<vector<int>> & edges, vector<vector<int>> & query)
        {
            vector<int> result;

            int q=query.size();

            result.resize(q, -1);

            vector<vector<int>> graph(n, vector<int>());

            //Build the undirected graph based on the given edges
            for(vector<int> & edge : edges) //O(e) [where e=number of edges]
            {
                int node1=edge[0];

                int node2=edge[1];

                graph[node1].push_back(node2);

                graph[node2].push_back(node1);
            }

            //Add the index of each query to each query
            for(int i=0;i<q;i++) //O(q) [where q=number of queries]
            {
                query[i].push_back(i);
            }

            //Iterate through each query
            for(vector<int> & q : query) //O(q) [where q=number of queries]
            {
                int source=q[0];

                int destination=q[1];

                int node=q[2];

                int index=q[3];

                deque<int> path;

                vector<bool> visited(n, false);

                //Generate the path from query source node to query destination node
                getPath(graph, path, visited, source, destination); //O(n) [where n=number of nodes in the graph]

                path.push_front(source);

                //Use breath-first search to calculate the distances from the query target node to every other node in the graph
                vector<int> distances=getDistances(graph, n, node); //O(n) [where n=number of nodes in the graph]

                int minDistance=numeric_limits<int>::max();

                //Iterate through all nodes in the path to find the closest node to the target query node
                for(int node2 : path) //O(p) [where p=number of nodes in the path]
                {
                    if(distances[node2] < minDistance)
                    {
                        minDistance=distances[node2];

                        result[index]=node2;
                    }
                }
            }

            return result;
        }

        bool getPath(vector<vector<int>> & graph, deque<int> & path, vector<bool> & visited, int source, int destination)
        {
            if(visited[source]==true)
            {
                return false;
            }

            visited[source]=true;

            if(source==destination)
            {
                return true;
            }

            for(int neighbour : graph[source])
            {
                if(getPath(graph, path, visited, neighbour, destination)==true)
                {
                    path.push_front(neighbour);
                    
                    return true;
                }
            }

            return false;
        }

        vector<int> getDistances(vector<vector<int>> & graph, int n, int source)
        {
            vector<int> distances(n, 0);

            vector<bool> visited(n, false);

            deque<int> queue;

            queue.push_back(source);

            int distance=0;

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    int node=queue.front();

                    queue.pop_front();

                    if(visited[node]==true)
                    {
                        continue;
                    }

                    distances[node]=distance;

                    visited[node]=true;

                    for(int neighbour : graph[node])
                    {
                        queue.push_back(neighbour);
                    }
                }

                distance+=1;
            }

            return distances;
        }
};