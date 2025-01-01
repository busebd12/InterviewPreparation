#include <cmath>
#include <vector>
using namespace std;

/*
Time complexity: O(rows * columns)
Space complexity: O(1)
*/

class Solution
{
    public:
        int matrixScore(vector<vector<int>> & grid)
        {
            int result=0;

            int rows=grid.size();

            int columns=grid[0].size();

            for(int row=0;row<rows;row++)
            {
                //If a row starts with zero, flip this one to maximize the amount of leading ones
                //The more leading ones, the larger the value of the binary number
                if(grid[row][0]==0)
                {
                    flipRow(grid, rows, columns, row);
                }
            }

            //At this point, we have maximized the number of ones in rows, so we don't want to make any changes to the rows
            //So, all we can do is maximize the number of ones in columns
            for(int column=0;column<columns;column++)
            {
                int ones=countOnes(grid, rows, columns, column);

                int zeros=rows - ones;

                //We only want to flip a column if there is not a majority of ones in it
                if(zeros >= ones)
                {
                    flipColumn(grid, rows, columns, column);
                }
            }

            //Calculate the maximum decimal value froom the grid
            for(int row=0;row<rows;row++)
            {
                int rowValue=toDecimal(grid[row], columns);

                result+=rowValue;
            }

            return result;
        }

        void flipRow(vector<vector<int>> & grid, int rows, int columns, int row)
        {
            for(int column=0;column<columns;column++)
            {
                if(grid[row][column]==0)
                {
                    grid[row][column]=1;
                }
                else
                {
                    grid[row][column]=0;
                }
            }
        }

        int countOnes(vector<vector<int>> & grid, int rows, int columns, int column)
        {
            int ones=0;

            for(int row=0;row<rows;row++)
            {
                if(grid[row][column]==1)
                {
                    ones+=1;
                }
            }

            return ones;
        }

        void flipColumn(vector<vector<int>> & grid, int rows, int columns, int column)
        {
            for(int row=0;row<rows;row++)
            {
                if(grid[row][column]==0)
                {
                    grid[row][column]=1;
                }
                else
                {
                    grid[row][column]=0;
                }
            }
        }

        int toDecimal(vector<int> & binary, int columns)
        {
            int decimal=0;

            int exponent=0;

            for(int i=columns-1;i>=0;i--)
            {
                if(binary[i]==1)
                {
                    decimal+=pow(2, exponent);
                }

                exponent+=1;
            }

            return decimal;
        }
};