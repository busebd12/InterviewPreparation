#include <iostream>
#include <cmath>
using namespace std;

/*
 * Approach:
 *
 * Calcuate perfect squares until we find one that is larger than x.
 * Then, since we are rounding down, take the square root of the perfect
 * square that is smaller than x as our answer.
 *
 * Time complexity: O(n) [where n is the number of perfect squares calcuated till we reach one that is larger than x]
 *
 * Space complexity: O(1)
 */

int mySqrt(int x)
{
    if(x==0)
    {
        return 0;
    }

    if(x==1)
    {
        return 1;
    }

    unsigned long int base=1;

    unsigned long int perfectSquare=0;

    while(true)
    {
        perfectSquare=base * base;

        if(perfectSquare > x)
        {
            break;
        }

        base++;
    }

    return int(base-1);
}