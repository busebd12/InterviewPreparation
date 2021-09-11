#include <iostream>

/*
 * Solutions:
 *
 * 1. After we handle some corner cases, we check for a negative power.
 * If the power is negative then wet set our flag to true. Then, we proceed
 * to multiply our result double by our base until we arrive at our answer.
 * If the power was negative, then we return 1 divided by our answer.
 * Else, we just return our answer. It should be noted that this solution
 * got a "Time Limit Exceeded" status when executed.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 *
 * 2. We use right-to-left binary exponentiation.
 * See this link: https://cp-algorithms.com/algebra/binary-exp.html
 *
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */

double myPow(double x, int n)
{
    if(x==0)
    {
        return 0;
    }

    if(x==1)
    {
        return 1;
    }

    if(n==0)
    {
        return 1;
    }

    if(n==-1)
    {
        return 1/x;
    }

    bool negative=false;

    if(n < 0)
    {
        negative=true;

        n*=-1;
    }

    double result=1.0;

    for(int count=0;count<n;++count)
    {
        result*=x;
    }

    return negative ? 1/result : result;
}

double myPow(double x, int n)
{
    if(x==0)
    {
        return 0;
    }

    if(x==1)
    {
        return 1;
    }

    if(n==0)
    {
        return 1;
    }

    if(n==-1)
    {
        return 1/x;
    }

    bool negative=false;

    long longN=n;

    if(n < 0)
    {
        negative=true;

        longN*=-1;
    }

    double result=1;

    while(longN > 0)
    {
        if(longN & 1)
        {
            result=result * x;
        }

        x=x * x;

        longN >>= 1;
    }

    return negative ? 1/result : result;
}

int main()
{
    std::cout<<"Hello, World!"<<std::endl;
    return 0;
}