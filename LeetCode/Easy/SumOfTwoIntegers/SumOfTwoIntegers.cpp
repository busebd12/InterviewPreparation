#include <iostream>
using namespace std;

int getSum(int a, int b)
{
    int sum;
    
    int carry;
    
    do 
    {
        sum=a ^ b; //add without carrying
        
        carry=(a & b) << 1; //carry, but don’t add

        a=sum;
        
        b=carry;
        
    }while(b!=0);

    return a;
}