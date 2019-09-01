#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

/*
 * Approach: while the input number is not zero, we do the following: calculate the remainder of the
 * input number % the base we are converting to, appending that remainder to the end of our result string,
 * and dividing the input number by the base we are converting to. After our loop, if the input number was
 * negative, append a '-' to the end of our result string. Then, reverse the result. Finally, return our result.
 *
 * Time complexity: O(size of input number)
 * Space complexity: O(1)
 */

string convertToBase7(int num)
{
    string result{};

    int base=7;

    if(num==0)
    {
        return "0";
    }

    bool negative=(num < 0) ? true : false;

    while(num)
    {
        int remainder=int(abs(num % base));

        result+=to_string(remainder);

        num=num/base;
    }

    if(negative)
    {
        result+="-";
    }

    reverse(result.begin(), result.end());

    return result;
}