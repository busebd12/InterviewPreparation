#include <iostream>
using namespace std;

/*
 * Approach: store the first bit in the number (reading the bits from right to left)
 * in a variable, previous, and then right shift the number by one. This will "chop off"
 * the right most bit. Then, for the remaining bits, store each right most bit in a variable,
 * current and if current and previous are the same, return false. Otherwise, make previous
 * equal to current and right shift the number by one. After the while loop, return true.
 *
 * Time complexity: O(b) [where b is the number of bits in n]
 * Space complexity: O(1)
 */

bool hasAlternatingBits(int n)
{
    if(n <= 0)
    {
        return false;
    }

    if(n==1)
    {
        return true;
    }

    int previous=n & 1;

    n >>= 1;

    while(n)
    {
        int current=n & 1;

        if(current==previous)
        {
            return false;
        }

        previous=current;

        n >>= 1;
    }

    return true;
}