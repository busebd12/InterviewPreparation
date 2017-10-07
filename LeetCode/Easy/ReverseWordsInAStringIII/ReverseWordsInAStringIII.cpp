#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

string reverseWords(string s)
{
    if(s.empty())
    {
        return s;
    }
    
    const size_t stringSize=s.size();
    
    for(int i=0, j=0;j<stringSize;)
    {
        char letter=s[j];

        if(j==stringSize-1)
        {
            if(!isspace(s[i]) && !isspace(s[j]))
            {
                reverse(begin(s)+i, end(s)-(stringSize-(j+1)));
            }
        }

        if(isspace(letter))
        {
            --j;

            reverse(begin(s)+i, end(s)-(stringSize-(j+1)));

            j+=2;

            i=j;
        }
        else
        {
            ++j;
        }
    }

    return s;
}