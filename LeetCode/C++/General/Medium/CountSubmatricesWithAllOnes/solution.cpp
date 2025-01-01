#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

/*
Solution: based on this video --> https://www.youtube.com/watch?v=8miqwSN3EFo
Submission result: accepted
Time complexity: O(rows^2 * columns)
Space complexity: O(rows * columns)
*/

class Solution
{
    public:
        int numSubmat(vector<vector<int>> & mat)
        {
            int result=0;

            int rows=mat.size();

            int columns=mat[0].size();

            vector<vector<int>> suffixMatrix=getSuffixMatrix(mat, rows, columns);

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(mat[row][column]==1)
                    {
                        getSubMatrices(suffixMatrix, result, rows, row, column);
                    }
                }
            }

            return result;
        }

        vector<vector<int>> getSuffixMatrix(vector<vector<int>> & mat, int rows, int columns)
        {
            vector<vector<int>> suffixMatrix(rows, vector<int>(columns, 0));

            for(int row=0;row<rows;row++)
            {
                suffixMatrix[row][columns - 1]=mat[row][columns - 1];

                for(int column=columns-2;column>=0;column--)
                {
                    if(mat[row][column]==1)
                    {
                        suffixMatrix[row][column]=(1 + suffixMatrix[row][column + 1]);
                    }
                }
            }

            return suffixMatrix;
        }

        void getSubMatrices(vector<vector<int>> & suffixMatrix, int & result, int rows, int row, int column)
        {
            int minLength=numeric_limits<int>::max();

            for(int r=row;r<rows;r++)
            {
                minLength=min(minLength, suffixMatrix[r][column]);

                result+=minLength;
            }
        }
};