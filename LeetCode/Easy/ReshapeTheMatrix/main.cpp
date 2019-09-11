#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*
 * Approach: If the product of the the original rows and columns is less than the product of r and c, then
 * we cannot reshape the matrix. Otherwise, we put all the elements of the nums into a deque, declare our output
 * vector<vector<int>> with r rows and c columns, and then add the elements of nums to the result.
 *
 * Time complexity: O(n * m) [where n is the number of rows in nums and m is the number of columns in nums]
 * Space complexity: O(n * m)
 */

vector<vector<int>> matrixReshape(vector<vector<int>> & nums, int r, int c)
{
    if(nums.empty())
    {
        return nums;
    }

    int originalRows=int(nums.size());

    int originalColumns=int(nums[0].size());

    int oldProduct=originalRows * originalColumns;

    int newProduct=r * c;

    if(newProduct > oldProduct)
    {
        return nums;
    }

    vector<vector<int>> result(r, vector<int>(c));

    deque<int> extra;

    for(int i=0;i<originalRows;++i)
    {
        for(int j=0;j<originalColumns;++j)
        {
            extra.emplace_back(nums[i][j]);
        }
    }

    for(int row=0;row<r;++row)
    {
        for(int column=0;column<c;++column)
        {
            int number=extra.front();

            extra.pop_front();

            result[row][column]=number;
        }
    }

    return result;
}