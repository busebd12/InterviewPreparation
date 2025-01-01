#include <algorithm>
#include <vector>
using namespace std;

/*
Time complexity: O(rows * columns)
Space complexity: O(1)
*/

class Solution
{
    public:
        int longestLine(vector<vector<int>> & mat)
        {
            int result=0;

            int rows=mat.size();

            int columns=mat[0].size();

            //Check rows
            for(int row=0;row<rows;row++)
            {
                int ones=0;

                for(int column=0;column<columns;column++)
                {
                    if(mat[row][column]==1)
                    {
                        ones+=1;

                        result=max(result, ones);
                    }
                    else
                    {
                        ones=0;
                    }
                }
            }

            //Check columns
            for(int column=0;column<columns;column++)
            {
                int ones=0;

                for(int row=0;row<rows;row++)
                {
                    if(mat[row][column]==1)
                    {
                        ones+=1;

                        result=max(result, ones);
                    }
                    else
                    {
                        ones=0;
                    }
                }
            }

            //Check diagonals starting in the top row
            for(int column=0;column<columns;column++)
            {
                int r=0;

                int c=column;

                int ones=0;

                while(r < rows and c < columns)
                {
                    if(mat[r][c]==1)
                    {
                        ones+=1;

                        result=max(result, ones);
                    }
                    else
                    {
                        ones=0;
                    }

                    r+=1;

                    c+=1;
                }
            }

            //Check diagonals starting from each row in the first column
            for(int row=1;row<rows;row++)
            {
                int r=row;

                int c=0;

                int ones=0;

                while(r < rows and c < columns)
                {
                    if(mat[r][c]==1)
                    {
                        ones+=1;

                        result=max(result, ones);
                    }
                    else
                    {
                        ones=0;
                    }

                    r+=1;

                    c+=1;
                }
            }

            //Check anti-diagonals starting from each column in the top row
            for(int column=columns-1;column>=0;column--)
            {
                int r=0;

                int c=column;

                int ones=0;

                while(r < rows and c >= 0)
                {
                    if(mat[r][c]==1)
                    {
                        ones+=1;

                        result=max(result, ones);
                    }
                    else
                    {
                        ones=0;
                    }

                    r+=1;

                    c-=1;
                }
            }

            //Check all anti-diagonals start from each row in the last column
            for(int row=1;row<rows;row++)
            {
                int r=row;

                int c=columns - 1;

                int ones=0;

                while(r < rows and c >= 0)
                {
                    if(mat[r][c]==1)
                    {
                        ones+=1;

                        result=max(result, ones);
                    }
                    else
                    {
                        ones=0;
                    }

                    r+=1;

                    c-=1;
                }
            }
            
            return result;
        }
};