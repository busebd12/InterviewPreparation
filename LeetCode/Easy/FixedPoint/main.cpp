#include <iostream>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1. Loop over the input vector and when we come to the first index where A[index]==index, set our result variable to that index and break.
 * Return that result variable as our answer.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 *
 * 2. Binary search, since the input vector is sorted. The only tricky part is when A[index]==index.
 * Since we are trying to find the smallest index, we simply decrement our high variable by one.
 *
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */

int fixedPoint(vector<int> & A)
{
    int result=-1;

    for(auto i=0;i<A.size();++i)
    {
        if(A[i]==i)
        {
            result=i;

            break;
        }
    }

    return result;
}

int fixedPoint(vector<int> & A)
{
    int result=-1;

    auto high=A.size()-1;

    auto low=0;

    while(low <= high)
    {
        int middle=low + (high - low)/2;

        if(middle < 0 || middle > int(A.size()-1))
        {
            break;
        }

        if(A[middle]==middle)
        {
            result=middle;

            high=middle-1;
        }
        else if(A[middle] > middle)
        {
            high=middle-1;
        }
        else
        {
            low=middle+1;
        }
    }

    return result;
}