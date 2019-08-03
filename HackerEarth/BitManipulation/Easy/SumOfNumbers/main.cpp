#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(vector<int> & numbers, int index, int sum)
{
    if(sum==0)
    {
        return true;
    }
    
    if(index==0 && sum!=0)
    {
        return false;
    }
    
    return isSubsetSum(numbers, index-1, sum-numbers[index-1]) || isSubsetSum(numbers, index-1, sum);
}

int main(int argc, char** argv)
{
    int T=0;
    
    cin >> T;
    
    for(int testCase=0;testCase<T;++testCase)
    {
        int N=0;
        
        cin >> N;
        
        vector<int> numbers(N);
        
        for(int index=0;index<N;++index)
        {
            int number=0;
            
            cin >> number;
            
            numbers[index]=number;
        }
        
        int sum=0;
        
        cin >> sum;
        
        if(isSubsetSum(numbers, N, sum))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}