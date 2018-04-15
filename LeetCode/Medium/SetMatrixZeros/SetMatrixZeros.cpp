#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>> & matrix)
{
    if(matrix.empty())
    {
        return;
    }

    int matrixSize=int(matrix.size());

    int rowSize=int(matrix[0].size());

    bool setFirstRowToZeros=false;

    bool setFirstColumnToZeros=false;

    for(int row=0;row<matrixSize;++row)
    {
        if(matrix[row][0]==0)
        {
            setFirstColumnToZeros=true;

            break;
        }
    }

    for(int column=0;column<rowSize;++column)
    {
        if(matrix[0][column]==0)
        {
            setFirstRowToZeros=true;

            break;
        }
    }

    for(int row=1;row<matrixSize;++row)
    {
        for(int column=1;column<rowSize;++column)
        {
            if(matrix[row][column]==0)
            {
                matrix[row][0]=0;

                matrix[0][column]=0;
            }
        }
    }

    for(int row=1;row<matrixSize;++row)
    {
        if(matrix[row][0]==0)
        {
            for(int column=1;column<rowSize;++column)
            {
                matrix[row][column]=0;
            }
        }
    }

    for(int column=1;column<rowSize;++column)
    {
        if(matrix[0][column]==0)
        {
            for(int row=1;row<matrixSize;++row)
            {
                matrix[row][column]=0;
            }
        }
    }

    if(setFirstRowToZeros)
    {
        for(int column=0;column<rowSize;++column)
        {
            matrix[0][column]=0;
        }
    }

    if(setFirstColumnToZeros)
    {
        for(int row=0;row<matrixSize;++row)
        {
            matrix[row][0]=0;
        }
    }
}