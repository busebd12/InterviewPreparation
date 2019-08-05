#include <iostream>
#include <vector>
using namespace std;

long long int solve(vector<long long int> & numbers)
{
    long long int result=numbers[0];

    for(long long int index=1;index<numbers.size();++index)
    {
        result=result ^ numbers[index];
    }

    return (result==0) ? -1 : result;
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

        cin >> N;

        vector<long long int> numbers(N);

        for(long long int index=0;index<N;++index)
        {
            cin >> numbers[index];
        }

        cout << solve(numbers) << "\n";
    }

    return 0;
}