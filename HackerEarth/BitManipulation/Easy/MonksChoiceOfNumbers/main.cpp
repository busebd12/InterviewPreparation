#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
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

int solve(vector<int> & numbers, int k)
{
    vector<pair<int, int>> cache;

    for(int number : numbers)
    {
        int ones=countOnes(number);

        pair<int, int> p(ones, number);

        cache.push_back(p);
    }

    sort(cache.begin(), cache.end(), [] (auto & e1, auto & e2) {return e1.first > e2.first;});

    int sum=0;

    for(int index=0;index<k;++index)
    {
        sum+=cache[index].first;
    }

    return sum;
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

        int K=0;

        cin >> N;

        cin >> K;

        vector<int> numbers(N);

        for(int index=0;index<N;++index)
        {
            int number=0;

            cin >> number;

            numbers[index]=number;
        }

        cout << solve(numbers, K) << endl;
    }

    return 0;
}