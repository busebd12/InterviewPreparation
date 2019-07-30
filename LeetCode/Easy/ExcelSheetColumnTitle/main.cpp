#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
 * Approach:
 * Keep a look-up table that maps each upper-case letter to its corresponding integer place in the alphabet (1 based).
 * Then, while n is greater than zero, modulo n by 26. This result will be the letter we add to our result string.
 * Now, there are two cases: the result of the modulo will be zero or greater than zero. If the result is zero, then
 * we add 'Z' to our result string (since 26 % 26 = 0). Then, we divide n by 26 and subtract 1.
 * Otherwise, on our next iteration, n would be 1 instead of zero, and we would add 'A' to our result string by mistake.
 * If the modulo result is greater than zero, we just add the appropriate letter mapped to the modulo result to our
 * result string and divide n by 26.
 *
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */

string convertToTitle(int n)
{
    string result{};

    if(n <= 0)
    {
        return result;
    }

    unordered_map<int, char> table;

    int count=1;

    for(char c='A';c<='Z';++c,++count)
    {
        table[count]=c;
    }

    while(n > 0)
    {
        int remainder=n % 26;

        if(remainder==0)
        {
            result+=table[26];

            n=(n/26)-1;
        }
        else
        {
            result+=table[remainder];

            n=n/26;
        }
    }

    reverse(result.begin(), result.end());

    return result;
}