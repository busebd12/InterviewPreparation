#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * Evolution of solutions, from top-to-bottom:
 *
 * 1) Brute-force, TLE (time limit exceeded): Run two for-loops and check all possible index pairs,
 * i and j, to see if their difference is less than or equal to k.
 *
 * Time complexity: O(n-squared) [where n is the size of the input vector]
 * Space complexity: O(1)
 *
 * 2) Use a hash table (unordered_map) to map each number to the indices
 * within the vector at which it appears. Then, loop over the hash table, and
 * if a number appears more than once, check all index pairs to see if two
 * indices have a absolute difference less than or equal to k
 *
 * Time complexity: O(n * d * m-squared)
 * [where n is the number of elements in the input vector and m is the number of indices;
 * d is the number of duplicate elements; and, m is the number of indices at which the duplicate elements appear]
 *
 * Space complexity: O(n)
 *
 * 3) Loop over the input vector and if the current number is in the hash table, check if its current minus its previous index
 * (the one it's mapped to in the hash table) is less than or equal to k.
 *
 * Time complexity: O(n) [where n is the size of the input vector]
 * Space complexity: O(n)
 */

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    if(nums.empty())
    {
        return false;
    }

    if(nums.size()==1)
    {
        return false;
    }

    int n=int(nums.size());

    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(nums[i]==nums[j])
            {
                int difference=abs(i - j);

                if(difference <= k)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    if(nums.empty())
    {
        return false;
    }

    if(nums.size()==1)
    {
        return false;
    }

    int n=int(nums.size());

    unordered_map<int, vector<int>> table;

    for(int index=0;index<n;++index)
    {
        int number=nums[index];

        if(table.count(number))
        {
            table[number].push_back(index);
        }
        else
        {
            table.insert(make_pair(number, vector<int>()));

            table[number].push_back(index);
        }
    }

    for(auto & element : table)
    {
        if(element.second.size() > 1)
        {
            vector<int> indices=element.second;

            int m=int(element.second.size());

            for(int i=0;i<m;++i)
            {
                for(int j=i+1;j<m;++j)
                {
                    int difference=abs(indices[i] - indices[j]);

                    if(difference <= k)
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool containsNearbyDuplicate(vector<int> & nums, int k)
{
    if(nums.empty())
    {
        return false;
    }

    if(nums.size()==1)
    {
        return false;
    }

    int n=int(nums.size());

    unordered_map<int, int> cache;

    for(int i=0;i<n;++i)
    {
        int current=nums[i];

        if(cache.count(current))
        {
            int difference=abs(i - cache[current]);

            if(difference <= k)
            {
                return true;
            }
        }

        cache[current]=i;
    }

    return false;
}