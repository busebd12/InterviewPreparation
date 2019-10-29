#include <iostream>
#include <vector>
using namespace std;

/*
 * Approach: While the numbers in the array are in increasing order, we keep iterating. After we finish iterating,
 * if we are still at index zero (vector is in decreasing order only) or have reached the end of the vector
 * (vector is strictly increasing), return false. Next, we iterating from that spot while the rest of the numbers
 * are in decreasing order. After this second round of iteration, if we are not at the end of the vector, then
 * not all of the numbers where decreasing, and we return false. Otherwise, we have a valid mountain array/vector.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

bool validMountainArray(vector<int>& A)
{
    if(A.empty())
    {
        return false;
    }

    int n=int(A.size());

    int i=0;

    while(i+1 < n && A[i] < A[i+1])
    {
        i++;
    }

    if(i==n-1 || i==0)
    {
        return false;
    }

    while(i+1 < n && A[i] > A[i+1])
    {
        i++;
    }

    if(i < n-1)
    {
        return false;
    }

    return true;
}