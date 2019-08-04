#include <iostream>
#include <strings.h>
#include <cmath>
using namespace std;

int getPositionOfFirstSetBit(int number)
{
    int position=0;

    while(!(number & 1))
    {
        number>>=1;

        position++;
    }

    return position;
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

        int sum=0;

        for(int count=0;count<N;++count)
        {
            int number=0;

            cin >> number;

            int position=ffs(number);

            position-=1;

            sum+=int(pow(2, position));
        }

        cout << sum << endl;
    }
}