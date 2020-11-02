#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

/*
 * Solutions:
 *
 * 1. We use the same logic as the merge step in merge sort and merge the two sorted arrays together into
 * one sorted array. Then, find the median value.
 *
 * Time complexity: O(m + n) [where m is the length of nums1 and n is the length of nums2]
 * Space complexity: O(m + n)
 *
 * 2. Using binary search. This video does an amazing job explaining it --> https://www.youtube.com/watch?v=LPFhl65R7ww
 *
 * Time complexity: O(log(min(m, n)) [where m is the length of nums1 and n is the length of nums2]
 * Space complexity: O(1)
 */

double findMedianSortedArrays(std::vector<int> & nums1, std::vector<int> & nums2)
{
    std::vector<int> merged;

    auto m=nums1.size();

    auto n=nums2.size();

    std::size_t i=0;

    std::size_t j=0;

    while(i < m && j < n)
    {
        if(nums1[i] < nums2[j])
        {
            merged.emplace_back(nums1[i]);

            i++;
        }
        else if(nums2[j] < nums1[i])
        {
            merged.emplace_back(nums2[j]);

            j++;
        }
        else
        {
            merged.emplace_back(nums1[i]);

            merged.emplace_back(nums2[j]);

            i++;

            j++;
        }
    }

    while(i < m)
    {
        merged.emplace_back(nums1[i]);

        i++;
    }

    while(j < n)
    {
        merged.emplace_back(nums2[j]);

        j++;
    }

    auto size=m + n;

    double result=0.0;

    if(size%2==1)
    {
        result+=merged[size/2];
    }
    else
    {
        result+=(merged[size/2] + merged[(size/2) - 1])/2.0;
    }

    return result;
}

double binarySearch(std::vector<int> & nums1, std::vector<int> & nums2)
{
    int m=int(nums1.size());

    int n=int(nums2.size());

    int total=m + n;

    int low=0;

    int high=m;

    double result=0.0;

    while(low <= high)
    {
        int partitionM=(low + (high - low)/2);

        int partitionN=(m + n + 1)/2 - partitionM;

        int maxLeftM=(partitionM==0) ? std::numeric_limits<int>::min() : nums1[partitionM-1];

        int minRightM=(partitionM==m) ? std::numeric_limits<int>::max() : nums1[partitionM];

        int maxLeftN=(partitionN==0) ? std::numeric_limits<int>::min() : nums2[partitionN-1];

        int minRightN=(partitionN==n) ? std::numeric_limits<int>::max() : nums2[partitionN];

        if(maxLeftM <= minRightN && maxLeftN <= minRightM)
        {
            if(total%2==0)
            {
                result+=double((std::max(maxLeftM, maxLeftN) + std::min(minRightN, minRightM))/2.0);
            }
            else
            {
                result+=double(std::max(maxLeftM, maxLeftN) * 1.0);
            }

            break;
        }
        else if(maxLeftM > minRightN)
        {
            high=partitionM - 1;
        }
        else
        {
            low=partitionM + 1;
        }
    }

    return result;
}

double findMedianSortedArrays(std::vector<int> & nums1, std::vector<int> & nums2)
{
    double median=0.0;

    if(nums1.size() < nums2.size())
    {
        median=binarySearch(nums1, nums2);
    }
    else
    {
        median=binarySearch(nums2, nums1);
    }

    return median;
}