#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Use an unordered_set<int> to find the duplicate number. Then, we fill the unordered_set<int> with the numbers
 * from [1,n] and then loop through the nums vector and look for the number that is not in the unordered_set<int>.
 *
 * Time complexity: O(n) [where n is the number of elements in the input vector]
 * Space complexity: O(n)
 *
 * 2) Use an unordered_map<int, int> as a hashtable. Then, we map each number in nums to its frequency.
 * We then loop over the numbers [1, n] and look for the number that appears twice and the number that is missing.
 *
 * Time complexity: O(n) [where n is the number of elements in the input vector]
 * Space complexity: O(n)
 *
 * 3) Same idea as the second solution but using a vector<int> as our hashtable instead of unordered_map<int, int>
 *
 * Time complexity: O(n) [where n is the number of elements in the input vector]
 * Space complexity: O(n)
 */

vector<int> findErrorNums(vector<int>& nums)
{
    vector<int> result(2);

    if(nums.empty())
    {
        return result;
    }

    int n=int(nums.size());

    unordered_set<int> cache;

    for(const auto & number : nums)
    {
        if(cache.count(number))
        {
            result[0]=number;
        }
        else
        {
            cache.insert(number);
        }
    }

    cache.clear();

    for(int number=1;number<=n;++number)
    {
        cache.insert(number);
    }

    for(const auto & number : nums)
    {
        if(cache.count(number))
        {
            cache.erase(number);
        }
    }

    result[1]=*(cache.begin());

    return result;
}

vector<int> findErrorNums(vector<int>& nums)
{
    vector<int> result(2);

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

    for(int i=1;i<=n;++i)
    {
        if(hashtable.count(i))
        {
            if(hashtable[i] > 1)
            {
                result[0]=i;
            }
        }
        else
        {
            result[1]=i;
        }
    }

    return result;
}

vector<int> findErrorNums(vector<int>& nums)
{
    vector<int> result(2);

    if(nums.empty())
    {
        return result;
    }

    int n=int(nums.size());

    vector<int> hashtable(n+1);

    for(const auto & number : nums)
    {
        hashtable[number]++;
    }

    for(int i=1;i<=n;++i)
    {
        if(hashtable[i] > 1)
        {
            result[0]=i;
        }

        if(hashtable[i]==0 && i > 0)
        {
            result[1]=i;
        }
    }

    return result;
}