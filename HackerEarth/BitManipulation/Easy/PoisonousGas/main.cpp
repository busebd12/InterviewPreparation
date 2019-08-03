#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPowerOfTwo(long long int strength)
{
    int ones=0;

    while(strength)
    {
        strength=strength & (strength-1);

        ones++;
    }

    return ones==1 ? true : false;
}

string solve(vector<long long int> & numbers)
{
    long long int strength=0;

    for(long long int number : numbers)
    {
        if(number > 0)
        {
            strength+=number;
        }
    }

    return (isPowerOfTwo(strength) && strength!=0) ? "Yes" : "No";
}

int main(int argc, char** argv)
{
    long long int T=0;

    cin >> T;

    for(int testCase=0;testCase<T;++testCase)
    {
        long long int N=0;

        cin >> N;

        vector<long long int> numbers(N);

        for(int count=0;count<N;++count)
        {
            long long int number=0;

            cin >> number;

            numbers[count]=number;
        }

        cout << solve(numbers) << endl;
    }
}