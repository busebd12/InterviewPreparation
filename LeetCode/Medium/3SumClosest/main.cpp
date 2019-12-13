#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <utility>

/*
 * Solutions:
 *
 * 1. Using three for loops, we generate all triplets of numbers and store each sum in the vector<int> sums.
 * Then, we loop over all the sums and choose the one that is the closest to the target sum.
 *
 * Time complexity: O(n-cubed) [where n is the length of the input vector]
 * Space complexity: O(s) [where s is the number of triplet sums]
 *
 * 2. We sort the input vector and then for each number in the vector, we perform a bi-directional search
 * of the vector (starting from the left and right ends and moving towards the middle)to find the other
 * two numbers in our triplet. If the sum of the current triplet is the target value, then we return the sum.
 * If the sum is less than the target sum or the sum is greater than the target, we add it to our vector<int> sums.
 * Then, increment left or decrement right accordingly. After we having finished traversing the input vector,
 * we loop over all the sums and choose the one that is the closest to the target sum.
 *
 * Time complexity: O(n-squared) [where n is the length of the input vector]
 * Space complexity: O(s) [where s is the number of triplet sums]
 *
 * 3. Similar idea to the second solution except that we keep track of the closest sum as we traverse the input vector
 * and thus, don't need to allocate extra space for the sums vector.
 *
 * Time complexity: O(n-squared) [where n is the length of the input vector]
 * Space complexity: O(1)
 */

int threeSumClosest(std::vector<int> & nums, int target)
{
    if(nums.size() < 3)
    {
        return target;
    }

    auto n=nums.size();

    std::vector<int> sums;

    for(auto i=0;i<n-2;++i)
    {
        for(auto j=i+1;j<n-1;++j)
        {
            for(auto k=j+1;k<n;++k)
            {
                int sum=nums[i] + nums[j] + nums[k];

                sums.push_back(sum);
            }
        }
    }

    auto dist=std::abs(target - sums[0]);

    auto sum=sums[0];

    for(auto i=1;i<sums.size();++i)
    {
        auto currentDist=abs(target - sums[i]);

        if(currentDist < dist)
        {
            dist=currentDist;

            sum=sums[i];
        }
    }

    return sum;
}

int threeSumClosest(std::vector<int>& nums, int target)
{
    if(nums.size() < 3)
    {
        return target;
    }

    auto n=nums.size();

    int result=0;

    std::sort(nums.begin(), nums.end());

    std::vector<int> sums;

    for(auto i=0;i<n;++i)
    {
        auto left=i+1;

        auto right=n-1;

        while(left < right)
        {
            int sum=nums[i] + nums[left] + nums[right];

            if(sum==target)
            {
                return sum;
            }
            else if(sum < target)
            {
                sums.push_back(sum);

                left++;
            }
            else
            {
                sums.push_back(sum);

                right--;
            }
        }
    }

    result=sums[0];

    auto dist=std::abs(target - sums[0]);

    for(auto i=1;i<sums.size();++i)
    {
        auto currentDist=std::abs(target - sums[i]);

        if(currentDist < dist)
        {
            result=sums[i];

            dist=currentDist;
        }
    }

    return result;
}

int threeSumClosest(std::vector<int> & nums, int target)
{
    if(nums.size() < 3)
    {
        return target;
    }

    auto n=nums.size();

    std::sort(nums.begin(), nums.end());

    int result=nums[0] + nums[1] + nums[2];

    for(auto i=0;i<n;++i)
    {
        auto left=i+1;

        auto right=n-1;

        while(left < right)
        {
            int sum=nums[i] + nums[left] + nums[right];

            if(sum==target)
            {
                return sum;
            }
            else
            {
                if(std::abs(sum-target) < std::abs(result-target))
                {
                    result=sum;
                }

                if(sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }

    return result;
}