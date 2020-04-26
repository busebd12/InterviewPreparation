#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

/*
 * Solution: inspired from this video --> https://www.youtube.com/watch?v=g8bSdXCG-lA
 *
 * Time complexity: O(rows * columns) [where rows is the number of rows in the matrix and columns is the number of columns]
 * Space complexity: O(columns)
 */

int largestRectangleArea(std::vector<int> & heights)
{
    int result=0;

    if(heights.empty())
    {
        return result;
    }

    std::stack<int> stk;

    stk.push(-1);

    auto n=int(heights.size());

    int i=0;

    for(;i<n;i++)
    {
        while(stk.top()!=-1 && heights[stk.top()] > heights[i])
        {
            int height=heights[stk.top()];

            stk.pop();

            int area=height * (i - stk.top() - 1);

            result=std::max(result, area);
        }

        stk.push(i);
    }

    while(stk.top()!=-1)
    {
        int height=heights[stk.top()];

        stk.pop();

        int area=height * (i - stk.top() - 1);

        result=std::max(result, area);
    }

    return result;
}

int maximalRectangle(std::vector<std::vector<char>> & matrix)
{
    int result=0;

    if(matrix.empty())
    {
        return result;
    }

    auto rows=int(matrix.size());

    auto columns=int(matrix[0].size());

    std::vector<int> heights(columns, 0);

    for(auto row=0;row<rows;++row)
    {
        int index=0;

        std::for_each(matrix[row].begin(), matrix[row].end(), [row, &heights, index] (auto & element) mutable
        {
            int number=element - '0';

            if(number==0)
            {
                heights[index]=number;
            }
            else
            {
                heights[index]+=number;
            }

            index++;
        });

        int area=largestRectangleArea(heights);

        result=std::max(result, area);
    }

    return result;
}