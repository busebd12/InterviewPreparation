#include <iostream>
using namespace std;

bool isPowerOfTwo(long long int number)
{
    int ones=0;

    while(number)
    {
        number=number & (number-1);

        ones++;
    }

    return ones==1 ? true : false;
}

int main(int argc, char** argv)
{
    long long int N=0;

    cin >> N;

    int result=0;

    for(long long int count=0;count<N;++count)
    {
        long long int number=0;

        cin >> number;

        if(isPowerOfTwo(number))
        {
            result++;
        }
    }

    cout << result << endl;
}
