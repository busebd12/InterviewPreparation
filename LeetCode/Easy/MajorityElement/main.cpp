#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * 1) https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 *
 * 2) Sort the vector. Then, the majority element will be at the n/2 index (n=size of the input vector).
 *
 * Time complexity: O(n log n) [where n is the size of the input vector]
 * Space complexity: O(1)
 *
 * 3) Use a hash table to keep track of the frequency for each number. Return the number that has a frequency
 * greater than n/2 (n=number of elements in the input vector)
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

int majorityElement(vector<int> & nums)
{
    int n=int(nums.size());

    int result=0;

    int count=0;

    for(int index=0;index<n;++index)
    {
        int current=nums[index];

        if(count==0)
        {
            result=current;

            count=1;
        }
        else
        {
            if(current==result)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
    }

    return result;
}

int majorityElement(vector<int> & nums)
{
    sort(nums.begin(), nums.end());

    int n=int(nums.size());

    return nums[n/2];
}

int majorityElement(vector<int>& nums)
{
    unordered_map<int,int> table;

    int n=int(nums.size());

    int targetFrequency=floor(n/2);

    int result=0;

    for(const int & number : nums)
    {
        table[number]++;
    }

    for(const auto & element : table)
    {
        if(element.second > targetFrequency)
        {
            result=element.first;

            break;
        }
    }

    return result;
}