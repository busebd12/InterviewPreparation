#include <iostream>
#include <map>
using namespace std;

int countOnes(long long int N)
{
    int ones=0;

    while(N)
    {
        N=N & (N-1);

        ones++;
    }

    return ones;
}

int main(int argc, char** argv)
{
    int T=0;

    cin >> T;

    for(int testCase=0;testCase<T;++testCase)
    {
        int N=0;

        cin >> N;

        multimap<int, long long int> table;

        for(int count=0;count<N;++count)
        {
            long long int number=0;

            cin >> number;

            int ones=countOnes(number);

            table.insert(make_pair(ones, number));
        }

        for(const auto & element : table)
        {
            cout << element.second << " ";
        }

        cout << endl;
    }
}