#include <iostream>
using namespace std;

/*
 * Approach: while x and y are not zero, we isolate the 0th bit from x and y.
 * If the bits are different, then we increase the hamming distance.
 * We then right-shift both x and y by 1 so that we can get the next 0th bits.
 *
 * Time complexity: O(number of set bits in x + number of set bits in y)
 * Space complexity: O(1)
 */

int hammingDistance(int x, int y)
{
    int result=0;

    while(x || y)
    {
        int x0thBit=x & 1;

        int y0thBit=y & 1;

        if(x0thBit!=y0thBit)
        {
            result++;
        }

        x >>= 1;

        y >>= 1;
    }

    return result;
}