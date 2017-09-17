#include <iostream>
#include <string>
using namespace std;

bool checkRecord(string s)
{
    if(s.empty())
    {
        return true;
    }

    const size_t stringSize=s.size();

    int aCount=0;

    int continuousLs=0;

    int lCount=0;

    for(int index=0;index<stringSize;++index)
    {
        char letter=s[index];

        if(index==stringSize-1)
        {
            if(letter=='L')
            {
                ++lCount;
            }
            else if(letter=='A')
            {
                ++aCount;
            }

            if(lCount > continuousLs)
            {
                continuousLs=lCount;
            }
            
            lCount=0;
        }
        else if(letter=='A')
        {
            ++aCount;

            if(index > 0)
            {
                char previousLetter=s[index-1];

                if(previousLetter=='L')
                {  
                    if(lCount > continuousLs)
                    {
                        continuousLs=lCount;
                    }
                    
                    lCount=0;
                }
            }
        }
        else if(letter=='P')
        {
            if(index > 0)
            {
                char previousLetter=s[index-1];

                if(previousLetter=='L')
                {   
                    if(lCount > continuousLs)
                    {
                        continuousLs=lCount;
                    }
                    
                    lCount=0;
                }
            }
        }
        else
        {
            ++lCount;
        }
    }
    
    if(aCount <= 1 && continuousLs > 2)
    {
        return false;
    }
    else if(aCount <= 1 && continuousLs <= 2)
    {
        return true;
    }
    else if(aCount > 1 && continuousLs > 2)
    {
        return false;
    }
    else if(aCount > 1 && continuousLs <= 2)
    {
        return false;
    }
}