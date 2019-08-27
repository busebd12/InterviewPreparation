#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
 * Approaches:
 *
 * 1) Use a hashtable (unordered_map<int, int>) to map each number to how many times it appears in the vector.
 * Then, loop over the numbers [1,n] and if a number is not in the hashtable, add it to the result vector.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 *
 * 2) Since we are just concerned with whether or not the number from the range [1, n] in the input vector
 * and not its frequency, we can just use an unordered_set<int> instead of an unordered_map<int, int>
 * (unordered_set will also get rid of duplicates). Then, we just iterate over the numbers [1, n] if a
 * number is not in the unordered_set, add it to the result vector.
 *
 * Time complexity: O(n)
 * Space complexity: O(n-number of duplicate elements)
 *
 * 3) Variation on approach number one but using vector<int> instead of unordered_map<int, int> for our hashtable.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 *
 *
 * 4) This is the big IQ play. For each number in the vector, we multiply the number at the index (current number-1)
 * in the vector by -1, if it isn't already negative. Then, we loop over the vector and if any number is positive,
 * we know that the number equal to the (current index+1) is not in vector. Why does this work?
 *
 * If all the numbers from the range from [1, n] were in the vector, and in the correct order, then at each index
 * (starting from zero) there would exist the number that is one greater than the current index. However, since
 * some of the numbers are missing, that means, for each missing number, x, the number at index x-1 will not be negative
 * because we were not able to access that index due to the fact the number that is one greater than index-1 is not in the input vector.
 * Thus, as we loop over the input vector, if the number at each index is positive, the input vector doesn't contain the number index+1.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 *
 */

vector<int> findDisappearedNumbers(vector<int>& nums)
{
    vector<int> result;

    if(nums.empty())
    {
        return result;
    }

    int n=int(nums.size());

    unordered_map<int, int> hashtable;

    for(const auto & number : nums)
    {
        hashtable[number]++;
    }

    for(int number=1;number<=n;++number)
    {
        if(!hashtable.count(number))
        {
            result.push_back(number);
        }
    }

    return result;
}

vector<int> findDisappearedNumbers(vector<int>& nums)
{
    vector<int> result;

    if(nums.empty())
    {
        return result;
    }

    int n=int(nums.size());

    unordered_set<int> cache(nums.begin(), nums.end());

    for(int number=1;number<=n;++number)
    {
        if(!cache.count(number))
        {
            result.push_back(number);
        }
    }

    return result;
}

vector<int> findDisappearedNumbers(vector<int>& nums)
{
    vector<int> result;

    if(nums.empty())
    {
        return result;
    }

    int n=int(nums.size());

    vector<int> hashtable(n+1, 0);

    for(const auto & number : nums)
    {
        hashtable[number]++;
    }

    for(int number=1;number<=n;++number)
    {
        if(hashtable[number]==0)
        {
            result.push_back(number);
        }
    }

    return result;
}

vector<int> findDisappearedNumbers(vector<int> & nums)
{
    vector<int> result;

    if(nums.empty())
    {
        return result;
    }

    int n=int(nums.size());

    for(int i=0;i<n;++i)
    {
        int current=nums[i];

        int oneLess=abs(current)-1;

        if(nums[oneLess] > 0)
        {
            nums[oneLess]*=-1;
        }
    }

    for(int index=0;index<n;++index)
    {
        if(nums[index] > 0)
        {
            result.emplace_back(index+1);
        }
    }

    return result;
}