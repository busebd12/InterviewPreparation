#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    long long int N=0;

    cin >> N;

    int result=-1;

    for(int count=0;count<N;++count)
    {
        long long int number=0;

        cin >> number;

        if(result==-1)
        {
            result=number;
        }
        else
        {
            result=result | number;
        }
    }

    cout << result << endl;
}