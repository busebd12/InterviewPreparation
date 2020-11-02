#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 Strategy
 For each number, calculate the difference between it and the target.
 If we don't find that difference in our hash table (unordered_map),
 then we know we haven't seen the second number that adds up to the target value.
 So, we add the current number and its index to the hash table.
 If we do find the difference in the hash table, that means we have
 found the second number in the pair that adds up to the target value.

 Time Complexity: O(n)

 Space Complexity: O(n) [worst case]
 */

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> indices;

    unordered_map<int, int> cache;

    int n=int(nums.size());

    for(int i=0;i<n;++i)
    {
        int current=nums[i];

        int difference=target-current;

        if(!cache.count(difference))
        {
            cache[current]=i;
        }
        else
        {
            indices.push_back(cache[difference]);

            indices.push_back(i);

            break;
        }
    }

    return indices;
}