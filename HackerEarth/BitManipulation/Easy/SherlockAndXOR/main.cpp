#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int T=0;

    cin >> T;

    for(int testCase=0;testCase<T;++testCase)
    {
        long long int N=0;

        cin >> N;

        long long int even=0;

        long long int odd=0;

        for(int count=0;count<N;++count)
        {
            long long int number=0;

            cin >> number;

            if(number & 1)
            {
                odd++;
            }
            else
            {
                even++;
            }
        }

        long long int result=even * odd;

        cout << result << endl;
    }

    return 0;
}