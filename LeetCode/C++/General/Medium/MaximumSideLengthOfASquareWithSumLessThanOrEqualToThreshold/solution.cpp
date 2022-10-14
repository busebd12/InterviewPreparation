#include <algorithm>
#include <vector>
using namespace std;


/*
Solution: inspired by this post

1)https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/solutions/451891/complete-explanation-simple-java-o-min-n-m-n-m/

Time complexity: O(min(rows, columns) * rows * columns)
Space complexity: O(rows * columns)
*/

class Solution
{
    public:
        int maxSideLength(vector<vector<int>> & mat, int threshold)
        {
            int result=0;
            
            int rows=mat.size();

            int columns=mat[0].size();

            vector<vector<int>> prefixSums(rows, vector<int>(columns, 0));

            prefixSums[0][0]=mat[0][0];

            for(int column=1;column<columns;column++)
            {
                prefixSums[0][column]=prefixSums[0][column - 1] + mat[0][column];
            }

            for(int row=1;row<rows;row++)
            {
                prefixSums[row][0]=prefixSums[row - 1][0] + mat[row][0];
            }

            for(int row=1;row<rows;row++)
            {
                for(int column=1;column<columns;column++)
                {
                    int sum=mat[row][column] + prefixSums[row][column - 1] + prefixSums[row - 1][column] - prefixSums[row - 1][column - 1];
                    
                    prefixSums[row][column]=sum;
                }
            }

            int maxSideLength=min(rows, columns);

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    for(int sideLength=0;sideLength<maxSideLength;sideLength++)
                    {
                        int bottomRightRow=row + sideLength;

                        int bottomRightColumn=column + sideLength;

                        if(bottomRightRow >= rows or bottomRightColumn >= columns)
                        {
                            break;
                        }

                        int prefixSum=prefixSums[bottomRightRow][bottomRightColumn];

                        if(column - 1 >= 0)
                        {
                            prefixSum-=prefixSums[bottomRightRow][column - 1];
                        }

                        if(row - 1 >= 0)
                        {
                            prefixSum-=prefixSums[row - 1][bottomRightColumn];
                        }

                        if(row - 1 >= 0 and column - 1 >= 0)
                        {
                            prefixSum+=prefixSums[row - 1][column - 1];
                        }

                        if(prefixSum <= threshold)
                        {
                            result=max(result, sideLength + 1);
                        }
                    }
                }
            }

            return result;
        }
};