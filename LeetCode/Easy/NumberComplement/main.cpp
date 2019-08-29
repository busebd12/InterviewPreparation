#include <iostream>
#include <cmath>
using namespace std;

/*
Approach: while the input number is not zero, check the 0th bit of the number.
If the 0th bit is 0, then in the complement of the number, this bit needs would be a one.
So, we just need to find the value of that bit by calculating 2 to the bit position and add
that to the result. Else, the bit is a one and would be a zero in the complement, so just add
zero to the result.

Time complexity: O(size of input number)
Space complexity: O(1)
*/

int findComplement(int num)
{
    int position=0;

    int result=0;

    while(num)
    {
        int zeroBit=num & 1;

        if(zeroBit==0)
        {
            result+=int(pow(2, position));
        }
        else
        {
            result+=0;
        }

        position++;

        num >>= 1;
    }

    return result;
}