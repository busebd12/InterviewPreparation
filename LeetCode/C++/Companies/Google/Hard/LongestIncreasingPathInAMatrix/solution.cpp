#include <array>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

/*
First solution: brute force. Compute the longest increasing path for each number in the matrix that is not
equal to the maximum value in the matrix (since the maximum value will only have a chain of 1) using bread-first
search and the answer is the maximum of those values.

Time complexity: O((m * n) + O(v * (m * n)))
[where m is the number of matrix rows, n is the number of matrix columns, and v is the number of non-max values in the matrix]

Space complexity: O(m * n)
*/

class Solution
{
    public:
        int getMaxValue(vector<vector<int>> & matrix)
        {
            int maxValue=matrix[0][0];

            for(auto row : matrix)
            {
                for(auto number : row)
                {
                    maxValue=max(maxValue, number);
                }
            }

            return maxValue;
        }

        bool isOnGrid(int rows, int columns, int row, int column)
        {
            return ((row < rows && row >= 0) && (column < columns && column >= 0));
        }

        int bfs(vector<vector<int>> & matrix, int rows, int columns, int row, int column)
        {
            int increasingPath=-1;

            vector<vector<int>> cache(rows, vector<int>(columns, 1));

            queue<vector<int>> Q;

            vector<int> start={row, column, 1};

            Q.emplace(start);

            while(!Q.empty())
            {
                auto current=Q.front();

                Q.pop();

                int currentRow=current[0];

                int currentColumn=current[1];

                int currentIncreasingPath=current[2];

                increasingPath=max(increasingPath, currentIncreasingPath);

                array<pair<int, int>, 4> directions={{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};

                for(auto direction : directions)
                {
                    int nextRow=currentRow + direction.first;

                    int nextColumn=currentColumn + direction.second;

                    if(isOnGrid(rows, columns, nextRow, nextColumn))
                    {
                        if(matrix[nextRow][nextColumn] > matrix[currentRow][currentColumn] && currentIncreasingPath + 1 > cache[nextRow][nextColumn])
                        {

                            cache[nextRow][nextColumn]=currentIncreasingPath + 1;

                            vector<int> next={nextRow, nextColumn, currentIncreasingPath + 1};

                            Q.emplace(next);
                        }
                    }
                }
            }

            return increasingPath;
        }

        int longestIncreasingPath(vector<vector<int>> & matrix)
        {
            int rows=matrix.size();

            int columns=matrix[0].size();

            int result=-1;

            if(rows==1 && columns==1)
            {
                return 1;
            }

            int maxValue=getMaxValue(matrix);

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(matrix[row][column]!=maxValue)
                    {
                        int increasingPath=bfs(matrix, rows, columns, row, column);

                        result=max(result, increasingPath);
                    }
                }
            }

            return result;
        }
};

/*
Second solution: based on topological sort. If we view the matrix as an undirected graph, and each longest increasing
path through the matrix as a traversal of its nodes, then all the nodes in the matrix will have outdegrees greater than zero
except for the numbers in the matrix that are of maximum value. These nodes will have an outdegree of zero. Since we are trying
to form the longest increasing path, the numbers in the matrix that have maximum value will be at the ends of at least one of the
chains. So, the idea is to start from the leaf nodes (ends of the potentially longest increasing chain) and work backwards to the
beginning of the chain. See code comments for further details.

Time complexity: O(m * n) [where m is the number of matrix rows and n is the number of matrix columns]
Space complexity: O(m * n)
*/

class Solution
{
    public:
        bool isOnGrid(int rows, int columns, int row, int column)
        {
            return ((row < rows && row >= 0) && (column < columns && column >= 0));
        }

        int longestIncreasingPath(vector<vector<int>> & matrix)
        {
            int rows=matrix.size();
            
            int columns=matrix[0].size();
            
            int result=0;
            
            //Matrix to hold the outdegrees of each node
            vector<vector<int>> outdegree(rows, vector<int>(columns, 0));
            
            //Queue to hold all the leaf nodes
            queue<pair<int, int>> leaves;
            
            array<pair<int, int>, 4> directions={{{0, -1}, {0, 1}, {1, 0}, {-1, 0}}};
            
            //Iterate through the matrix and calculate the outdegree of each node
            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    for(auto direction : directions)
                    {
                        int nextRow=row + direction.first;
                        
                        int nextColumn=column + direction.second;
                        
                        if(isOnGrid(rows, columns, nextRow, nextColumn))
                        {
                            //If the the value of the adjacent node to the current node is greater, then the chain can extend from the current node to the adjacent one
                            //So, increment the outdegree of the current node
                            if(matrix[nextRow][nextColumn] > matrix[row][column])
                            {
                                outdegree[row][column]++;
                            }
                        }
                    }
                }
            }
            
            //Populate the queue with the first round of leaf nodes
            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(outdegree[row][column]==0)
                    {
                        leaves.emplace(make_pair(row, column));
                    }
                }
            }
            
            while(!leaves.empty())
            {
                int qSize=leaves.size();
                
                //Iterate through all the leaf nodes in this round/at this level
                for(int count=0;count<qSize;count++)
                {
                    auto current=leaves.front();
                    
                    int currentRow=current.first;
                    
                    int currentColumn=current.second;
                    
                    leaves.pop();
                    
                    for(auto direction : directions)
                    {
                        int nextRow=currentRow + direction.first;
                        
                        int nextColumn=currentColumn + direction.second;
                        
                        //If this node is within the bounds of the matrix, is smaller than the previous node in the chain (we are moving along the chain in reverse),
                        //and has an outdegree greater than zero (not a leaf node)
                        if(isOnGrid(rows, columns, nextRow, nextColumn) && matrix[nextRow][nextColumn] < matrix[currentRow][currentColumn] && outdegree[nextRow][nextColumn] > 0)
                        {
                            //Decrement the outdegree value for the current node
                            outdegree[nextRow][nextColumn]--;
                            
                            //If the new outdegree is zero, then the current node is a leaf node
                            if(outdegree[nextRow][nextColumn]==0)
                            {
                                //Add the leaf node to the queue
                                leaves.emplace(make_pair(nextRow, nextColumn));
                            }
                        }
                    }
                }
                
                result++;
            }
            
            return result;
        }
};