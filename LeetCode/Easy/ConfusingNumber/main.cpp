#include <cmath>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

/*
 * Approach: use a hashtable (vector<int>) to map each digit that can be rotated to its rotated value.
 * Then, as we try to rotate each digit in the input number, if a digit cannot be rotated, return false.
 * Finally, remove all the digits from the deque we stored them in and build the rotated number.
 * If the rotated number is different from the original, return true. Else, return false.
 *
 * Time complexity: O(d) [where d is the number of digits in the input number]
 * Space complexity: O(d)
 */

bool confusingNumber(int N)
{
    vector<int> hashtable(10, 0);

    hashtable[1]=1;

    hashtable[6]=9;

    hashtable[8]=8;

    hashtable[9]=6;

    deque<int> dq;

    int n=N;

    while(n)
    {
        int digit=n % 10;

        if(hashtable[digit]==0 && digit!=0)
        {
            return false;
        }
        else
        {
            dq.push_front(hashtable[digit]);
        }

        n/=10;
    }

    int power=0;

    int rotated=0;

    while(!dq.empty())
    {
        int value=static_cast<int>(dq.front() * pow(10, power));

        rotated+=value;

        dq.pop_front();

        power++;
    }

    return rotated!=N;
}