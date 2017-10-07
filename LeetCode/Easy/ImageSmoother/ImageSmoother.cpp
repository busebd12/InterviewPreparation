#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isOnGrid(int row, int column, const size_t rows, const size_t columnSize)
{
    return ((row >= 0 && row <= rows-1) && (column >= 0 && column <= columnSize-1));
}

vector<vector<int>> imageSmoother(vector<vector<int>>& M) 
{
    vector<vector<int>> result(M.size(), vector<int>(M[0].size()));

    if(M.empty())
    {
        return result;
    }

    const size_t rows=M.size();

    const size_t columnSize=M[0].size();

    for(int row=0;row<rows;++row)
    {
        for(int column=0;column<columnSize;++column)
        {
            int total=M[row][column];

            int count=1;

            if(isOnGrid(row+1, column, rows, columnSize))
            {
                total+=M[row+1][column];

                ++count;
            }

            if(isOnGrid(row-1, column, rows, columnSize))
            {
                total+=M[row-1][column];

                ++count;
            }

            if(isOnGrid(row, column+1, rows, columnSize))
            {
                total+=M[row][column+1];

                ++count;
            }

            if(isOnGrid(row, column-1, rows, columnSize))
            {
                total+=M[row][column-1];

                ++count;
            }

            if(isOnGrid(row-1, column-1, rows, columnSize))
            {
                total+=M[row-1][column-1];

                ++count;
            }

            if(isOnGrid(row-1, column+1, rows, columnSize))
            {
                total+=M[row-1][column+1];

                ++count;
            }

            if(isOnGrid(row+1, column-1, rows, columnSize))
            {
                total+=M[row+1][column-1];

                ++count;
            }

            if(isOnGrid(row+1, column+1, rows, columnSize))
            {
                total+=M[row+1][column+1];

                ++count;
            }

            if(count==0)
            {
                result[row][column]=M[row][column];
            }
            else
            {
                result[row][column]=(total/count); 
            }   
        }
    }

    return result;
}