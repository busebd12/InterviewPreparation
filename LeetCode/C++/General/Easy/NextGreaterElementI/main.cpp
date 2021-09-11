#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * Approach: for each number in nums1, get its index in nums2.
 * Then, loop from one after that index till the end of nums2,
 * and if we find a number greater than the current number from
 * nums1, mark position i in our result vector with that number.
 * Return our result vector.
 *
 * Time complexity: O(n * m) [where n is the number of elements in nums1 and m is the number of elements in nums2]
 * Space complexity: O(n) [where n is the size of our result vector]
 */

int getIndex(vector<int> & nums2, int number)
{
    int index=-1;

    auto itr=find(nums2.begin(), nums2.end(), number);

    if(itr!=nums2.end())
    {
        index=itr-nums2.begin();
    }

    return index;
}

vector<int> nextGreaterElement(vector<int> & nums1, vector<int> & nums2)
{
    vector<int> result(nums1.size(), -1);

    if(nums1.empty()||nums2.empty())
    {
        return result;
    }

    int n=int(nums1.size());

    int m=int(nums2.size());

    for(int i=0;i<n;++i)
    {
        int number=nums1[i];

        int index=getIndex(nums2, number);

        int nextGreater=-1;

        for(int j=index+1;j<m;++j)
        {
            if(nums2[j]>number)
            {
                nextGreater=nums2[j];

                break;
            }
        }

        result[i]=nextGreater;
    }

    return result;
}