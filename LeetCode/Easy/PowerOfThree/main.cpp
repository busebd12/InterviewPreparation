#include <iostream>
#include <cmath>
using namespace std;

/*
 * Approaches:
 *
 * 1) Brute-force, iterative, TLE (time limit exceeded)
 * Time complexity: O(log-base 3 of n)
 * Space complexity: O(size of an integer)
 *
 * 2) Calculate if a number y is a power of x
 * Time complexity: O(log base x of y)
 * Space complexity: O(size of long int)
 *
 * 3) Recursively divide the number
 * Time complexity: O(log base 3 of n)
 * Space complexity: O(log base 3 of n) stack space
 *
 * 4) Iterative version of number three
 * Time complexity: O(log base 3 of n)
 * Space complexity: O(1)
 */
bool isPowerOfThree(int n)
{
    if(n <= 0)
    {
        return false;
    }

    if(n==1)
    {
        return true;
    }

    if(n==2)
    {
        return false;
    }

    int power=1;

    while(true)
    {
        int number=int(pow(3, power));

        if(number > n)
        {
            return false;
        }

        if(number==n)
        {
            return true;
        }

        power++;
    }
}

bool isPowerOf(long int x, int y)
{
    if(y==1)
    {
        return x==1;
    }

    long int power=1;

    while(power < x)
    {
        power*=y;
    }

    return power==x;
}

bool isPowerOfThree(int n)
{
    if(n <= 0)
    {
        return false;
    }

    if(n==1)
    {
        return true;
    }

    if(n==2)
    {
        return false;
    }

    int y=3;

    long int x=static_cast<long int>(n);

    return isPowerOf(x, y);
}

bool isPowerOfThree(int n)
{
    return n > 0 && (n==1 || (n%3==0 && isPowerOfThree(n/3)));
}

bool isPowerOfThree(int n)
{
    if(n <= 0)
    {
        return false;
    }

    if(n==1)
    {
        return true;
    }

    while((n % 3)==0)
    {
        n/=3;
    }

    return n==1;
}