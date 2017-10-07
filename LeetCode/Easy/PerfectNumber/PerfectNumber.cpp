#include <iostream>
#include <cmath>
using namespace std;

bool perfectNumber(int num)
{
    int sum=0;
    
    for(int i=1;i<num;++i)
    {
        if((num % i)==0)
        {   
            sum+=i;
        }
    }
    
    return sum==num;
}

bool checkPerfectNumber(int num)
{
    if(num==1)
    {
        return false;
    }
    
    int sum=0;
    
    for(int i=2;i<sqrt(num);++i)
    {
        if((num % i)==0)
        {
            sum+=(i + (num/i));
        }
    }
    
    ++sum;
    
    return sum==num;
}