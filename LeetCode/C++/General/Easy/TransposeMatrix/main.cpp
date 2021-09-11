#include <iostream>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) The idea is that the transpose of a matrix can be found by doing a column major order traversal of the original
 * matrix and copying the contents of the matrix into our newly transposed matrix.
 *
 * Time complexity: O(n * m) [where n is the number of rows in our matrix and m is the number of columns]
 * Space complexity: O(n * m) [if we are counting the returned matrix]; otherwise, O(1)
 *
 * 2) Same logic and the first solution, but we allocated the amount of memory we will need for our returned matrix ahead of time.
 *
 * Time complexity: O(n * m) [where n is the number of rows in our matrix and m is the number of columns]
 * Space complexity: O(n * m) [if we are counting the returned matrix]; otherwise, O(1)
 */

vector<vector<int>> transpose(vector<vector<int>> & A)
{
    if(A.empty())
    {
        return A;
    }

    int rows=int(A.size());

    int columns=int(A[0].size());

    vector<vector<int>> transposed;

    for(int column=0;column<columns;++column)
    {
        vector<int> transposedRow;

        for(int row=0;row<rows;++row)
        {
            transposedRow.emplace_back(A[row][column]);
        }

        transposed.push_back(transposedRow);
    }

    return transposed;
}

vector<vector<int>> transpose(vector<vector<int>> & A)
{
    if(A.empty())
    {
        return A;
    }

    int rows=int(A.size());

    int columns=int(A[0].size());

    vector<vector<int>> transposed(columns, vector<int>(rows, 0));

    for(int column=0;column<columns;++column)
    {
        for(int row=0;row<rows;++row)
        {
            transposed[column][row]=A[row][column];
        }
    }

    return transposed;
}