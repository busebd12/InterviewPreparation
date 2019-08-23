#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
 * Approaches:
 *
 * 1) Since each hexadecimal digit maps exactly to four bits of a binary number,
 * we can split the binary representation of the number into its four bit chunks
 * and convert each chunk to its corresponding hexadecimal value. This is why
 * we are shifting to the right by 4 bits every time in the while loop.
 * We cast the input number to unsigned int to account for negative numbers.
 * We 'AND' the number with 15 because 15 is the largest number that can be represented by 4 bits.
 *
 * Time complexity: O(size of unsigned int version of input number)
 * Space complexity: O(size of characters string) --> O(16) --> O(1)
 *
 * 2) Use the Standard Template Library tools to do the conversion.
 */

string toHex(int num)
{
    string result{};

    if(num==0)
    {
        return "0";
    }

    unsigned int unsignedNum=static_cast<unsigned int>(num);

    string characters="0123456789abcdef";

    int largest4BitNumber=15;

    while(unsignedNum)
    {
        result+=characters[unsignedNum & largest4BitNumber];

        unsignedNum >>= 4;
    }

    reverse(result.begin(), result.end());

    return result;
}

string toHex(int num)
{
    stringstream ss;

    ss << hex << num;

    string result(ss.str());

    return result;
}