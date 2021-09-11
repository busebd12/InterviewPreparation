#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * 1) Use a hash table (unordered_map) to keep track of the frequencies of each number.
 * If a number has a frequency greater than 1, return true. If no elements do, return false.
 *
 * Time complexity: O(n) [where n is the number of elements in the input vector]
 * Space complexity: O(n)
 *
 * 2) Use a unordered_set to keep track of which elements we have seen already.
 * If we try to insert an element that is already in the unordered_set, return true.
 * If all unique, return false.
 *
 * Time complexity: O(n) [where n is the number of elements in the input vector]
 * Space complexity: O(n - number of duplicates)
 *
 * 3) Sort the input vector. Then, loop through it and check for duplicates.
 *
 * Time complexity: O(n log n)
 * Space complexity: O(1)
 */

bool containsDuplicate(vector<int>& nums)
{
    if(nums.empty())
    {
        return false;
    }

    if(nums.size()==1)
    {
        return false;
    }

    unordered_map<int, int> table;

    for(int number : nums)
    {
        table[number]++;
    }

    for(const auto & element : table)
    {
        if(element.second > 1)
        {
            return true;
        }
    }

    return false;
}

bool containsDuplicate(vector<int> & nums)
{
    if(nums.empty())
    {
        return false;
    }

    if(nums.size()==1)
    {
        return false;
    }

    unordered_set<int> table;

    for(int number : nums)
    {
        if(table.count(number))
        {
            return true;
        }
        else
        {
            table.insert(number);
        }
    }

    return false;
}

bool containsDuplicate(vector<int> & nums)
{
    if(nums.empty())
    {
        return false;
    }

    if(nums.size()==1)
    {
        return false;
    }

    sort(nums.begin(), nums.end());

    int n=int(nums.size());

    for(int i=1;i<n;++i)
    {
        if(nums[i-1]==nums[i])
        {
            return true;
        }
    }

    return false;
}