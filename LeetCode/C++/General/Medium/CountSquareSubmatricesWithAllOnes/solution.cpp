#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/count-square-submatrices-with-all-ones/discuss/643565/DP-Visualization-of-the-Algorithm-and-Code-for-Count-Square-Submatrices-with-All-Ones

Time complexity: O(rows * columns) [where rows is the number of rows in the matrix and columns is the number of columns in the matrix]
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
                    if(row > 0 and column > 0 and matrix[row][column] > 0)
                    {
                        int minNeighbour=min(matrix[row - 1][column], min(matrix[row][column - 1], matrix[row - 1][column - 1]));
                        
                        matrix[row][column]+=minNeighbour;
                    }
                    
                    result+=matrix[row][column];
                }
            }
            
            return result;
        }
};