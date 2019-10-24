#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Approaches:
 *
 * 1) Using two for loops, check if the array is either monotonic increasing or monotonic decreasing.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 *
 * 2) If the array is monotonic increasing, then it is sorted from left to right.
 * If the array is monotonic decreasing, then it is sorted from right to left.
 * We use the STL function, is_sorted, to check for either of those two cases.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

bool isMonotonic(vector<int>& A)
{
    bool monotoneIncreasing=true;

    bool monotoneDecreasing=true;

    int n=int(A.size());

    for(int i=0;i<n;++i)
    {
        if(i+1 < n)
        {
            if(A[i] > A[i+1])
            {
                monotoneIncreasing=false;

                break;
            }
        }
    }

    for(int i=0;i<n;++i)
    {
        if(i+1 < n)
        {
            if(A[i] < A[i+1])
            {
                monotoneDecreasing=false;

                break;
            }
        }
    }

    return monotoneIncreasing || monotoneDecreasing;
}

bool isMonotonic(vector<int>& A)
{
    return is_sorted(A.cbegin(), A.cend()) || is_sorted(A.crbegin(), A.crend());
}