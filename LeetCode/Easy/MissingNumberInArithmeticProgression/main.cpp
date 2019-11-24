#include <iostream>
#include <vector>
using namespace std;

/*
 * Approach: we sum up the first n numbers in our arithmetic progression.
 * Then, we subtract each number in the input vector from our sum.
 * The leftover value is the missing number.
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(1)
 */

int missingNumber(vector<int> & arr)
{
    if(arr.empty())
    {
        return -1;
    }

    auto n=arr.size();

    auto sum=((n + 1) * (arr[0] + arr[n-1]))/2;

    for(const auto & number : arr)
    {
        sum-=number;
    }

    return sum;
}