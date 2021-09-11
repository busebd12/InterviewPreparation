#include <iostream>
#include <vector>
using namespace std;

/*
 * Approach: Sieve of Eratosthenes --> https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 *
 * Time complexity: O(n log log n) [where n is the input number]
 * Space complexity: O(n)
 */

int countPrimes(int n)
{
    int result=0;

    if(n <= 2)
    {
        return result;
    }

    vector<bool> sieve(n+1);

    for(int number=0;number<n;++number)
    {
        sieve[number]=true;
    }

    for(int number=2;(number * number)<n;++number)
    {
        if(!sieve[number])
        {
            continue;
        }

        int numberSquared=number * number;

        for(int multiple=numberSquared;multiple<n;multiple+=number)
        {
            sieve[multiple]=false;
        }
    }

    for(int i=2;i<n;++i)
    {
        if(sieve[i])
        {
            result++;
        }
    }

    return result;
}