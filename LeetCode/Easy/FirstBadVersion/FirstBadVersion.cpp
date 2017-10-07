#include <iostream>
using namespace std;

int firstBadVersion(int n)
{
    int start=1;
    
    int end=n;
    
    while(start < end)
    {
        int middle=start+(end-start)/2;
        
        if(!isBadVersion(middle))
        {
            start=middle+1;
        }
        else
        {
            end=middle;
        }
    }
    
    return start;
}