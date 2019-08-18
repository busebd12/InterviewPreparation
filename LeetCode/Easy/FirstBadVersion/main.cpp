#include <iostream>
#include <cmath>
using namespace std;

/*
 * Approaches:
 *
 * 1) Linear search, gets TLE (time limit exceeded)
 * Time complexity: O(n)
 * Space complexity: O(1)
 *
 * 2) Binary search, recursive
 *
 * Time complexity: O(log n)
 * Space complexity: O(log n) stack space
 *
 * 3) Binary search, recursive
 *
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */

int firstBadVersion(int n)
{
    int result=0;

    if(n==0)
    {
        return n;
    }

    for(int version=1;version<=n;++version)
    {
        if(isBadVersion(version))
        {
            result=version;

            break;
        }
    }

    return result;
}

void binarySearch(int low, int high, int n, int & result)
{
    if(low > high || low < 0 || high < 0 || high > n)
    {
        return;
    }

    int version=low + ((high - low) / 2);

    if(isBadVersion(version))
    {
        if(result==-1)
        {
            result=version;
        }
        else
        {
            if(version < result)
            {
                result=version;
            }
        }

        binarySearch(low, version-1, n, result);
    }
    else
    {
        binarySearch(version+1, high, n, result);
    }
}

int firstBadVersion(int n)
{
    int result=-1;

    if(n==0)
    {
        return 0;
    }

    int low=0;

    int high=n;

    binarySearch(low, high, n, result);

    return result;
}

int firstBadVersion(int n)
{
    int result=-1;

    if(n==0)
    {
        return n;
    }

    int low=0;

    int high=n;

    while(low <= high)
    {
        int version=low + ((high - low) / 2);

        if(isBadVersion(version))
        {
            if(result==-1)
            {
                result=version;
            }
            else
            {
                result=min(result, version);
            }

            high=version - 1;
        }
        else
        {
            low=version + 1;
        }
    }

    return result;
}