#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n)
{
    vector<bool> table(n, true);
    
    for(int p=2;p*p<n;++p)
    {
        if(table[p])
        {
            for(int i=p*2;i<=n;i+=p)
            {
                table[i]=false;
            }
        }
    }
    
    int result=0;
    
    for(int index=2;index<table.size();++index)
    {
        if(table[index])
        {
            cout << index << " ";
            
            ++result;
        }
    }
    
    cout << endl;
    
    return result;
}