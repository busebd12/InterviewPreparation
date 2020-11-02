#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
 * Approaches:
 *
 * 1. We use a stringstream object to split the ip address by the '.' character. Then, for each number in the ip address,
 * we add it plus the new delimeter to our result string. Return our result string.
 *
 * Time complexity: O(n) [where n is the length of the string address]
 * Space complexity: O(n)
 *
 * 2. Iterate through the string address and if we see a non . character, we add it to our result string. Else, we add
 * the new delimeter, [.], to the result string. Return our result string.
 *
 * Time complexity: O(n) [where n is the length of the input string address]
 * Space complexity: O(r) [where r is the length of the result string (if we are counting the result as extra space. If not, O(1))]
 */

string defangIPaddr(string address)
{
    string result{};

    string buffer{};

    stringstream ss(address);

    char delimeter='.';

    string newDelimeter="[.]";

    while(getline(ss, buffer, delimeter))
    {
        result+=buffer;

        result+=newDelimeter;
    }

    int count=3;

    for(auto i=0;i<count;++i)
    {
        result.pop_back();
    }

    return result;
}

string defangIPaddr(string address)
{
    string result{};

    string delimeter="[.]";

    for(const char & character : address)
    {
        if(character!='.')
        {
            result+=character;
        }
        else
        {
            result+=delimeter;
        }
    }

    return result;
}