#include <iostream>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * 1) If n is not zero or negative, while n is even, repeatedly divide it by two.
 * After that, if n is one then it is a power of two.
 *
 * Time complexity: O(log n) [where n is the input number]
 * Space complexity: O(1)
 *
 * 2) Same logic as the first solution but using bit manipulation.
 *
 * Time complexity: O(log n) [where n is the input number]
 * Space complexity: O(1)
 *
 * 3) Using only bit manipulation. The key realization is the following:
 * Properties for numbers which are powers of 2, is that they have one and only one bit set in their binary representation.
 * If the number is neither zero nor a power of two, it will have 1 in more than one place.
 * So, if x is a power of 2, then x & (x-1) will be 0.
 *
 * Time complexity: O(1)
 * Space complexity: O(1)
 */

bool isPowerOfTwo(int n)
{
    if(n <= 0)
    {
        return false;
    }

    while((n % 2)==0)
    {
        n/=2;
    }

    return n==1;
}

bool isPowerOfTwo(int n)
{
    if(n <= 0)
    {
        return false;
    }

    while(!(n & 1))
    {
        n=n >> 1;
    }

    return n==1;
}

bool isPowerOfTwo(int n)
{
    if(n <= 0)
    {
        return false;
    }

    return (n && (!(n & n-1)));
}