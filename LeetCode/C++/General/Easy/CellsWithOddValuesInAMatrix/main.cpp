#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
 * Approach: we create a matrix of size n by m.
 * Then, for each row and column index pair in indices, we increment all numbers
 * within that row and column. Then, for each row in the matrix, we count the number
 * of odd values and add that total to our result variable. Return result.
 *
 * Time complexity: O(i + m + n) [where i is the length of indices; m is the number of columns in the matrix; n is the number of rows in the matrix]
 * Space complexity: O(n * m)
 */

int oddCells(int n, int m, vector<vector<int>>& indices)
{
    vector<vector<int>> matrix(n, vector<int>(m));

    for(auto & index : indices)
    {
        int row=index[0];

        int column=index[1];

        for(auto i=0;i<m;++i)
        {
            matrix[row][i]++;
        }

        for(auto j=0;j<n;++j)
        {
            matrix[j][column]++;
        }
    }

    int result=0;

    for(const auto & row : matrix)
    {
        result+=count_if(row.begin(), row.end(), [] (auto & number) {return number%2==1;});
    }

    return result;
}