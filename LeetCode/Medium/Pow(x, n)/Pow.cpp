#include <iostream>
#include <cmath>
using namespace std;
double myPow(double x, int n)
{
    double result=1;

    long absN=abs(long(n));

    while(absN > 0)
    {
        if((absN & 1)==1)
        {
            result*=x;
        }

        absN >>=1;

        x*=x;
    }

    return (n < 0) ? 1/result : result;
}