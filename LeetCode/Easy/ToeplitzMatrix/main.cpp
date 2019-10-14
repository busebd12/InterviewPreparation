#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
 * Approaches:
 *
 * 1) Traverse all the diagonals from the top-right to bottom-left and see if all of them have homogenous numbers.
 * If not, return false. If they do, return true. We use an unordered_set to keep track of the uniqueness of numbers
 * in the diagonal.
 *
 * Time complexity: O(n) [where n is the number of elements in all the diagonals from top-right to bottom-left]
 * Space complexity: O(n)
 *
 * 2) Same logic except without using the unordered_set to keep track of uniqueness of the numbers in the diagonals.
 *
 * Time complexity: O(n) [where n is the number of elements in all the diagonals from top-right to bottom-left]
 * Space complexity: O(1)
 */

bool isValid(size_t row, size_t column, size_t rows, size_t columns)
{
    return ((row >= 0 && row < rows) && (column >= 0 && column < columns));
}

bool isToeplitzMatrix(vector<vector<int>> & matrix)
{
    if(matrix.empty())
    {
        return true;
    }

    size_t rows=matrix.size();

    size_t columns=matrix[0].size();

    unordered_set<int> diagonal;

    for(size_t x=columns-1;x<columns;--x)
    {
        size_t row=0;

        size_t column=x;

        while(isValid(row, column, rows, columns))
        {
            int number=matrix[row][column];

            if(!diagonal.count(number))
            {
                if(diagonal.empty())
                {
                    diagonal.insert(number);
                }
                else
                {
                    return false;
                }
            }

            row++;

            column++;
        }

        diagonal.clear();
    }

    for(size_t y=1;y<rows;++y)
    {
        size_t row=y;

        size_t column=0;

        while(isValid(row, column, rows, columns))
        {
            int number=matrix[row][column];

            if(!diagonal.count(number))
            {
                if(diagonal.empty())
                {
                    diagonal.insert(number);
                }
                else
                {
                    return false;
                }
            }

            row++;

            column++;
        }

        diagonal.clear();
    }

    return true;
}

bool isToeplitzMatrix(vector<vector<int>> & matrix)
{
    if(matrix.empty())
    {
        return true;
    }

    size_t rows=matrix.size();

    size_t columns=matrix[0].size();

    for(size_t x=columns-1;x<columns;--x)
    {
        size_t row=0;

        size_t column=x;

        int first=matrix[row][column];

        while(isValid(row, column, rows, columns))
        {
            int number=matrix[row][column];

            if(number!=first)
            {
                return false;
            }

            row++;

            column++;
        }
    }

    for(size_t y=1;y<rows;++y)
    {
        size_t row=y;

        size_t column=0;

        int first=matrix[row][column];

        while(isValid(row, column, rows, columns))
        {
            int number=matrix[row][column];

            if(number!=first)
            {
                return false;
            }

            row++;

            column++;
        }
    }

    return true;
}