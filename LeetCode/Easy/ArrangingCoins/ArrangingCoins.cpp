#include <iostream>
using namespace std;

int arrangeCoins(int n)
{
    if(n <= 0)
    {
        return 0;
    }
    
    int rows=0;
    
    for(int i=1;i<=n;++i)
    {
        if(n >= i)
        {
            n-=i;
            
            ++rows;
        }
        else
        {
            break;
        }
    }
    
    return rows;
}