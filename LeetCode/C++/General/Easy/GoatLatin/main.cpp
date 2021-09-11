#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
 * Approach: follow the rules of goat latin provided below
 *
 * The rules of Goat Latin are as follows

    If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
    For example, the word 'apple' becomes 'applema'.

    If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
    For example, the word "goat" becomes "oatgma".

    Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
    For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
 *
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(n)
 *
 */

bool isVowel(char c)
{
    c=char(tolower(c));

    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

string toGoatLatin(string S)
{
    if(S.empty())
    {
        return S;
    }

    string result{};

    stringstream ss(S);

    string buffer{};

    int count=1;

    while(ss >> buffer)
    {
        if(isVowel(buffer[0]))
        {
            buffer+="ma";
        }
        else
        {
            reverse(buffer.begin(), buffer.end());

            char c=buffer.back();

            buffer.pop_back();

            reverse(buffer.begin(), buffer.end());

            buffer+=c;

            buffer+="ma";
        }

        for(int i=0;i<count;++i)
        {
            buffer+='a';
        }

        count++;

        result+=buffer;

        result+=" ";
    }

    result.pop_back();

    return result;
}