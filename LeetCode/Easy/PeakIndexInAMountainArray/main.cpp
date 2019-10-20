#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Approaches:
 *
 * 1) Brute force. Consider each index as a potential peak index and check to see if there
 * is at least one element to the left of it that is less and one element to the right of it that is less.
 *
 * Time complexity: O(n-squared) [where n is the length of the input vector/array]
 * Space complexity: O(1)
 *
 * 2. Using the is_sorted_until function provided by the STL. This function will return an iterator to the first
 * elememt in the array that is not sorted. All we have to check for is to make sure that the previous element,
 * the last element that is in sorted order, is not either the first element in the array (no elements to the left of it)
 * or the last element (no elements to the right of it). If that check is true, then return the index.
 *
 * Time complexity: O(n) [where n is the length of the input array/vector]
 * Space complexity: O(1)
 *
 *
 * 3) Same logic as the second solution, just without using the is_sorted_until STL function.
 *
 * Time complexity: O(n) [where n is the size of the input array/vector]
 * Space complexity: O(1)
 */

bool isPeak(vector<int> & A, const int & n, int candidate)
{
    int leftCount=0;

    for(int left=0;left<candidate;++left)
    {
        if(A[left] < A[candidate])
        {
            leftCount++;
        }
        else
        {
            break;
        }
    }

    int rightCount=0;

    for(int right=candidate+1;right<n;++right)
    {
        if(A[right] < A[candidate])
        {
            rightCount++;
        }
        else
        {
            break;
        }
    }

    return leftCount > 0 && rightCount > 0;
}

int peakIndexInMountainArray(vector<int> & A)
{
    if(A.empty())
    {
        return 0;
    }

    int n=int(A.size());

    int result=-1;

    for(int i=0;i<n;++i)
    {
        if(isPeak(A, n, i))
        {
            result=i;

            break;
        }
    }

    return result;
}

int peakIndexInMountainArray(vector<int> & A)
{
    auto itr=is_sorted_until(A.begin(), A.end());

    int result=-1;

    if(itr!=A.end() && itr!=A.begin())
    {
        result=(itr - A.begin())-1;
    }

    return result;
}

int peakIndexInMountainArray(vector<int> & A)
{
    int result=-1;

    int n=int(A.size());

    for(int i=1;i<n;i++)
    {
        if(i > 0 && i+1 < n)
        {
            if(A[i] > A[i-1] && A[i] > A[i+1])
            {
                result=i;

                break;
            }
        }
    }

    return result;
}