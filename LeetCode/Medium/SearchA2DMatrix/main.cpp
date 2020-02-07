#include <iostream>
#include <vector>

/*
 * Solutions:
 *
 * 1. Search through the matrix and if we find the target return true.
 * After searching through the entire matrix, return false.
 *
 * Time complexity: O(m * n) [where m is the number of rows and n is the number of columns in the matrix]
 * Space complexity: O(1)
 *
 * 2. Since the rows of the matrix are sorted in ascending order, we iterate through the rows until we find a row
 * with a last value that is greater than our target. At this point, if the target value exists in the matrix, it has
 * to be contained within this row. Thus, we just search this row for the target value. If we find it, return true.
 * Otherwise, return false.
 *
 * Time complexity: O(m + n) [where m is the number of rows and n is the number of columns in the matrix]
 * Space complexity: O(1)
 *
 * 3. Binary Search. If the rows of the matrix are concatenated together, they will form a 1-dimensional array
 * sorted in ascending order. Thus, we can use binary search to determine whether or not the given target exists
 * in the matrix. The only bookkeeping is converting the 1-dimensional array index into a 2-dimensional index.
 * See this explanation: https://softwareengineering.stackexchange.com/questions/212808/treating-a-1d-data-structure-as-2d-grid
 *
 * Time complexity: O(log(m * n)) [where m is the number of rows and n is the number of columns in the matrix]
 * Space complexity: O(1)
 */

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
{
    if(matrix.empty())
    {
        return false;
    }

    int rows=int(matrix.size());

    int columns=int(matrix[0].size());

    for(auto row=0;row<rows;++row)
    {
        for(auto column=0;column<columns;++column)
        {
            if(matrix[row][column]==target)
            {
                return true;
            }
        }
    }

    return false;
}

bool searchMatrix(std::vector<std::vector<int>> & matrix, int target)
{
    if(matrix.empty())
    {
        return false;
    }

    int rows=int(matrix.size());

    int columns=int(matrix[0].size());

    bool empty=true;

    for(auto row=0;row<rows;++row)
    {
        if(matrix[row].size() > 0)
        {
            empty=false;

            break;
        }
    }

    if(empty)
    {
        return false;
    }

    int row=0;

    int column=columns-1;

    while(row < rows && matrix[row][column] < target)
    {
        row++;
    }

    if(row < rows)
    {
        for(int i=0;i<columns;++i)
        {
            if(matrix[row][i]==target)
            {
                return true;
            }
        }
    }

    return false;
}

bool searchMatrix(std::vector<std::vector<int>> & matrix, int target)
{
    if(matrix.empty())
    {
        return false;
    }

    int rows=int(matrix.size());

    int columns=int(matrix[0].size());

    int low=0;

    int high=(rows * columns) - 1;

    while(low <= high)
    {
        int middle=low + (high - low)/2;

        int row=middle/columns;

        int column=middle % columns;

        int current=matrix[row][column];

        if(current==target)
        {
            return true;
        }
        else if(current > target)
        {
            high=middle-1;
        }
        else
        {
            low=middle+1;
        }
    }

    return false;
}