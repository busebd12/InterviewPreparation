#include <iostream>
#include <set>
#include <vector>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k)
{
    if(matrix.empty() || k <= 0)
    {
        return 0;
    }

    int rows=int(matrix.size());

    int columns=int(matrix[0].size());

    multiset<int> sorted;

    for(int i=0;i<rows;++i)
    {
        for(int j=0;j<columns;++j)
        {
            sorted.insert(matrix[i][j]);
        }
    }

    int count=1;

    for(auto & number : sorted)
    {
        if(count==k)
        {
            return number;
        }

        ++count;
    }
}