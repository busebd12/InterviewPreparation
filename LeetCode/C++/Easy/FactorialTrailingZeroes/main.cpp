#include <iostream>
#include <cmath>
using namespace std;

/*
 * Approach: https://www.purplemath.com/modules/factzero.htm
 *
 * Time complexity: O(logn)
 * Space complexity: O(1)
 */

int trailingZeroes(int n)
{
    int zeroes=0;

    while(n > 0)
    {
        int next=n/5;

        zeroes+=next;

        n=next;
    }

    return zeroes;
}