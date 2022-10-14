#include <vector>
using namespace std;

/*
Time complexity: O(rows * columns)
Space complexity: O(rows * columns)
*/

class Solution
{
    public:
        vector<vector<int>> matrixBlockSum(vector<vector<int>> & mat, int k)
        {
            vector<vector<int>> result;

            int rows=mat.size();

            int columns=mat[0].size();

            result.resize(rows, vector<int>(columns, 0));

            vector<vector<int>> prefixSums=getPrefixSums(mat, rows, columns);

            for(int row=0;row<rows;row++)
            {
                int upperLeftRow=max(0, row - k);

                int bottomRightRow=min(row + k, rows - 1);
                
                for(int column=0;column<columns;column++)
                {
                    int upperLeftColumn=max(0, column - k);

                    int bottomRightColumn=min(column + k, columns - 1);

                    int blockSum=prefixSums[bottomRightRow][bottomRightColumn];

                    if(upperLeftRow > 0)
                    {
                        blockSum-=prefixSums[upperLeftRow - 1][bottomRightColumn];
                    }

                    if(upperLeftColumn > 0)
                    {
                        blockSum-=prefixSums[bottomRightRow][upperLeftColumn - 1];
                    }

                    if(upperLeftRow > 0 and upperLeftColumn > 0)
                    {
                        blockSum+=prefixSums[upperLeftRow - 1][upperLeftColumn - 1];
                    }

                    result[row][column]=blockSum;
                }
            }

            return result;
        }

        vector<vector<int>> getPrefixSums(vector<vector<int>> & mat, int rows, int columns)
        {
            vector<vector<int>> prefixSums(rows, vector<int>(columns, 0));

            prefixSums[0][0]=mat[0][0];

            for(int column=1;column<columns;column++)
            {
                prefixSums[0][column]=mat[0][column] + prefixSums[0][column - 1];
            }

            for(int row=1;row<rows;row++)
            {
                prefixSums[row][0]=mat[row][0] + prefixSums[row - 1][0];
            }

            for(int row=1;row<rows;row++)
            {
                for(int column=1;column<columns;column++)
                {
                    prefixSums[row][column]=mat[row][column] + prefixSums[row - 1][column] + prefixSums[row][column - 1] - prefixSums[row - 1][column - 1];
                }
            }

            return prefixSums;
        }
};