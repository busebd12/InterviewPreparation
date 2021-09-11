#include <iostream>
#include <vector>

/*
 * Solution: inspired from this video explanation --> https://www.youtube.com/watch?v=dsPdwhRR_84
 *
 * Time complexity: O(m + n) [where m is the number of rows in the matrix and n is the number of columns in the matrix]
 * Space complexity: O(1)
 */

bool searchMatrix(std::vector<std::vector<int>> & matrix, int target)
{
    if(matrix.empty())
    {
        return false;
    }

    int rows=int(matrix.size());

    int columns=int(matrix[0].size());

    int row=0;

    int column=columns-1;

    while(row < rows && column >= 0)
    {
        if(matrix[row][column]==target)
        {
            return true;
        }
        else if(matrix[row][column] > target)
        {
            column--;
        }
        else
        {
            row++;
        }
    }

    return false;
}