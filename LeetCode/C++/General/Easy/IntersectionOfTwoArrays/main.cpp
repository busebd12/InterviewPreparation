#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Approaches:
 *
 * 1) For each number in the first array (vector), check if the element also appears in the second array (vector).
 * If it does, add it to our unordered_set<int>. Add all the elements of the unordered_set to our result vector.
 *
 * Time complexity: O(n * m) [where n is the size of the first array (vector) and m is the size of the second array (vector)]
 * Space complexity: O(number of unique elements from the first array (vector that also appear in the second array (vector)]
 *
 * 2) Similar logic to the first approach except the two loops are no longer nested.
 *
 * Time complexity: O(n + m) [where n is the size of the first array (vector) and m is the size of the second array (vector)]
 * Space complexity: O(number of unique elements from the first array (vector that also appear in the second array (vector))
 *
 * 3) For each element in the first array (vector), use binary search to see if the element is present in the second array (vector)
 *
 * Time complexity: O(n log n) [where n is the size of the second array (vector)]
 * Space complexity: O(number of unique elements from the first array (vector that also appear in the second array (vector))
 */

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> result;

    if(nums1.empty() || nums2.empty())
    {
        return result;
    }

    int n=int(nums1.size());

    int m=int(nums2.size());

    unordered_set<int> seen;

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(nums1[i]==nums2[j])
            {
                seen.insert(nums1[i]);
            }
        }
    }

    for(const auto & element : seen)
    {
        result.push_back(element);
    }

    return result;
}

vector<int> intersection(vector<int> & nums1, vector<int> & nums2)
{
    vector<int> result;

    if(nums1.empty() || nums2.empty())
    {
        return result;
    }

    unordered_set<int> cache;

    for(const auto & number : nums1)
    {
        cache.insert(number);
    }

    for(const auto & number : nums2)
    {
        if(cache.count(number))
        {
            result.push_back(number);

            cache.erase(number);
        }
    }

    return result;
}

bool binarySearch(vector<int> & v, int target)
{
    int low=0;

    int high=int(v.size())-1;

    while(low <= high)
    {
        int middle=(low + ((high - low)/2));

        if(v[middle]==target)
        {
            return true;
        }
        else if(v[middle] > target)
        {
            high=middle-1;
        }
        else
        {
            low=middle+1;
        }
    }

    return false;
}

vector<int> intersection(vector<int> & nums1, vector<int> & nums2)
{
    vector<int> result;

    if(nums1.empty() || nums2.empty())
    {
        return result;
    }

    int n=int(nums1.size());

    sort(nums2.begin(), nums2.end());

    unordered_set<int> cache;

    for(int i=0;i<n;++i)
    {
        if(binarySearch(nums2, nums1[i]))
        {
            cache.insert(nums1[i]);
        }
    }

    for(const auto & number : cache)
    {
        result.push_back(number);
    }

    return result;
}