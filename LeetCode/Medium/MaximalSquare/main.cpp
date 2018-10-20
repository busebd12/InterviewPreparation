#include <iostream>
#include <vector>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix)
{
    int answer=0;

    if(matrix.empty())
    {
        return answer;
    }

    int rows=int(matrix.size());

    int columns=int(matrix[0].size());

    vector<vector<int>> cache(rows, vector<int>(columns));

    for(int i=0;i<matrix[0].size();++i)
    {
        cache[0][i]=matrix[0][i]-'0';

        if(matrix[0][i]=='1')
        {
            answer=1;
        }
    }

    for(int j=0;j<rows;++j)
    {
        cache[j][0]=matrix[j][0]-'0';

        if(matrix[j][0]=='1')
        {
            answer=1;
        }
    }

    for(int i=1;i<rows;++i)
    {
        for(int j=1;j<columns;++j)
        {
            if(matrix[i][j]=='1')
            {
                cache[i][j]=min(min(cache[i-1][j], cache[i][j-1]), min(cache[i][j-1], cache[i-1][j-1]))+1;
            }

            if(cache[i][j] > answer)
            {
                answer=cache[i][j];
            }
        }
    }

    return answer*answer;
}