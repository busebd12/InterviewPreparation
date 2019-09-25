#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

/*
 * Approaches:
 *
 * 1) For each spot in the grid, M, count the total number of surrounding spots
 * are in the grid (i.e. up, down, left, right, and all diagonals). For each surrounding
 * spot that is in the grid, and that is greater than zero, add its value to the sum
 * kept for each spot. Then, divide the sum by the total number of valid surrounding spots.
 * The result is the value in the new grid.
 *
 * Time complexity: O(m * n) [where n is the number of rows and m is the number of columns in the grid]
 * Space complexity: O(m * n) --> if we are counting the return vector<vector<int>> as extra space
 *
 * 2) Almost identical to the first solution except that we don't have to check if the valid surrounding spots
 * value is greater than zero since adding zero wouldn't impact the sum.
 *
 * Time complexity: O(m * n) [where n is the number of rows and m is the number of columns in the grid]
 * Space complexity: O(m * n) --> if we are counting the return vector<vector<int>> as extra space.
 */

bool isValid(int row, int column, int & rows, int & columns)
{
    return ((row >= 0 && row < rows) && (column >= 0 && column < columns));
}

vector<vector<int>> imageSmoother(vector<vector<int>> & M)
{
    if(M.empty())
    {
        return M;
    }

    int rows=int(M.size());

    int columns=int(M[0].size());

    vector<vector<int>> result(rows, vector<int>(columns, 0));

    for(int row=0;row<rows;++row)
    {
        for(int column=0;column<columns;++column)
        {
            int count=1;

            int sum=0;

            if(M[row][column] > 0)
            {
                sum+=M[row][column];
            }

            if(isValid(row-1, column, rows, columns))
            {
                count++;

                if(M[row-1][column] > 0)
                {
                    sum+=M[row-1][column];
                }
            }

            if(isValid(row+1, column, rows, columns))
            {
                count++;

                if(M[row+1][column] > 0)
                {
                    sum+=M[row+1][column];
                }
            }

            if(isValid(row, column-1, rows, columns))
            {
                count++;

                if(M[row][column-1] > 0)
                {
                    sum+=M[row][column-1];
                }
            }

            if(isValid(row, column+1, rows, columns))
            {
                count++;

                if(M[row][column+1] > 0)
                {
                    sum+=M[row][column+1];
                }
            }

            if(isValid(row-1, column-1, rows, columns))
            {
                count++;

                if(M[row-1][column-1] > 0)
                {
                    sum+=M[row-1][column-1];
                }
            }

            if(isValid(row-1, column+1, rows, columns))
            {
                count++;

                if(M[row-1][column+1] > 0)
                {
                    sum+=M[row-1][column+1];
                }
            }

            if(isValid(row+1, column+1, rows, columns))
            {
                count++;

                if(M[row+1][column+1] > 0)
                {
                    sum+=M[row+1][column+1];
                }
            }

            if(isValid(row+1, column-1, rows, columns))
            {
                count++;

                if(M[row+1][column-1] > 0)
                {
                    sum+=M[row+1][column-1];
                }
            }

            int smoothed=int(floor(sum/count));

            result[row][column]=smoothed;
        }
    }

    return result;
}

vector<vector<int>> imageSmoother(vector<vector<int>>& M)
{
    if(M.empty())
    {
        return M;
    }

    int rows=int(M.size());

    int columns=int(M[0].size());

    vector<vector<int>> result(rows, vector<int>(columns, 0));

    for(int row=0;row<rows;++row)
    {
        for(int column=0;column<columns;++column)
        {
            int count=1;

            int sum=0;

            sum+=M[row][column];

            if(isValid(row-1, column, rows, columns))
            {
                count++;

                sum+=M[row-1][column];
            }

            if(isValid(row+1, column, rows, columns))
            {
                count++;

                sum+=M[row+1][column];
            }

            if(isValid(row, column-1, rows, columns))
            {
                count++;

                sum+=M[row][column-1];
            }

            if(isValid(row, column+1, rows, columns))
            {
                count++;

                sum+=M[row][column+1];
            }

            if(isValid(row-1, column-1, rows, columns))
            {
                count++;

                sum+=M[row-1][column-1];
            }

            if(isValid(row-1, column+1, rows, columns))
            {
                count++;

                sum+=M[row-1][column+1];
            }

            if(isValid(row+1, column+1, rows, columns))
            {
                count++;

                sum+=M[row+1][column+1];
            }

            if(isValid(row+1, column-1, rows, columns))
            {
                count++;

                sum+=M[row+1][column-1];
            }

            int smoothed=int(floor(sum/count));

            result[row][column]=smoothed;
        }
    }

    return result;
}