#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

/*
 * Solutions:
 *
 * 1. The idea is to sort the nums vector and then for each element in nums, we do a bi-directional
 * search of nums for two numbers that when added to the current number, give a sum of 0.
 * When we find two numbers that add up to our target number, we add the three numbers to a vector<int> triplet
 * and then add triplet to a set<vector<int>> cache. Since sets don't allow duplicates, only unique triplets will
 * be added to cache. After looping over nums, we add all the unique vectors to our vector<vector<int>> result.
 * Finally, return result.
 *
 * Time complexity: O(n-squared) [where n is the length of the nums vector]
 * Space complexity: O(t) [where t is the number of triplets that sum to zero]
 *
 *
 * 2. Similar to the first solution. However, instead of using a set<vector<int>> to handle duplicate triplets,
 * for each triplet we find, we skip all duplicates of any/all of the three numbers before going for another
 * pass through our while loop.
 *
 * Time complexity: O(n-squared) [where n is the length of the input vector]
 * Space complexity: O(u) [where u is number of unique triplets that add to zero]
 */

std::vector<std::vector<int>> threeSum(std::vector<int> & nums)
{
    std::vector<std::vector<int>> result;

    if(nums.size() < 3)
    {
        return result;
    }

    std::sort(nums.begin(), nums.end());

    auto n=nums.size();

    std::set<std::vector<int>> cache;

    for(auto i=0;i<n;++i)
    {
        int target=-nums[i];

        auto left=i+1;

        auto right=n-1;

        while(left < right)
        {
            auto sum=nums[left] + nums[right];

            if(sum==target)
            {
                std::vector<int> triplet(3, 0);

                triplet[0]=nums[i];

                triplet[1]=nums[left];

                triplet[2]=nums[right];

                cache.insert(triplet);

                left++;

                right--;
            }
            else if(sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    for(const auto & element : cache)
    {
        result.push_back(element);
    }

    return result;
}

std::vector<std::vector<int>> threeSum(std::vector<int> & nums)
{
    std::vector<std::vector<int>> result;

    if(nums.size() < 3)
    {
        return result;
    }

    std::sort(nums.begin(), nums.end());

    auto n=nums.size();

    for(auto i=0;i<n;++i)
    {
        int target=-nums[i];

        int left=i+1;

        int right=n-1;

        while(left < right)
        {
            auto sum=nums[left] + nums[right];

            if(sum==target)
            {
                std::vector<int> triplet(3, 0);

                triplet[0]=nums[i];

                triplet[1]=nums[left];

                triplet[2]=nums[right];

                result.push_back(triplet);

                while(left < right && nums[left]==triplet[1])
                {
                    left++;
                }

                while(left < right && nums[right]==triplet[2])
                {
                    right--;
                }
            }
            else if(sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        while(i+1 < n && nums[i]==nums[i+1])
        {
            i++;
        }
    }

    return result;
}