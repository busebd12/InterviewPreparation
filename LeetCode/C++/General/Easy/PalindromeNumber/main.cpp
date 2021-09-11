#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

/*
 * Approach:
 * Create a copy of the input number.
 * If the number is negative, push a - onto our stack of characters.
 * Loop over the copy and push each digit (as a character) onto the stack.
 * Then, loop over the original input and compare the current digit against the top of the stack.
 * If they are't the same, return false;
 * If the stack is not empty, return false. Else, return false;
 *
 * Time complexity: O(number of digits)
 *
 * Space Complexity: O(number of digits)
 */

bool isPalindrome(int x)
{
    long int copy=x;

    stack<char> stk;

    if(x < 0)
    {
        stk.push('-');

        copy*=-1;
    }

    while(copy)
    {
        int copyDigit=copy % 10;

        stk.push('0' + copyDigit);

        copy/=10;
    }

    while(x)
    {
        int digit=x % 10;

        int copyDigit=(stk.top() -'0');

        if(digit!=copyDigit)
        {
            return false;
        }

        stk.pop();

        x/=10;
    }

    return (!stk.empty()) ? false : true;
}