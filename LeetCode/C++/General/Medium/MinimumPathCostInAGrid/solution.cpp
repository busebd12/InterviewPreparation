#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

/*
Solution 1: dynamic programming

Time complexity: O(rows * columns^2)
Space complexity: O(rows * columns)
*/

class Solution
{
    public:
        int minPathCost(vector<vector<int>> & grid, vector<vector<int>> & moveCost)
        {
            int result=0;

            int rows=grid.size();

            int columns=grid[0].size();

            vector<vector<int>> memo(rows, vector<int>(columns, 0));

            for(int row=1;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    //Stores the minimum cost to reach grid[row][column] from all columns in the row above the current one
                    int columnMinValue=numeric_limits<int>::max();

                    //Iterate through all the columns in the row above the current one
                    for(int c=0;c<columns;c++)
                    {
                        int index=grid[row - 1][c];

                        int weight=moveCost[index][column];

                        //IMPORTANT: DON'T FORGET to include the cost we stored in memo from the previous row of caclulations
                        //We want to re-use previously calculated values instead of calculating them all over again
                        //[Another tenant of dynamic programming :)]
                        int totalCost=index + weight + memo[row - 1][c];

                        //Update the min cost
                        columnMinValue=min(columnMinValue, totalCost);
                    }

                    //VERY IMPORTANT: Store min cost in memo table so that we can re-use it
                    //in the next row of calculations [this is the crux of dynamic programming :)]
                    memo[row][column]=columnMinValue;
                }
            }

            //Loop over the last row in memo to get the answer
            for(int column=0;column<columns;column++)
            {
                //IMPORTANT: DON'T FORGET to add in the actual value for grid[row - 1][column]
                //to the final path cost since the value of a cell is part of the path cost
                int pathCost=memo[rows - 1][column] + grid[rows - 1][column];

                if(result==0 or pathCost < result)
                {
                    result=pathCost;
                }
            }

            return result;
        }
};