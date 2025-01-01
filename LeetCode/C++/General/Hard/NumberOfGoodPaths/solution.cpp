#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: based on this video --> https://www.youtube.com/watch?v=d9G9u5zvMZs

Time complexity: O(n log n)
Space complexity: O(n)
*/

class DisjointSetUnion
{
    private:
        vector<int> parent;
    
    public:
        DisjointSetUnion()
        {

        }
        
        DisjointSetUnion(int n)
        {
            parent.resize(n, 0);

            for(int node=0;node<n;node++)
            {
                parent[node]=node;
            }
        }

        int find(int node)
        {
            if(parent[node]==node)
            {
                return node;
            }

            parent[node]=find(parent[node]);

            return parent[node];
        }

        void unions(int u, int v)
        {
            int uParent=find(u);

            int vParent=find(v);

            if(uParent==vParent)
            {
                return;
            }

            parent[vParent]=uParent;
        }
};

class Solution
{
    public:
        int numberOfGoodPaths(vector<int> & vals, vector<vector<int>> & edges)
        {
            int result=0;

            int n=vals.size();

            result+=n;

            if(edges.empty())
            {
                return result;
            }

            //Sort the edges in increasing order by the max value of the the two nodes in the edge
            sort(edges.begin(), edges.end(), [&vals] (vector<int> & lhsEdge, vector<int> & rhsEdge)
            {
                return max(vals[lhsEdge[0]], vals[lhsEdge[1]]) < max(vals[rhsEdge[0]], vals[rhsEdge[1]]);
            });

            //Keeps track of frequencies of node values in subtrees
            vector<unordered_map<int, int>> subtreeFrequencies(n);

            for(int node=0;node<n;node++)
            {
                subtreeFrequencies[node][vals[node]]=1;
            }

            DisjointSetUnion disjointSetUnion(n);

            for(vector<int> edge : edges)
            {
                int u=edge[0];

                int v=edge[1];

                int uVal=vals[u];

                int vVal=vals[v];

                //Max value between the node values in this edge
                int maxValue=max(uVal, vVal);

                int uParent=disjointSetUnion.find(u);

                int vParent=disjointSetUnion.find(v);

                //Merge/union the subtree contain u and the subtree containing v
                disjointSetUnion.unions(u, v);

                //The number of good paths between the subtree root at uParent and the subtree rooted at vParent
                int goodPaths=subtreeFrequencies[uParent][maxValue] * subtreeFrequencies[vParent][maxValue];

                result+=goodPaths;

                //Since we merged the subtree root at vParent into the subtree rooted at uParent,
                //the frequency of the max value  in the subtree rooted at vParent is added to
                //the frequency of the same max value in the subtree rooted at uParent since these two subtree were merged into one tree
                subtreeFrequencies[uParent][maxValue]+=subtreeFrequencies[vParent][maxValue];

                //Since the subtree rooted at vParent no longer exists, just set the frequency to 0
                subtreeFrequencies[vParent][maxValue]=0;
            }

            return result;
        }
};