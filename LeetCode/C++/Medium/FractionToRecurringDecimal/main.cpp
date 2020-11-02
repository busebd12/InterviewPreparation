#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>

/*
 * Solution: we use the grade school long division algorithm and a hashtable (std::unordered_map<long, int>) to keep
 * track of remainders that we have seen so far. We map the remainder amount to the index in the the result string.
 * While executing the long division algorithm, if we come across a remainder that we have already seen before, then
 * we know that the decimal will repeat infinitely and we can put ( and ) around the repeating decimal part.
 * We use the long data type to handle the cases where the result of a division or multiplication would result
 * in a number that is too large to fit into the integer type. We also have checks for the numerator or denominator
 * being zero.
 *
 * Time complexity: O(n) [where n is the length of the divisor]
 * Space complexity: O(n)
 */

std::string fractionToDecimal(int numerator, int denominator)
{
    std::string result{};

    if(denominator==0)
    {
        return result;
    }

    if(numerator==0)
    {
        return "0";
    }

    bool negative=true;

    if((numerator > 0 && denominator > 0) || (numerator < 0 && denominator < 0))
    {
        negative=false;
    }

    if(negative)
    {
        result+='-';
    }

    long longNumerator=std::labs(numerator);

    long longDenominator=std::labs(denominator);

    auto integerPart=longNumerator/longDenominator;

    result+=std::to_string(integerPart);

    auto remaining=longNumerator % longDenominator;

    if(remaining==0)
    {
        return result;
    }

    result+='.';

    std::unordered_map<long, int> hashtable;

    while(remaining)
    {
        remaining*=10;

        if(hashtable.count(remaining))
        {
            result.insert(hashtable[remaining], "(");

            result+=')';

            break;
        }

        hashtable[remaining]=result.size();

        auto digit=remaining/longDenominator;

        result+=std::to_string(digit);

        remaining%=longDenominator;
    }

    return result;
}