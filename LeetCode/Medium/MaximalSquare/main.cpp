#include <cmath>
#include <iostream>
#include <vector>

/*
 * Solutions:
 *
 * Both of these solutions were inspired from these videos
 *
 * https://www.youtube.com/watch?v=_Lf1looyJMU
 * https://www.youtube.com/watch?v=FO7VXDfS8Gk
 *
 * 1. Dynamic programming
 *
 * Time complexity: O(n * m) [where n is the number of rows in the matrix and m is the number of columns]
 * Space complexity: O(n * m)
 *
 * 2. Dynamic programming
 *
 * Time complexity: O(n * m) [where n is the number of rows in the matrix and m is the number of columns]
 * Space complexity: O(1)
 */

int maximalSquare(std::vector<std::vector<char>> & matrix)
{
    int result=0;

    if(matrix.empty())
    {
        return result;
    }

    int rows=int(matrix.size());

    int columns=int(matrix[0].size());

    std::vector<std::vector<int>> dp(rows, std::vector<int>(columns, 0));

    for(auto row=0;row<rows;++row)
    {
        dp[row][0]=matrix[row][0] - '0';

        result=std::max(result, dp[row][0]);
    }

    for(auto column=0;column<columns;++column)
    {
        dp[0][column]=matrix[0][column] - '0';

        result=std::max(result, dp[0][column]);
    }

    for(auto row=1;row<rows;++row)
    {
        for(auto column=1;column<columns;++column)
        {
            if(matrix[row][column]=='0')
            {
                dp[row][column]=0;
            }
            else
            {
                int neighborsResult=std::min(dp[row-1][column], std::min(dp[row-1][column-1], dp[row][column-1]));

                dp[row][column]=1 + neighborsResult;
            }

            result=std::max(result, dp[row][column]);
        }
    }

    result=result * result;

    return result;
}

int maximalSquare(std::vector<std::vector<char>> & matrix)
{
    int result=0;

    if(matrix.empty())
    {
        return result;
    }

    int rows=int(matrix.size());

    int columns=int(matrix[0].size());

    for(auto row=0;row<rows;++row)
    {
        result=std::max(result, matrix[row][0]-'0');
    }

    for(auto column=0;column<columns;++column)
    {
        result=std::max(result, matrix[0][column] - '0');
    }

    for(auto row=1;row<rows;++row)
    {
        for(auto column=1;column<columns;++column)
        {
            if(matrix[row][column]=='1')
            {
                int up=matrix[row-1][column] - '0';

                int left=matrix[row][column-1] - '0';

                int diagonal=matrix[row-1][column-1] - '0';

                int subproblem=1 + std::min({up, left, diagonal});

                matrix[row][column]=subproblem + '0';

                result=std::max(result, subproblem);
            }
        }
    }

    result=result * result;

    return result;
}