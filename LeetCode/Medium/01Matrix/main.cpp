#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool onBoard(int rows, int columns, int row, int column)
{
    return row >= 0 && row < rows && column >= 0 && column < columns;
}

vector<vector<int>> updateMatrix(vector<vector<int>> & matrix)
{
    if(matrix.empty())
    {
        return matrix;
    }

    int rows=int(matrix.size());

    int columns=int(matrix[0].size());

    for(int i=0;i<rows;++i)
    {
        for(int j=0;j<columns;++j)
        {
            if(matrix[i][j]==1)
            {
                int left=rows + columns + 1;

                int up=rows + columns + 1;

                if(onBoard(rows, columns, i-1, j))
                {
                    up=matrix[i-1][j];
                }

                if(onBoard(rows, columns, i, j-1))
                {
                    left=matrix[i][j-1];
                }

                matrix[i][j]=(int(rows + columns + 1), min(up, left) + 1);
            }
        }
    }

    for(int i=rows-1;i>=0;--i)
    {
        for(int j=columns-1;j>=0;--j)
        {
            if(matrix[i][j]!=0 && matrix[i][j]!=1)
            {
                int down=rows + columns + 1;

                int right=rows + columns + 1;

                if(onBoard(rows, columns, i+1, j))
                {
                    down=matrix[i+1][j];
                }

                if(onBoard(rows, columns, i, j+1))
                {
                    right=matrix[i][j+1];
                }

                matrix[i][j]=min(matrix[i][j], min(down, right) + 1);
            }
        }
    }

    return matrix;
}