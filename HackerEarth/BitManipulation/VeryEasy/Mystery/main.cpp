#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    unsigned long long int N=0;

    while(cin >> N)
    {
        int ones=0;

        while(N)
        {
            N=N & (N-1);

            ones++;
        }

        cout << ones << "\n";
    }

    return 0;
}