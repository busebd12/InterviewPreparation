#include <iostream>
#include <vector>
using namespace std;

vector<string> summaryRanges(vector<int> & nums)
{
    vector<string> result;

    if(nums.empty())
    {
        return result;
    }

    int numsSize=int(nums.size());

    int i=0;

    int j=0;

    while(j < numsSize)
    {
        if(j==numsSize-1)
        {
            string element{};

            if(nums[i]==nums[j])
            {
                element+=to_string(nums[i]);
            }
            else
            {
                element+=to_string(nums[i]);

                element+="->";

                element+=to_string(nums[j]);
            }

            result.emplace_back(element);

            break;
        }

        ++j;

        if(nums[j]-nums[j-1]!=1)
        {
            string element{};

            if(nums[i]==nums[j-1])
            {
                element+=to_string(nums[i]);
            }
            else
            {
                element+=to_string(nums[i]);

                element+="->";

                element+=to_string(nums[j-1]);
            }
            result.emplace_back(element);

            i=j;
        }
    }

    return result;
}