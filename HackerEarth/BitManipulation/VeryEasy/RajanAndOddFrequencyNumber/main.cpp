#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int n=0;

    cin >> n;

    int total=(2 * n) + 1;

    int result=0;

    for(int count=0;count<total;++count)
    {
        int number=0;

        cin >> number;

        result=result ^ number;
    }

    cout << result << endl;
}