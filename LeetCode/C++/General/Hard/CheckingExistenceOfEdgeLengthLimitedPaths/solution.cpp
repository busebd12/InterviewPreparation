#include <algorithm>
#include <vector>
using namespace std;

/*
Solution 1: build graph + breadth-first search to find a path between the two vertices of each query

Submission result: Time Limit Exceeded.
*/

class Solution
{
    public:
        vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> & edgeList, vector<vector<int>> & queries)
        {
            vector<bool> result;

            int q=queries.size();

            result.resize(q, false);

            vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());

            for(vector<int> & edge : edgeList)
            {
                int u=edge[0];

                int v=edge[1];

                int edgeDistance=edge[2];

                graph[u].emplace_back(v, edgeDistance);

                graph[v].emplace_back(u, edgeDistance);
            }

            for(int i=0;i<q;i++)
            {
                int source=queries[i][0];

                int destination=queries[i][1];

                int limit=queries[i][2];

                if(bfs(graph, n, limit, source, destination)==true)
                {
                    result[i]=true;
                }
            }

            return result;
        }

        bool bfs(vector<vector<pair<int, int>>> & graph, int n, int limit, int source, int destination)
        {
            vector<int> visited(n, false);

            deque<int> queue;

            queue.push_back(source);

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

                    visited[node]=true;

                    if(node==destination)
                    {
                        return true;
                    }

                    for(auto & [neighbour, edgeDistance] : graph[node])
                    {
                        if(edgeDistance < limit)
                        {
                            queue.push_back(neighbour);
                        }
                    }
                }
            }

            return false;
        }
};

/*
Solution 2: Disjoint sets + Union-Find based on these posts

1) https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/solutions/978450/c-dsu-two-pointers/

2) https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/solutions/978453/c-union-find/

Time complexity: O((q * log(q)) + (e * log(e))) [where e=length of edgeList and q=length of queries]
Space complexity: O(n)
*/

class UnionFind
{
    private:
        vector<int> parent;

    public:
        UnionFind(int n)
        {
            parent.resize(n, 0);

            for(int node=0;node<n;node++)
            {
                parent[node]=node;
            }
        }
        int doFind(int node)
        {
            if(parent[node]==node)
            {
                return node;
            }

            return doFind(parent[node]);
        }
        void doUnion(int u, int v)
        {
            int uParent=doFind(u);

            int vParent=doFind(v);

            if(uParent==vParent)
            {
                return;
            }

            parent[vParent]=uParent;
        }
        bool isConnected(int u, int v)
        {
            int uParent=doFind(u);

            int vParent=doFind(v);

            return (uParent==vParent);
        }
};

class Solution
{
    public:
        vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> & edgeList, vector<vector<int>> & queries)
        {
            vector<bool> result;

            int q=queries.size();

            int e=edgeList.size();

            result.resize(q, false);

            for(int index=0;index<q;index++)
            {
                queries[index].push_back(index);
            }

            sort(edgeList.begin(), edgeList.end(), [] (const vector<int> & lhs, const vector<int> & rhs) {return lhs[2] < rhs[2];});

            sort(queries.begin(), queries.end(), [] (const vector<int> & lhs, const vector<int> & rhs) {return lhs[2] < rhs[2];});

            UnionFind uf(n);

            int i=0;

            for(vector<int> & query : queries)
            {
                int index=query[3];
                
                int limit=query[2];

                while(i < e and edgeList[i][2] < limit)
                {
                    uf.doUnion(edgeList[i][0], edgeList[i][1]);

                    i+=1;
                }

                int u=query[0];

                int v=query[1];

                if(uf.isConnected(u, v)==true)
                {   
                    result[index]=true;
                }
            }

            return result;
        }
};