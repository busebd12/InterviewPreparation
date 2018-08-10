#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

int minimumTotal(vector<vector<int>> & triangle)
{
    if(triangle.empty())
    {
        return 0;
    }

    int triangleSize=int(triangle.size());

    vector<vector<int>> sums;

    for(int i=0;i<triangleSize;++i)
    {
        sums.emplace_back(vector<int>(triangle[i].size()));
    }

    sums[0][0]=triangle[0][0];

    for(int row=1;row<triangleSize;++row)
    {
        for(int index=0;index<triangle[row].size();++index)
        {
            //if it's the first number in the row, only path can be from the number in the same place in the previous row
            if(index==0)
            {
                sums[row][index]=sums[row-1][index] + triangle[row][index];
            }
            //if it's the last number in the row, the only path can be from the number at the end of the previous row
            else if(index==triangle[row].size()-1)
            {
                sums[row][index]=sums[row-1][index-1] + triangle[row][index];
            }
            //if the number is in the middle of the row, then the paths can be from the number one index before it in the preivous row
            //and from the number in the same spot in the previous row. Take the minimum of the two.
            else
            {
                sums[row][index]=min(sums[row-1][index-1], sums[row-1][index]) + triangle[row][index];
            }
        }
    }

    int result=*(min_element(begin(sums[triangleSize-1]), end(sums[triangleSize-1])));

    return result;
}