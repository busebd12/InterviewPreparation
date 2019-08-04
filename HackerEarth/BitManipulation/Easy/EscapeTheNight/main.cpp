#include <iostream>
#include <cmath>
using namespace std;

int countOnes(long long int number)
{
    int ones=0;
    
    while(number)
    {
        number=number & (number-1);
        
        ones++;
    }
    
    return ones;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    
    cin.tie(NULL);
    
    int T=0;
    
    cin >> T;
    
    for(int testCase=0;testCase<T;++testCase)
    {
        unsigned long long int sum=0;
        
        unsigned long long int N=0;
        
        cin >> N;
        
        for(unsigned long long int i=2;i<N;i=i*2)
        {
            for(unsigned long long int j=1;j<i;j=j*2)
            {
                if((i+j) <= N)
                {
                    sum=(sum + i + j) % 1000000007;
                }
            }
        }
        
        cout << sum << endl;
    }
    
    return 0;
}