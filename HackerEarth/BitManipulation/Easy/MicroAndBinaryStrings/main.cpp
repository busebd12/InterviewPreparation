#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solveTLE(string binary, int N)
{
    int ways=0;
    
    int n=int(binary.size());
    
    for(int rotations=0;rotations<N;++rotations)
    {
        rotate(binary.rbegin(), binary.rbegin()+1, binary.rend());
        
        if(binary[n-1]=='1')
        {
            ways++;
        }
    }
    
    return ways;
}

int solve(string binary)
{
    return count(binary.begin(), binary.end(), '1');
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    
    cin.tie(NULL);
    
    int T=0;
    
    cin >> T;
    
    for(int testCase=0;testCase<T;++testCase)
    {
        int N=0;
        
        string binary{};
        
        cin >> N;
        
        cin >> binary;
        
        cout << solve(binary) << endl;
    }
    
    return 0;
}