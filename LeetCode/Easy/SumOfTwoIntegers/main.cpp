#include <iostream>
using namespace std;

/*
 * Approach: See this video --> https://www.youtube.com/watch?v=qq64FrA2UXQ
 *
 * Time complexity: O(b)
 * Space complexity: O(1)
 */

int getSum(int a, int b)
{
    while(b!=0)
    {
        int carry=(a & b); //tells us which positions will result in carries

        a=(a ^ b); //do the actual addition

        b=(unsigned int)carry << 1; //store our carries
    }

    return a;
}