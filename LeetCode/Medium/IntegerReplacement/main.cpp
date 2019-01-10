#include <iostream>
#include <cmath>
using namespace std;

long integerReplacement(long n)
{
    if(n==1)
    {
        return 0;
    }

    if(n%2==0)
    {
        long even=1+integerReplacement(static_cast<long>(n/2));

        return even;
    }
    else
    {
        long odd1=1+integerReplacement(static_cast<long>(n+1));

        long odd2=1+integerReplacement(static_cast<long>(n-1));

        return min(odd1, odd2);
    }
}