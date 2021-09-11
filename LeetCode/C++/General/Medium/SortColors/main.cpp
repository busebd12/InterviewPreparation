#include <algorithm>
#include <iostream>
#include <vector>

/*
 * Solutions:
 *
 * 1. Count sort. We count the number of zeroes, ones, and twos.
 * Then, we iterate through the vector and fill it with the zeores,
 * ones, and twos in the correct order.
 *
 * Time complexity: O(n + c) [where n is the length of the input vector and c is the number of colors]
 * Space complexity: O(c) [where c is the number of colors]
 *
 * 2. We partition the zeroes to the left of the ones and the twos to the right of the ones in the vector.
 * See this video: https://www.youtube.com/watch?v=BOt1DAvR0zI
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(1)
 */

void sortColors(std::vector<int> & nums)
{
    if(nums.empty())
    {
        return;
    }

    int colours=3;

    int n=int(nums.size());

    std::vector<int> counts(colours, 0);

    for(const auto & number : nums)
    {
        counts[number]++;
    }

    int i=0;

    for(int count=0;count<counts[0];++count)
    {
        nums[i]=0;

        i++;
    }

    for(int count=0;count<counts[1];++count)
    {
        nums[i]=1;

        i++;
    }

    for(int count=0;count<counts[2];++count)
    {
        nums[i]=2;

        i++;
    }
}

void sortColors(std::vector<int> & nums)
{
    if(nums.empty())
    {
        return;
    }

    int n=int(nums.size());

    int low=0;

    int middle=0;

    int high=n-1;

    while(middle <= high)
    {
        switch(nums[middle])
        {
            case 0:
                std::swap(nums[low], nums[middle]);

                low++;

                middle++;

                break;

            case 1:
                middle++;

                break;

            case 2:
                std::swap(nums[middle], nums[high]);

                high--;

                break;
        }
    }
}