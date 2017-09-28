#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c)
{
    if(nums.empty())
    {
        return nums;
    }

    int numsRows=nums.size();

    int numsColumns=nums[0].size();

    if((numsRows * numsColumns)!=(r * c))
    {
        return nums;
    }

    vector<vector<int>> result;

    int elementCount=0;

    vector<int> row;

    for(int i=0;i<numsRows;++i)
    {
        for(int j=0;j<numsColumns;++j)
        {   
            row.emplace_back(nums[i][j]);

            ++elementCount;

            if(elementCount==c)
            {
                elementCount=0;

                result.emplace_back(row);

                row.clear();
            }
        }
    }

    return result;
}