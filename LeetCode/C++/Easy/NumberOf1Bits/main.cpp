#include <iostream>
#include <cstdint>
using namespace std;

/*
 * Approach:
 * While n is not zero, we will AND n and n-1, which will decrease
 * the number of set (one) bits by one each time.
 *
 * Time complexity: O(number of one bits in the input number)
 * Space complexity: O(1)
 */

int hammingWeight(uint32_t n)
{
    int ones=0;

    while(n)
    {
        n=n & (n-1);

        ones++;
    }

    return ones;
}