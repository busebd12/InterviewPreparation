#include <iostream>
#include <string>
using namespace std;

/*
 * Approach: loop over the input string and if the current letter is not a vowel, add it to our result string.
 * Return our result string.
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(n - v) [where n is the length of the input string and v is the number of vowels in the input string]
 */

bool isVowel(const char & c)
{
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

string removeVowels(string S)
{
    if(S.empty())
    {
        return S;
    }

    string result{};

    for(const auto & character : S)
    {
        if(!isVowel(character))
        {
            result+=character;
        }
    }

    return result;
}