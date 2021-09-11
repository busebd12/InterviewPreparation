#include <iostream>
#include <string>
using namespace std;

/*
 * Approach: There are two overall cases. The string has capital letters or it does not.
 * If it does, then we have to sub-cases. First, if there is only one capitalized letter,
 * then it can only be the first letter of the word. If there are more than one capitalized
 * letters, then all the letters have to be capitalized. If the string has no capitalized letters,
 * then we are all good.
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(1)
 *
 */

bool isCapitalLetter(char letter)
{
    int number=int(letter);

    return (number >= 65 && number <= 90);
}

bool detectCapitalUse(string word)
{
    if(word.empty())
    {
        return true;
    }

    bool result=false;

    int capitalLetters=0;

    for(char letter : word)
    {
        if(isCapitalLetter(letter))
        {
            capitalLetters++;
        }
    }

    if(capitalLetters > 0)
    {
        if(capitalLetters==1)
        {
            result=isCapitalLetter(word[0]);
        }
        else
        {
            result=(capitalLetters==word.size()) ? true : false;
        }
    }
    else
    {
        result=true;
    }

    return result;
}