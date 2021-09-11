#include <iostream>
#include <cmath>
using namespace std;

/*
 * Approaches:
 *
 * 1) Repeatedly recursively divide the number
 *
 * Time complexity: O(log four of n)
 * Space complexity: O(log four of n) stack space
 *
 * 2) Same logic as number one, just iteratively instead
 *
 * Time complexity: O(log four of n)
 * Space complexity: O(1)
 */

bool isPowerOfFour(int num)
{
    return num > 0 && (num==1 || (num%4==0 && isPowerOfFour(num/4)));
}

bool isPowerOfFour(int num)
{
    if(num <= 0)
    {
        return false;
    }

    while(num%4==0)
    {
        num/=4;
    }

    return num==1;
}