#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> & matrix, int target)
{
    if(matrix.empty())
    {
        return false;
    }

    int m=int(matrix.size());

    int n=int(matrix[0].size());

    if(m==1)
    {
        for(int i=0;i<n;++i)
        {
            if(matrix[0][i]==target)
            {
                return true;
            }
        }

        return false;
    }

    if(n==1)
    {
        for(int i=0;i<m;++i)
        {
            if(matrix[i][0]==target)
            {
                return true;
            }
        }

        return false;
    }

    int row=-1;

    for(int count=0;count<m;++count)
    {
        int first=matrix[count][0];

        int last=matrix[count][n-1];

        if(first <= target && target <= last)
        {
            row=count;

            break;
        }
    }

    if(row==-1)
    {
        return false;
    }

    for(int index=0;index<n;++index)
    {
        if(matrix[row][index]==target)
        {
            return true;
        }
    }

    return false;
}