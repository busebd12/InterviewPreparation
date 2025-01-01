#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

/*
Time complexity: O(rows * columns)
Space complexity: O(1)
*/

class Solution
{
    public:
        int minFallingPathSum(vector<vector<int>> & matrix)
        {
            int result=0;

            int rows=matrix.size();

            int columns=matrix[0].size();

            for(int row=1;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    //pathSum stores the path sum ending at matrix[row][column]
                    int pathSum=numeric_limits<int>::max();

                    //Calculuate the falling path sum coming down from the upper left diagonal
                    if(column - 1 >= 0)
                    {
                        int leftDiagonalSum=matrix[row][column] + matrix[row - 1][column - 1];

                        pathSum=min(pathSum, leftDiagonalSum);
                    }

                    //Calculate the falling path sum from the row directly above this one
                    int upSum=matrix[row][column] + matrix[row - 1][column];

                    pathSum=min(pathSum, upSum);

                    //Calculate the falling path sum coming down from the upper right diagonal
                    if(column + 1 < columns)
                    {
                        int rightDiagonalSum=matrix[row][column] + matrix[row - 1][column + 1];

                        pathSum=min(pathSum, rightDiagonalSum);
                    }

                    //Update the current spot with the minimum path sum out of the path sums coming down from the upper left, upper right, or the row directly above
                    matrix[row][column]=pathSum;
                }
            }

            //After iterating through the matrix, the minimum falling path sum is simply the minimum value in the last row
            result=*(min_element(matrix[rows - 1].begin(), matrix[rows - 1].end()));

            return result;
        }
};