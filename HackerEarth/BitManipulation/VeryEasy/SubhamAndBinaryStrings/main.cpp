#include <iostream>
#include <string>
using namespace std;

int countZeroes(string s, int length)
{
    int zeroes=0;

    for(int x=0;x<length;++x)
    {
        if(s[x]=='0')
        {
            zeroes++;
        }
    }

    return zeroes;
}

int main(int argc, char** argv)
{
    int testCases=0;

    cin >> testCases;

    for(int i=0;i<testCases;++i)
    {
        int length=0;

        string s{};

        cin >> length;

        cin >> s;

        cout << countZeroes(s, length) << endl;
    }

    return 0;
}