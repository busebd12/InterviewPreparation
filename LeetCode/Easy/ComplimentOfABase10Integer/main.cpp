#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

/*
 * Approach: we convert the input number to a string representation of its bits.
 * Then, for each bit, if the bit is a one, we make it a zero and vice versa.
 * Finally, we convert the string back into a decimal number and return that number.
 *
 * Time complexity: O(b) [where b is the number of bits in the input number]
 * Space complexity: O(b)
 */

int binaryToDecimal(string complimentString)
{
    int decimal=0;

    int n=int(complimentString.size());

    int power=0;

    for(int i=0;i<n;++i)
    {
        if(complimentString[i]=='0')
        {
            complimentString[i]='1';
        }
        else
        {
            complimentString[i]='0';
        }
    }

    for(int i=n-1;i>=0;--i)
    {
        if(complimentString[i]=='1')
        {
            int value=1;

            for(int count=0;count<power;++count)
            {
                value*=2;
            }

            decimal+=value;
        }

        power++;
    }

    return decimal;
}

int bitwiseComplement(int N)
{
    if(N==0)
    {
        return 1;
    }

    string complimentString{};

    while(N)
    {
        int digit=N & 1;

        complimentString+=(digit + '0');

        N >>= 1;
    }

    reverse(complimentString.begin(), complimentString.end());

    int compliment=binaryToDecimal(complimentString);

    return compliment;
}