#include <iostream>
#include <cstdint>
using namespace std;

/*
 * Approach:
 * Loop over the 32 bits (starting from zero) and if the current bit is set,
 * then set the corresponding bit from the end of the reversed number.
 *
 * Time complexity: O(number of bits in the input number) --> O(32) --> O(1) since 32 is a constant
 * Space complexity: O(1)
 */

uint32_t reverseBits(uint32_t n)
{
    uint32_t result=0;

    uint32_t totalBits=32;

    for(uint32_t bit=0;bit<totalBits;++bit)
    {
        uint32_t setBit=(n & (1 << bit)); //check if the current bit is set

        if(setBit)
        {
            result=result | (1 << ((totalBits-1) - bit)); //We want to use OR because 1 OR 0 is 1
        }
    }

    return result;
}