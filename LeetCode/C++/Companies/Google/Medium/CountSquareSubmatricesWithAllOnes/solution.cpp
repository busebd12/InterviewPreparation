#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

/*
Solution: inspired from this post --> https://leetcode.com/problems/count-square-submatrices-with-all-ones/discuss/643429/Python-DP-Solution-%2B-Thinking-Process-Diagrams-(O(mn)-runtime-O(1)-space)

Time complexity: O(m * n) [where m is the number of rows and n is the number of columns in the matrix]
Space complexity: O(1)
*/

class Solution
{
    public:
        int countSquares(vector<vector<int>> & matrix)
        {
            int result=0;

            int rows=matrix.size();

            int columns=matrix[0].size();

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(matrix[row][column]==1)
                    {
                        if(row==0 || column==0)
                        {
                            result++;
                        }
                        else
                        {
                            int cellValueBasedOnNeighbours=min({matrix[row - 1][column], matrix[row][column - 1], matrix[row - 1][column - 1]}) + matrix[row][column];

                            result+=cellValueBasedOnNeighbours;

                            matrix[row][column]=cellValueBasedOnNeighbours;
                        }
                    }
                }
            }

            return result;
        }
};