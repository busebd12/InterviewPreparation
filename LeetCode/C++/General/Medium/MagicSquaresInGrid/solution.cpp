#include <vector>
using namespace std;

/*
Solution: brute-force - just check all the conditions for each 3x3 square within the grid

Time complexity: O(rows * columns * k^2) [where k=3]
Space complexity: O(1)
*/

class Solution
{
    public:
        int numMagicSquaresInside(vector<vector<int>> & grid)
        {
            int result=0;

            int rows=grid.size();

            int columns=grid[0].size();

            int k=3;

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    int bottomRightRow=row + k - 1;

                    int bottomRightColumn=column + k - 1;

                    if(bottomRightRow < rows and bottomRightColumn < columns)
                    {
                        if(isValidMagicSquare(grid, rows, columns, row, column, bottomRightRow, bottomRightColumn)==true)
                        {
                            result+=1;
                        }
                    }
                }
            }

            return result;
        }

        bool isValidMagicSquare(vector<vector<int>> & grid, int rows, int columns, int row, int column, int bottomRightRow, int bottomRightColumn)
        {
            bool validMagicSquare=true;

            //Step 1: verify that the 3x3 square contains only distinct values from 1 to 9 inclusive
            vector<bool> used(10, false);

            for(int r=row;r<=bottomRightRow;r++)
            {
                for(int c=column;c<=bottomRightColumn;c++)
                {
                    int number=grid[r][c];

                    if(0 < number and number < 10)
                    {
                        used[number]=true;
                    }
                }
            }

            for(int number=1;number<10;number++)
            {
                if(used[number]==false)
                {
                    validMagicSquare=false;

                    break;
                }
            }

            if(validMagicSquare==false)
            {
                return validMagicSquare;
            }

            //Step 2: check if all row sums are the same
            int previousRowSum=-1;

            for(int r=row;r<=bottomRightRow;r++)
            {
                int rowSum=0;

                for(int c=column;c<=bottomRightColumn;c++)
                {
                    rowSum+=grid[r][c];
                }

                if(previousRowSum==-1)
                {
                    previousRowSum=rowSum;
                }
                else
                {
                    if(previousRowSum!=rowSum)
                    {
                        validMagicSquare=false;
                    }

                    previousRowSum=rowSum;
                }
            }

            if(validMagicSquare==false)
            {
                return validMagicSquare;
            }

            //Step 3: check if all column sums are the same
            int previousColumnSum=-1;

            for(int c=column;c<=bottomRightColumn;c++)
            {
                int columnSum=0;

                for(int r=row;r<=bottomRightRow;r++)
                {
                    columnSum+=grid[r][c];
                }

                if(previousColumnSum==-1)
                {
                    previousColumnSum=columnSum;
                }
                else
                {
                    if(previousColumnSum!=columnSum)
                    {
                        validMagicSquare=false;
                    }

                    previousColumnSum=columnSum;
                }
            }

            if(validMagicSquare==false)
            {
                return validMagicSquare;
            }

            //Step 4: check if both diagonal sums are the same
            int firstDiagonalSum=0;

            int r=row;

            int c=column;

            while(r <= bottomRightRow and c <= bottomRightColumn)
            {
                firstDiagonalSum+=grid[r][c];

                r+=1;

                c+=1;
            }

            int secondDiagonalSum=0;

            r=row;

            c=bottomRightColumn;

            while(r <= bottomRightRow and c >= 0)
            {
                secondDiagonalSum+=grid[r][c];

                r+=1;

                c-=1;
            }

            if(firstDiagonalSum!=secondDiagonalSum)
            {
                validMagicSquare=false;
            }

            return validMagicSquare;
        }
};