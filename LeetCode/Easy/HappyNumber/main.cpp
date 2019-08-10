#include <iostream>
#include <unordered_set>
using namespace std;

/*
 * Approach: while true, loop over the number and square each individual digit and add the result to a running sum.
 * If the sum, is equal to n or is a number that would start in infinite loop, return false.
 * If the sum is 1, return true.
 * You can verify that the numbers listed in the unordered_set do, indeed, represent the starts of
 * infinite loops if you work through some examples by hand.
 *
 * Time complexity: O(k) [where k is the number of times it takes to get 1 or a number that starts an infinite loop]
 * Space complexity: O(number of numbers that start infinite loops) = O(8) = O(1)
 */
bool isHappy(int n)
{
    if(n==0)
    {
        return false;
    }

    if(n==1)
    {
        return true;
    }

    unordered_set<int> loopPoints={4, 16, 37, 58, 89, 145, 42, 20};

    if(loopPoints.count(n))
    {
        return false;
    }

    int current=n;

    while(true)
    {
        int sum=0;

        while(current)
        {
            int digit=current % 10;

            sum+=(digit * digit);

            current/=10;
        }

        if(sum==n || loopPoints.count(sum))
        {
            return false;
        }

        if(sum==1)
        {
            return true;
        }

        current=sum;
    }
}