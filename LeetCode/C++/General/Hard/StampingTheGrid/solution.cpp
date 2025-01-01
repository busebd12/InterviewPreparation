#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(rows * columns) [where rows=rows in grid and columns=columns in grid]
Space complexity: O(rows * columns)
*/

class Solution
{
    public:
        bool possibleToStamp(vector<vector<int>> & grid, int stampHeight, int stampWidth)
        {
            int rows=grid.size();

            int columns=grid[0].size();

            vector<vector<int>> prefixSums=getPrefixSums(grid, rows, columns);

            //bottomRightCorners[row][column]==1 means that (row, column) is the bottom
            //right corner of an area of the grid that has the dimensions of stampHeight x stampWidth and is stampable
            vector<vector<int>> bottomRightCorners(rows, vector<int>(columns, 0));

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    //We want to make sure that (row, column) is a valid bottom right corner
                    if(row < stampHeight - 1 or column < stampWidth - 1)
                    {
                        continue;
                    }

                    //(row1, column1) is the top left corner of an area of the grid that has the dimensions of stampHeight x stampWidth and is stampable
                    
                    //Top left row
                    int row1=(row - stampHeight) + 1;

                    //Top left column
                    int column1=(column - stampWidth) + 1;

                    //Check the sum of grid cells in the potentially stampable region
                    //Region has top left cell (row1, column1) and bottom right cell (row, column)
                    int regionSum=getRegionSum(prefixSums, row1, column1, row, column);

                    //If the region sum is zero, then all the cells are empty and this region can be stamped
                    if(regionSum==0)
                    {   
                        //Mark the bottom right corner as 1 to show that it is the bottom right corner of a stampable region in the grid
                        bottomRightCorners[row][column]=1;
                    }
                }
            }

            //Get the 2D prefix sums grid for bottomRightCorners so that we can calculate the sum of cells in areas of the grid in O(1) time
            vector<vector<int>> bottomRightCornersPrefixSums=getPrefixSums(bottomRightCorners, rows, columns);

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    //Empty cell could be part of a stampable region
                    if(grid[row][column]==0)
                    {
                        //(row2, column2) is the bottom right corner of a potentially stampable region of the grid
                        //Note, we do min() row2 and column2 because stamps are allowed to overlap so we can consider
                        //regions of the grid that don't have dimensions exactly equal to stampHeight x stampWidth
                        int row2=min(row + stampHeight - 1, rows - 1);

                        int column2=min(column + stampWidth - 1, columns - 1);

                        //Calculate the sum of grid cells in the area with top left cell (row, column) and bottom right cell (row2, column2)
                        int regionSum=getRegionSum(bottomRightCornersPrefixSums, row, column, row2, column2);

                        //If the regionSum equals zero, then this region did not have a valid bottom right corner and can't be stamped
                        if(regionSum==0)
                        {
                            return false;
                        }
                    }
                }
            }

            return true;
        }

        vector<vector<int>> getPrefixSums(vector<vector<int>> & grid, int rows, int columns)
        {
            vector<vector<int>> prefixSums(rows, vector<int>(columns, 0));

            prefixSums[0][0]=grid[0][0];

            for(int row=1;row<rows;row++)
            {
                prefixSums[row][0]=prefixSums[row - 1][0] + grid[row][0];
            }

            for(int column=1;column<columns;column++)
            {
                prefixSums[0][column]=prefixSums[0][column - 1] + grid[0][column];
            }

            for(int row=1;row<rows;row++)
            {
                for(int column=1;column<columns;column++)
                {
                    int sum=grid[row][column] + prefixSums[row - 1][column] + prefixSums[row][column - 1] - prefixSums[row - 1][column - 1];

                    prefixSums[row][column]=sum;
                }
            }

            return prefixSums;
        }

        int getRegionSum(vector<vector<int>> & matrix, int row1, int column1, int row2, int column2)
        {
            int sum=matrix[row2][column2];

            if(column1 - 1 >= 0)
            {
                sum-=matrix[row2][column1 - 1];
            }

            if(row1 - 1 >= 0)
            {
                sum-=matrix[row1 - 1][column2];
            }

            if(row1 - 1 >= 0 and column1 - 1 >= 0)
            {
                sum+=matrix[row1 - 1][column1 - 1];
            }


            return sum;
        }
};