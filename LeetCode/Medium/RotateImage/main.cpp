#include <algorithm>
#include <iostream>
#include <vector>

/*
 * Solution: we transpose the matrix and then reverse the rows.
 * The bookeeping details we need to remember are the following
 *
 * 1. We need to start our columns loop one after the current row. This will ignore the first and last numbers in our matrix since they don't get swapped.
 *
 * Time complexity: O(rows * columns) [where rows is the number of rows in the matrix and columns is the number of columns in the matrix]
 * Space complexity: O(1)
 */

void rotate(std::vector<std::vector<int>> & matrix)
{
    if(matrix.empty())
    {
        return;
    }

    const int rows=int(matrix.size());

    const int columns=int(matrix[0].size());

    for(int row=0;row<rows;++row)
    {
        for(int column=row+1;column<columns;++column)
        {
            std::swap(matrix[row][column], matrix[column][row]);
        }
    }

    for(auto & row : matrix)
    {
        std::reverse(row.begin(), row.end());
    }
}