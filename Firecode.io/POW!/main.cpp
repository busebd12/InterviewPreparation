#include <iostream>
#include <cmath>
using namespace std;

double power(int x, int n)
{
    bool negative=(n < 0) ? true : false;
    
    int count=abs(n);
    
    double result=1;
    
    while(count > 0)
    {
        result*=x;
        
        count--;
    }
    
    return (negative) ? 1/result : result;
}
