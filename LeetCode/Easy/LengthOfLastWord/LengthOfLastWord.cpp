#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s)
{
    if(s.empty())
    {
        return 0;
    }

    const size_t stringSize=s.size();
    
    int length{};
    
    int lastLength{};

    for(int index=0;index<stringSize;++index)
    {
        if(isspace(s[index]))
        {
            length=0;
        }
        else
        {
            ++length;
            
            lastLength=length;
        }
    }

    return lastLength;
}