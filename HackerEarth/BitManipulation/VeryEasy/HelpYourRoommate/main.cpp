#include <iostream>
using namespace std;

int solve(int N)
{
    int count=0;

    for(int bit=0;bit<32;++bit)
    {
        if(N & (1 << bit))
        {
            count++;
        }
    }

    return count;
}

int main(int argc, char** argv)
{
    int T=0;

    cin >> T;

    for(int testCase=0;testCase<T;++testCase)
    {
        int N=0;

        cin >> N;

        cout << solve(N) << endl;
    }

    return 0;
}