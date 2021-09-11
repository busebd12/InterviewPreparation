#include <iostream>
#include <vector>
using namespace std;

/*
 * Approach: As we loop through the array, if the current bit is a zero, then we know it only needs
 * to be one bit, we set our oneBit boolean to true, and we can move i by one. However, if the current bit is a 1,
 * then we know it needs to be two bits in total, either 10 or 11. Hence, we increment i by two and set oneBit to false in that case.
 * After we finish looping, if the last character we touched was a one bit, then we know the bits are valid.
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(1)
 *
 */

bool isOneBitCharacter(vector<int> & bits)
{
    if(bits.empty())
    {
        return false;
    }

    size_t n=bits.size();

    bool oneBit=false;

    for(size_t index=0;index<n;)
    {
        if(bits[index]==0)
        {
            oneBit=true;

            ++index;
        }
        else
        {
            oneBit=false;

            index+=2;
        }
    }

    return oneBit;
}