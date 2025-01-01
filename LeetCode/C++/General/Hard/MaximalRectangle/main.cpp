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

/*
Solution 2: Based on the solution to problem #84, Largest Rectangle In Historgram
*/

class Solution
{
    public:
        int maximalRectangle(vector<vector<char>> & matrix)
        {
            int result=0;

            int rows=matrix.size();

            int columns=matrix[0].size();

            vector<int> heights(columns, 0);

            for(int row=0;row<rows;row++)
            {
                getHeights(matrix[row], heights, columns);

                int area=getMaxArea(heights);

                result=max(result, area);
            }

            return result;
        }

        void getHeights(vector<char> & matrixRow, vector<int> & heights, int columns)
        {
            for(int column=0;column<columns;column++)
            {
                int digit=matrixRow[column] - '0';

                if(digit==0)
                {
                    heights[column]=0;
                }
                else
                {
                    heights[column]+=digit;
                }
            }
        }

        int getMaxArea(vector<int> & heights)
        {
            int maxAreaSoFar=0;

            int h=heights.size();

            deque<pair<int, int>> stack;

            for(int i=0;i<h;i++)
            {
                int startIndex=i;

                while(!stack.empty() and stack.back().second > heights[i])
                {
                    auto [index, height]=stack.back();

                    stack.pop_back();

                    int length=i - index;

                    int area=height * length;

                    maxAreaSoFar=max(maxAreaSoFar, area);

                    startIndex=index;
                }

                stack.emplace_back(startIndex, heights[i]);
            }

            while(!stack.empty())
            {
                auto [index, height]=stack.back();

                stack.pop_back();

                int length=h - index;

                int area=height * length;

                maxAreaSoFar=max(maxAreaSoFar, area);
            }

            return maxAreaSoFar;
        }
};