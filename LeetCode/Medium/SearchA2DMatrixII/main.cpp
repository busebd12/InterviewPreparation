#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> & matrix, int target)
{
    if(matrix.empty() || matrix[0].empty())
    {
        return false;
    }

    int m=static_cast<int>(matrix.size());

    int n=static_cast<int>(matrix[0].size());

    int row=0;

    int column=n-1;

    while(row < m && column >= 0)
    {
        if(matrix[row][column]==target)
        {
            return true;
        }
        else if(matrix[row][column] > target)
        {
            --column;
        }
        else
        {
            ++row;
        }
    }

    return false;
}