#include <iostream>
#include <vector>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Approach:
 * Loop over the vector of digits backwards. If we are on the last digit, add one to it.
 * If the result is greater than nine (i.e. 10), set carry equal to one and zero as the new value
 * of the current digit to 0. If we are not on the last digit, add the carry value to the number.
 * If the new value is greater than nine (i.e. 10), set the carry equal to one and zero as the new value.
 * Else, set carry equal to zero. If, after the for loop, carry is greater than zero, add carry to the end
 * of the input vector and then reverse the input vector (for a case like 999). Return the input vector.
 *
 * Time complexity: O(n) [where n is the size of the input vector]
 *
 * Space complexity: O(1) [since we are modifying the input vector in-place]
 */

vector<int> plusOne(vector<int> & digits)
{
    if(digits.empty())
    {
        return digits;
    }

    int n=int(digits.size());

    int carry=0;

    for(int i=n-1;i>=0;--i)
    {
        int number=digits[i];

        if(i==n-1)
        {
            number+=1;
        }

        if(carry > 0)
        {
            number+=carry;
        }

        if(number > 9)
        {
            carry=number/10;

            digits[i]=number % 10;
        }
        else
        {
            digits[i]=number;

            carry=0;
        }
    }

    if(carry > 0)
    {
        digits.emplace_back(carry);

        reverse(digits.begin(), digits.end());
    }

    return digits;
}