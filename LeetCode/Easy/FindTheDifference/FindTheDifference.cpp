#include <iostream>
#include <string>
using namespace std;

char findTheDifference(string s, string t)
{
    int asciiSum=0;

    for(auto & letter : t)
    {
        asciiSum+=int(letter);
    }

    for(auto & letter : s)
    {
        asciiSum-=int(letter);
    }
    
    if(asciiSum < 0)
    {
        asciiSum*=-1;
    }

    char answer=(char)asciiSum;

    return answer;
}