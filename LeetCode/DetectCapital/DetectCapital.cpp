#include <iostream>
#include <string>
#include <locale>
using namespace std;

bool detectCapitalUse(string word)
{
    int upperCaseLetters=0;
    
    const size_t wordSize=word.size();
    
    for(int index=0;index<wordSize;++index)
    {
        if(isupper(word[index]))
        {
            ++upperCaseLetters;
        }
    }
    
    if(upperCaseLetters==1)
    {
        return isupper(word[0]);
    }
    
    return upperCaseLetters==0 || upperCaseLetters==wordSize;
}