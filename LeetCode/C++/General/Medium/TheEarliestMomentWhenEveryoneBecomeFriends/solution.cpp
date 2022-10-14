#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution based off these materials on Disjoint Sets and Union-Find operations:

1. https://www.youtube.com/watch?v=wU6udHRIkcc&t=48s

2. https://www.techiedelight.com/union-find-algorithm-cycle-detection-graph/
*/

class Solution
{
    private:
        class DisjointSet
        {
            private:
                unordered_map<int, int> parent;
            
                int connectedComponents;
            
            public:
                DisjointSet(int n)
                {
                    this->connectedComponents=n;
                    
                    makeSet(n);
                }
            
                void makeSet(int n)
                {
                    for(int node=0;node<n;node++)
                    {
                        parent[node]=node;
                    }
                }
            
                int Find(int node)
                {
                    if(parent[node]==node)
                    {
                        return node;
                    }
                    
                    return Find(parent[node]);
                }
            
                bool Union(int node1, int node2)
                {
                    int node1Parent=Find(node1);
                    
                    int node2Parent=Find(node2);
                    
                    if(node1Parent!=node2Parent)
                    {
                        connectedComponents-=1;
                        
                        parent[node2Parent]=node1Parent;
                    }
                    
                    return connectedComponents==1;
                }
        };
    
    public:
        int earliestAcq(vector<vector<int>> & logs, int n)
        {
            int result=0;
            
            DisjointSet object(n);
            
            auto compareLikeThis=[] (vector<int> & lhs, vector<int> & rhs)
            {
                return lhs[0] < rhs[0];
            };
            
            sort(begin(logs), end(logs), compareLikeThis);
            
            for(vector<int> & log : logs)
            {
                if(object.Union(log[1], log[2])==true)
                {
                    return log[0];
                }
            }
            
            return -1;
        }
};

class Solution
{
    private:
        class DisjointSet
        {
            private:
                vector<int> parent;
            
                int connectedComponents;
            
            public:
                DisjointSet(int n)
                {
                    this->connectedComponents=n;
                    
                    parent.resize(n, 0);
                    
                    makeSet(n);
                }
            
                void makeSet(int n)
                {
                    for(int node=0;node<n;node++)
                    {
                        parent[node]=node;
                    }
                }
            
                int Find(int node)
                {
                    if(parent[node]==node)
                    {
                        return node;
                    }
                    
                    return Find(parent[node]);
                }
            
                bool Union(int node1, int node2)
                {
                    int node1Parent=Find(node1);
                    
                    int node2Parent=Find(node2);
                    
                    if(node1Parent!=node2Parent)
                    {
                        connectedComponents-=1;
                        
                        parent[node2Parent]=node1Parent;
                    }
                    
                    return connectedComponents==1;
                }
        };
    
    public:
        int earliestAcq(vector<vector<int>> & logs, int n)
        {
            int result=0;
            
            DisjointSet object(n);
            
            auto compareLikeThis=[] (vector<int> & lhs, vector<int> & rhs)
            {
                return lhs[0] < rhs[0];
            };
            
            sort(begin(logs), end(logs), compareLikeThis);
            
            for(vector<int> & log : logs)
            {
                if(object.Union(log[1], log[2])==true)
                {
                    return log[0];
                }
            }
            
            return -1;
        }
};