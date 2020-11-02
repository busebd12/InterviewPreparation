#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
 * Approach:
 *
 * 1. Find the minimum number in the input vector
 * 2. Sum up the digits in the minimum number
 * 3. If the sum of the digits is odd return 0; else, return 1
 *
 * Time complexity: O(n + d) [where n is the length of the input vector and d is the number of digits in the minimum number]
 * Space complexity: O(1)
 */

int sumOfDigits(vector<int> & A)
{
    if(A.empty())
    {
        return 0;
    }

    int minNumber=*(min_element(A.begin(), A.end()));

    int sum=0;

    while(minNumber)
    {
        sum+=(minNumber % 10);

        minNumber/=10;
    }

    return sum%2==1 ? 0 : 1;
}