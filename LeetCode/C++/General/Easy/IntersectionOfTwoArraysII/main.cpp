#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * Approaches:
 *
 * 1) Using a two hashtables (unordered_map), loop over both arrays and count the frequecy of each element.
 * Then, loop over the first hashtable and if the current element is present in the second hashtable,
 * add the current element min(frequency from first hashtable, frequency from second hashtable) times.
 *
 * Time complexity: O(m + n) [where m is the length of the second array and n is the length of the first array]
 * Space complexity: O(m + n)
 *
 * 2) Using a singel hashtable (unordered_map), determine the frequency of each element in the first array.
 * Then, loop over the second array and if the frequecy of the element, when decremented by one, is still greater
 * than zero, add the current element to the result vector.
 *
 * Time complexity: O(m + n) [where m is the length of the second array and n is the length of the first array]
 * Spae complexity: O(m + n)
 */

vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> result;

    if(nums1.empty() || nums2.empty())
    {
        return result;
    }

    unordered_map<int, int> nums1Map;

    unordered_map<int, int> nums2Map;

    for(const int & number : nums1)
    {
        nums1Map[number]++;
    }

    for(const int & number : nums2)
    {
        nums2Map[number]++;
    }

    for(const auto & element : nums1Map)
    {
        if(nums2Map.count(element.first))
        {
            int total=min(element.second, nums2Map[element.first]);

            for(int count=0;count<total;++count)
            {
                result.push_back(element.first);
            }
        }
    }

    return result;
}

vector<int> intersect(vector<int> & nums1, vector<int> & nums2)
{
    vector<int> result;

    if(nums1.empty() || nums2.empty())
    {
        return result;
    }

    unordered_map<int, int> hashtable;

    int n=int(nums1.size());

    int m=int(nums2.size());

    for(int x=0;x<n;++x)
    {
        hashtable[nums1[x]]++;
    }

    for(int y=0;y<m;++y)
    {
        if(hashtable[nums2[y]] > 0)
        {
            --hashtable[nums2[y]];

            result.push_back(nums2[y]);
        }
    }

    return result;
}