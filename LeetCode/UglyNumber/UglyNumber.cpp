#include <iostream>
#include <vector>
using namespace std;

bool isUgly(int num)
{
    if(num <= 0)
    {
        return false;
    }
    
    vector<int> divisors={2, 3, 5};
    
    for(auto divisor : divisors)
    {
        while(num % divisor==0)
        {
            num/=divisor;
        }
    }
    
    return num==1;
}