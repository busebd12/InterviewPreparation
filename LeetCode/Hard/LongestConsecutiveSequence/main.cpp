#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

/*
 * Solutions:
 *
 * 1. The idea is to find the minimum and maximum value of the input vector of numbers.
 * Then, we iterate over all numbers starting from the minimum value up to and including
 * the maximum value and keep track of the longest consecutive sequence of numbers that
 * we see.
 *
 * Time complexity: O(3n + d) => O(n + d) [where n is length of the input vector and d is the difference
 * between the minimum and maximum value of the input vector of numbers]
 *
 * Space complexity: O(u) [where u is the number of unique values from the input vector of numbers]
 *
 * 2. Put all numbers from the input vector into an std::unordered_set<int>. The idea is to treat each number from the
 * vector of numbers as either the start of a consecutive chain of numbers or the end of the consecutive chain of numbers
 * and walk the chain in both directions: going up from the starting number or going down from the starting number.
 * As we walk these chains, we keep track of the longest of said chains.
 *
 * Time complexity: O(n * (c1 + c2)) [where n is the length of the input vector; c1 is the length of the increasing chain;
 * c2 is the length of the decreasing chain]
 *
 * Space complexity: O(u) [where u is the number of unique values in the input vector of numbers]
 *
 * 3. Put all the numbers from the input vector into an unordered_set<int>. Then, we only iterate through the increasing
 * chain for a number if the number one less than it is not in the unordered_set. Why? Because we want to start each
 * chain at its lowest point (i.e. the smallest number in the chain) so that we don't re-count parts of chains that we
 * have already counted.
 *
 * Time complexity: O(n * c) [where n is the length of the input vector and c is the average chain length]
 * Space complexity: O(u) [where u is the number of unique values from the input vector]
 */

int longestConsecutive(std::vector<int> & nums)
{
    int result=0;

    if(nums.empty())
    {
        return result;
    }

    std::unordered_set<int> cache(nums.begin(), nums.end());

    int minimumValue=*(std::min_element(nums.begin(), nums.end()));

    int maximumValue=*(std::max_element(nums.begin(), nums.end()));

    int currentLength=0;

    for(auto number=minimumValue;number<=maximumValue;++number)
    {
        if(cache.count(number))
        {
            currentLength++;
        }
        else
        {
            result=std::max(currentLength, result);

            currentLength=0;
        }
    }

    result=std::max(result, currentLength);

    return result;
}

int longestConsecutive(std::vector<int> & nums)
{
    int result=0;

    if(nums.empty())
    {
        return result;
    }

    std::unordered_set<int> cache(nums.begin(), nums.end());

    for(auto & number : nums)
    {
        int currentLength=1;

        if(cache.count(number + 1))
        {
            int start=number + 1;

            while(cache.count(start))
            {
                currentLength++;

                start++;
            }
        }

        result=std::max(result, currentLength);

        currentLength=1;

        if(cache.count(number - 1))
        {
            int start=number - 1;

            while(cache.count(start))
            {
                currentLength++;

                start--;
            }
        }

        result=std::max(result, currentLength);
    }

    return result;
}

int longestConsecutive(std::vector<int> & nums)
{
    int result=0;

    if(nums.empty())
    {
        return result;
    }

    std::unordered_set<int> cache(nums.begin(), nums.end());

    for(auto & number : nums)
    {
        int currentLength=1;

        if(!cache.count(number - 1))
        {
            int start=number + 1;

            while(cache.count(start))
            {
                currentLength++;

                start++;
            }

            result=std::max(result, currentLength);
        }
    }

    return result;
}