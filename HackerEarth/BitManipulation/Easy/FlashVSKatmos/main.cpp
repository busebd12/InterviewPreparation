#include <iostream>
#include <vector>
#include <map>
using namespace std;

int countOnes(int number)
{
    int ones=0;
    
    while(number)
    {
        number=number & (number-1);
        
        ones++;
    }
    
    return ones;
}

void solve(vector<int> & numbers)
{
    multimap<int, int> cache;
    
    int n=int(numbers.size());
    
    for(int index=0;index<n;++index)
    {
        int number=numbers[index];
        
        int ones=countOnes(number);
        
        pair<int, int> p(ones, index);
        
        cache.insert(p);
    }
    
    for(const auto & element : cache)
    {
        cout << numbers[element.second] << " ";
    }
    
    cout << endl;
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
        
        solve(numbers);
    }
    
    return 0;
}