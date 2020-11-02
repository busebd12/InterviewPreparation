#include <iostream>
#include <vector>

/*
 * Solution: see this video --> https://www.youtube.com/watch?v=siKFOI8PNKM
 *
 * Time complexity: O(n * m) [where n is the number of rows in the input matrix and m is the number of columns in the input matrix]
 * Space complexity: O(1)
 */

std::vector<int> spiralOrder(std::vector<std::vector<int>> & matrix)
{
    std::vector<int> traversal;

    if(matrix.empty())
    {
        return traversal;
    }

    int rows=int(matrix.size());

    int columns=int(matrix[0].size());

    int topRow=0;

    int bottomRow=rows-1;

    int leftColumn=0;

    int rightColumn=columns-1;

    int direction=0;

    while(topRow <= bottomRow && leftColumn <= rightColumn)
    {
        if(direction==0)
        {
            for(int i=leftColumn;i<=rightColumn;++i)
            {
                traversal.push_back(matrix[topRow][i]);
            }

            topRow++;
        }
        else if(direction==1)
        {
            for(int i=topRow;i<=bottomRow;++i)
            {
                traversal.push_back(matrix[i][rightColumn]);
            }

            rightColumn--;
        }
        else if(direction==2)
        {
            for(int i=rightColumn;i>=leftColumn;--i)
            {
                traversal.push_back(matrix[bottomRow][i]);
            }

            bottomRow--;
        }
        else if(direction==3)
        {
            for(int i=bottomRow;i>=topRow;--i)
            {
                traversal.push_back(matrix[i][leftColumn]);
            }

            leftColumn++;
        }

        direction=(direction + 1) % 4;
    }

    return traversal;
}