#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Approach: for each row in the matrix, we reverse it and then replace all ones with zeroes and all zeroes with ones.
 *
 * Time complexity: O(n * m) [where n is the number of rows in the matrix and m is the number of columns]
 * Space complexity: O(1)
 */

vector<vector<int>> flipAndInvertImage(vector<vector<int>> & A)
{
    int rows=int(A.size());

    for(int row=0;row<rows;++row)
    {
        reverse(A[row].begin(), A[row].end());

        for_each(A[row].begin(), A[row].end(), [&A] (int & number){number==0 ? number=1 : number=0;});
    }

    return A;
}