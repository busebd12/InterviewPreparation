#include <iostream>
#include <vector>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * 1) Insert the elements of nums2 into nums1 starting after the last non-zero digit in nums1. Then, sort nums1.
 *
 * Time complexity: O(m+n log m+n) [where m+n is the total size of the elements already in nums1 plus the elements from nums2]
 * Space complexity: O(1)
 *
 * 2) Loop backwards through nums1 and nums2 and insert elements into their
 * appropriate slot, based on which element is greater, the one from nums1 or the one from nums2.
 *
 * Time complexity: O(m+n) [where m is the number of initialized elements in nums1 and n is the number of initialized elements in nums2]
 * Space complexity: O(1)
 */

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int i=(m+n)-(n);

    for(int j=0;j<n;++j)
    {
        nums1[i]=nums2[j];

        i++;
    }

    sort(nums1.begin(), nums1.end());
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int i=m-1;

    int j=n-1;

    int k=m+n-1;

    while(i >= 0 && j >= 0)
    {
        nums1[k--]=(nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
    }

    while(j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}