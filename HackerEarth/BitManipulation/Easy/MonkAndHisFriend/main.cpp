#include <iostream>
using namespace std;

int solve(long long int first, long long int second)
{
    int differentBits=0;

    while(first || second)
    {
        if(((first & (1 << 0)) && !(second & (1 << 0))) || ((!(first & (1 << 0)) && (second & (1 << 0)))))
        {
            differentBits++;
        }

        first=first >> 1;

        second=second >> 1;
    }

    return differentBits;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int T=0;

    cin >> T;

    for(int testCase=0;testCase<T;++testCase)
    {
        long long int first=0;

        long long int second=0;

        cin >> first;

        cin >> second;

        cout << solve(first, second) << endl;
    }

    return 0;
}