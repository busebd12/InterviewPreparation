#include <iostream>
#include <string>
using namespace std;

int countSegments(string s)
{
    if(s.empty())
    {
        return 0;
    }
    
    const size_t stringSize=s.size();
    
    int nonSpaceCharacters=0;
    
    int totalCharacters=0;
    
    for(const auto & element : s)
    {
        ++totalCharacters;
        
        if(!isspace(element))
        {
            ++nonSpaceCharacters;
        }
    }
    
    if(nonSpaceCharacters==stringSize)
    {
        return 1;
    }
    
    int spaceCount=0;
    
    int segments=0;
    
    int characterCount=0;
    
    for(int index=0;index<stringSize;++index)
    {
        if(isspace(s[index]))
        {
            if(characterCount > 0 && characterCount < totalCharacters && spaceCount==0)
            {
                ++segments;
            }
            
            ++spaceCount;
        }
        else
        {
            if(index==stringSize-1 && !isspace(s[index]))
            {
                ++segments;
            }
            else
            {
                if(spaceCount > 0)
                {
                    spaceCount=0;
                }
            }
        }
        
        ++characterCount;
    }
    
    return segments;
}