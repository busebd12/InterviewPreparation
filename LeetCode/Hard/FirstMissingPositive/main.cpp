#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

/*
 * Solutions:
 *
 * 1. Put the contents of the input vector into an std::unordered_set<int>.
 * Then, iterate from 1 to the max integer value and which ever number is not
 * in the unordered_set is the answer.
 *
 * Time complexity: O(n + value of max integer) [where n is the length of the input vector]
 * Space complexity: O(u) [where u is the number of unique integers in the input vector]
 *
 * 2. Similar idea to the first solution except that we don't use the std::unordered_set<int> for storage,
 * just loop from 1 to the max integer value (inclusive) and check for the first missing value.
 *
 * Time complexity: O(n * max integer value) [where n is the length of the input vector]
 * Space complexity: O(1)
 *
 * 3. Inspired from this solution --> https://leetcode.com/problems/first-missing-positive/discuss/17071/My-short-c%2B%2B-solution-O(1)-space-and-O(n)-time
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(1)
 */

int firstMissingPositive(std::vector<int> & nums)
{
    if(nums.empty())
    {
        return 1;
    }

    int result=0;

    std::unordered_set<int> cache(nums.begin(), nums.end());

    for(auto number=1;number<=std::numeric_limits<int>::max();++number)
    {
        if(!cache.count(number))
        {
            result=number;

            break;
        }
    }

    return result;
}

int firstMissingPositive(std::vector<int> & nums)
{
    if(nums.empty())
    {
        return 1;
    }

    int result=0;

    for(auto number=1;number<=std::numeric_limits<int>::max();++number)
    {
        if(std::find(nums.begin(), nums.end(), number)==nums.end())
        {
            result=number;

            break;
        }
    }

    return result;
}

int firstMissingPositive(std::vector<int> & nums)
{
    if(nums.empty())
    {
        return 1;
    }

    int i=0;

    auto n=int(nums.size());

    while(i < n)
    {
        if(nums[i] > 0 && nums[i] <= n && nums[i]!=nums[nums[i]-1])
        {
            std::swap(nums[i], nums[nums[i]-1]);
        }
        else
        {
            i++;
        }
    }

    for(i=0;i<n;++i)
    {
        if(nums[i]!=i+1)
        {
            return i+1;
        }
    }

    return n+1;
}