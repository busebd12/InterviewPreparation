#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

void rotate(vector<vector<int>> & matrix)
{
    reverse(begin(matrix), end(matrix));

    const int matrixSize=(int)matrix.size();

    for(int i=0;i<matrixSize;++i)
    {
        int rowSize=(int)matrix[i].size();

        for(int j=i+1;j<rowSize;++j)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}