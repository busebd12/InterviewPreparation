#include <iostream>
#include <cmath>
using namespace std;

int getLength(long long int number)
{
    int count=0;

    while(number)
    {
        number=number >> 1;

        count++;
    }

    return count;
}

int main(int argc, char** argv)
{
    long long int A=0;

    cin >> A;

    long long int B=A;

    int length=getLength(A);

    long long int temp=static_cast<long long int>(pow(2, length)-1);

    long long int C=A ^ temp;

    cout << B << " " << C << endl;
}