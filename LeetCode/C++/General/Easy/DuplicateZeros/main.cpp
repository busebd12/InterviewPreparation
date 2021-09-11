#include <iostream>
#include <vector>
using namespace std;

/*
 * Approach: as we iterate over the input vector, if we find a zero,
 * we shift all the elements to right by one place and then make the
 * number to the right of the current zero and zero.
 *
 * Time complexity: O(z * n-squared) [where z is the number of zeroes in the input vector and n is the length of the input vector]
 * Space complexity: O(1)
 */

void duplicateZeros(vector<int> & arr)
{
    if(arr.empty())
    {
        return;
    }

    auto n=arr.size();

    for(auto i=0;i<n;)
    {
        if(arr[i]==0)
        {
            for(auto j=n-2;j>=i;--j)
            {
                arr[j+1]=arr[j];
            }

            i+=2;
        }
        else
        {
            i++;
        }
    }
}