#include <iostream>
using namespace std;

int solve(long int N)
{
    int count=0;

    if(N==0)
    {
        return 0;
    }
    else
    {
        while(!(N & 1))
        {
            N=(N >> 1);

            count++;
        }

        return (1 << count);
    }
}

int main(int argc, char** argv)
{
    long int N=0;

    while(cin >> N)
    {
        cout << solve(N) << endl;
    }

    return 0;
}