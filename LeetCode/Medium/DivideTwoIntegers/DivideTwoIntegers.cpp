#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

int divide(int dividend, int divisor)
{
    if(divisor==0)
    {
        return numeric_limits<int>::max();
    }

    if(dividend==0)
    {
        return 0;
    }

    if(divisor > dividend)
    {
        if(dividend > 0)
        {
            return 0;
        }
    }

    bool negative=false;

    if(dividend < 0 || divisor < 0)
    {
        negative=true;
    }
    
    if(dividend < 0 && divisor < 0)
    {
        negative=false;
    }

    long lDividend=labs(dividend);

    long lDivisor=labs(divisor);

    if(lDividend >= numeric_limits<int>::max())
    {
        if(divisor==1)
        {
            return dividend;
        }
        else if(divisor==-1)
        {
            return numeric_limits<int>::max();
        }
    }

    int result=0;

    while (lDividend >= lDivisor)
    { 
        long long temp=lDivisor;

        long long multiple=1;

        while (lDividend >= (temp << 1))
        {
            temp <<= 1;

            multiple <<= 1;
        }

        lDividend-=temp;

        result+=multiple;
    }

    return (negative) ? -result : result;
}