#include <iostream>
#include <cmath>
using namespace std;

bool judgeSquareSum(int c)
{
    for(int b=0;b<=sqrt(c);++b)
    {
        int a=sqrt(c-(b*b));
        
        int aSquared=a*a;
        
        if(aSquared==(c-(b*b)))
        {
            return true;
        }
    }
    
    return false;
}