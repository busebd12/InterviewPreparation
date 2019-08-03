#include <iostream>
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
    long long int T=0;

    cin >> T;

    for(int testCase=0;testCase<T;++testCase)
    {
        long long int number=0;

        cin >> number;

        cout << countOnes(number) << endl;
    }
}