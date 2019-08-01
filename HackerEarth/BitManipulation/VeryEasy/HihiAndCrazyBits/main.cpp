#include <iostream>
using namespace std;

int findFirstBitNotSet(long int n)
{
    int position=-1;

    for(int bit=0;bit<32;++bit)
    {
        if(!(n & (1 << bit)))
        {
            if(position==-1)
            {
                position=bit;
            }
            else
            {
                position=min(position, bit);
            }
        }
    }

    return position;
}

long int getNextNumber(long int n)
{
    long int result=0;

    if(!(n & 1))
    {
        result=(n | 1);
    }
    else
    {
        int position=findFirstBitNotSet(n);

        result=(n | (1 << position));
    }

    return result;
}

int main(int argc, char** argv)
{
    long int T=0;

    cin >> T;

    for(long int testCase=0;testCase<T;++testCase)
    {
        long int N=0;

        cin >> N;

        cout << getNextNumber(N) << endl;
    }

    return 0;
}