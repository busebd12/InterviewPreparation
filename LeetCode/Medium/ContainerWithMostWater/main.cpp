#include <cmath>
#include <iostream>
#include <vector>

/*
 * Solutions:
 *
 * 1. Look at all pairs of numbers in the height vector, calculate the area of the rectangle formed by these numbers,
 * and take the maximum area.
 *
 * Time complexity: O(n-squared) [where n is the length of the input vector]
 * Space complexity: O(1)
 *
 * 2. Use two pointers to scan the input vector. During each iteration, we calculate the rectangle area formed
 * by the two current numbers, and if the area is larger than the current max, we update the current max value.
 * We then find the next larger number than the minimum number of the current two numbers and start the process
 * over again.
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(1)
 */

int maxArea(std::vector<int> & height)
{
    int result=0;

    auto n=height.size();

    for(auto i=0;i<n;++i)
    {
        for(auto j=i+1;j<n;++j)
        {
            auto width=std::min(height[i], height[j]);

            auto length=j-i;

            auto A=length * width;

            result=std::max(result, A);
        }
    }

    return result;
}

int maxArea(std::vector<int> & height)
{
    int result=0;

    auto left=0;

    auto right=height.size()-1;

    size_t length=0;

    size_t width=0;

    int A=0;

    bool leftIsMin=false;

    while(left < right)
    {
        length=right - left;

        if(height[left] < height[right])
        {
            width=height[left];

            leftIsMin=true;
        }
        else
        {
            width=height[right];

            leftIsMin=false;
        }

        A=length * width;

        result=std::max(result, static_cast<int>(A));

        if(leftIsMin)
        {
            int i=left + 1;

            while(i < right && height[left] >= height[i])
            {
                i++;
            }

            left=i;
        }
        else
        {
            int j=right - 1;

            while(j > left && height[right] >= height[j])
            {
                j--;
            }

            right=j;
        }
    }

    return result;
}