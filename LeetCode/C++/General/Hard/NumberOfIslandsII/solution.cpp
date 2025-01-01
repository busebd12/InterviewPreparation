#include <array>
#include <utility>
#include <vector>
using namespace std;

class UnionFind
{
    private:
        //The parent/root for each island
        vector<int> parent;

    public:
        UnionFind(int parents)
        {
            parent.resize(parents, -1);
        }

        bool doUnion(int node1, int node2)
        {   
            //Find the parent of the first island
            int node1Parent=find(node1);

            //Find the parent of the second island
            int node2Parent=find(node2);

            //If the parents of the two island are already the same, then we can't perform a union
            if(node1Parent==node2Parent)
            {
                return false;
            }

            //Make the parent of the node2 island the parent of node1 island
            //We are connecting the node2 island to the node1 island
            parent[node2Parent]=node1Parent;

            return true;
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

        vector<int> & getParent()
        {
            return parent;
        }
};

class Solution
{
    public:
        vector<int> numIslands2(int m, int n, vector<vector<int>> & positions)
        {
            vector<int> result;

            int p=positions.size();

            result.resize(p, 0);

            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

            int oneDGridSize=m * n;

            UnionFind uf(oneDGridSize);

            int islands=0;

            for(int i=0;i<p;i++)
            {
                int row=positions[i][0];

                int column=positions[i][1];

                //Convert the 2D grid [row][column] position to a 1D index
                int oneDGridIndex=(row * n) + column;

                //If the parent of the current position in the grid is not -1,
                //then this position is already part of an island, so the number of islands don't change
                if(uf.getParent()[oneDGridIndex]!=-1)
                {
                    result[i]=islands;

                    continue;
                }

                //Mark the parent of this position as itself
                //This means that we are assuming this position is its own island
                uf.getParent()[oneDGridIndex]=oneDGridIndex;

                //Increment the number of islands
                islands+=1;

                //Iterate through all the valid neighbours of the current position
                for(auto & [rowOffset, columnOffset] : directions)
                {
                    int neighbourRow=row + rowOffset;

                    int neighbourColumn=column + columnOffset;

                    bool isValid=((0 <= neighbourRow and neighbourRow < m) and (0 <= neighbourColumn and neighbourColumn < n));

                    //Convert the 2D grid neighbour index to a 1D index
                    int oneDGridNeighbourIndex=(neighbourRow * n) + neighbourColumn;

                    //If the neighbour is valid and the neighbour is already part of an island
                    if(isValid==true and uf.getParent()[oneDGridNeighbourIndex]!=-1)
                    {
                        //We try to union/combine the current position with its neighbour since both should be part of the same island
                        //If we are able to successfully union to two separate islands, then we need to decrement the number of islands
                        //since we now have one less island
                        if(uf.doUnion(oneDGridIndex, oneDGridNeighbourIndex)==true)
                        {
                            islands-=1;
                        }
                    }
                }

                result[i]=islands;
            }

            return result;
        }
};