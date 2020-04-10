#include <iostream>
#include <string>
#include <vector>

/*
 * Solution: As we iterate through the input vector, we use two variables to mark the beginning and ending of the ranges,
 * start and end. Initially, both start and end have the same value, the first number in the vector. Then, as we go
 * through the vector, if the current number is exactly one more than the previous number, the end of the range is set
 * to the current number. If not, we know we have reached the end of the current range, and we add the range to the
 * std::vector<std::string> result. We also set start and end to the beginning of the new range.
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(1) [if we don't count the space used for the output] O(r) [where r is the number of output ranges
 * if we do count the space used by the output]
 */

std::vector<std::string> summaryRanges(std::vector<int> & nums)
{
    std::vector<std::string> result;

    if(nums.empty())
    {
        return result;
    }

    auto n=nums.size();

    if(n==1)
    {
        result.emplace_back(std::to_string(nums[0]));

        return result;
    }

    int start=nums[0];

    int end=nums[0];

    for(auto i=1;i<n;++i)
    {
        if(nums[i]-1==nums[i-1])
        {
            end=nums[i];

            if(i==n-1)
            {
                if(start==end)
                {
                    result.emplace_back(std::to_string(start));
                }
                else
                {
                    result.emplace_back(std::to_string(start) + "->" + std::to_string(end));
                }
            }
        }
        else
        {
            if(start==end)
            {
                result.emplace_back(std::to_string(start));
            }
            else
            {
                result.emplace_back(std::to_string(start) + "->" + std::to_string(end));
            }

            start=nums[i];

            end=nums[i];

            if(i==n-1)
            {
                if(start==end)
                {
                    result.emplace_back(std::to_string(start));
                }
                else
                {
                    result.emplace_back(std::to_string(start) + "->" + std::to_string(end));
                }
            }
        }
    }

    return result;
}