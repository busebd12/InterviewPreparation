#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/*
 * Solutions:
 *
 * 1. Create a copy of the input matrix. Then, for each spot in the copy matrix that is a zero,
 * we set all the numbers in the correct row and column to zero.
 *
 * Time complexity: O(m * n) [where m is the number of rows in the input matrix and n is the number of columns]
 * Space complexity: O(m * n)
 *
 * 2. Store the row and column values for the spots in the input matrix that are zeroes as a string in a vector of strings.
 * Then, iterate through the vector of strings and set all the values in the appropriate row and column to zero.
 *
 * Time complexity: O(m * n) [where m is the number of rows in the input matrix and n is the number of columns]
 * Space complexity: O(number of zeroes in the input matrix]
 */

void helper(std::vector<std::vector<int>> & matrix, int rows, int columns, int row, int column)
{
    for(int i=column;i<columns;++i)
    {
        matrix[row][i]=0;
    }

    for(int i=column;i>=0;--i)
    {
        matrix[row][i]=0;
    }

    for(int j=row;j<rows;++j)
    {
        matrix[j][column]=0;
    }

    for(int j=row;j>=0;--j)
    {
        matrix[j][column]=0;
    }
}

void setZeroes(std::vector<std::vector<int>>& matrix)
{
    if(matrix.empty())
    {
        return;
    }

    int rows=int(matrix.size());

    int columns=int(matrix[0].size());

    std::vector<std::vector<int>> extraSpace=matrix;

    for(auto row=0;row<rows;++row)
    {
        for(auto column=0;column<columns;++column)
        {
            if(extraSpace[row][column]==0)
            {
                helper(matrix, rows, columns, row, column);
            }
        }
    }
}

void setZeroes(std::vector<std::vector<int>>& matrix)
{
    if(matrix.empty())
    {
        return;
    }

    int rows=int(matrix.size());

    int columns=int(matrix[0].size());

    std::vector<std::string> coordinates;

    for(auto row=0;row<rows;++row)
    {
        for(auto column=0;column<columns;++column)
        {
            if(matrix[row][column]==0)
            {
                std::string coordinate{};

                coordinate+=std::to_string(row);

                coordinate+=",";

                coordinate+=std::to_string(column);

                coordinates.push_back(coordinate);
            }
        }
    }

    for(auto & coordinate : coordinates)
    {
        auto position=coordinate.find(',');

        int row=std::stoi(coordinate.substr(0, position));

        int column=std::stoi(coordinate.substr(position+1));

        helper(matrix, rows, columns, row, column);
    }
}