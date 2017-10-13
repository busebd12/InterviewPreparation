#include <iostream>
#include <string>
#include <cstdlib>
#include <locale>
#include <algorithm>
#include <cctype>

int myAtoi(string str)
{
    if(str.empty())
    {
        return 0;
    }

    str.erase(str.begin(), find_if(str.begin(), str.end(), [](int ch)
    {
        return !isspace(ch);
    }));

    bool isNegative=false;
    
    if(str.size() >= 2)
    {
        if((str[0]=='+' && str[1]=='-') || (str[0]=='-' && str[1]=='+') || (str[0]=='-' && str[1]=='-') || (str[0]=='+' && str[1]=='+'))
        {
            return 0;
        }
    }

    if(str[0]=='-')
    {
        isNegative=true;
    }

    long answer=0;
    
    const size_t stringSize=str.size();

    if(isNegative)
    {
        for(int index=0;index<stringSize;++index)
        {   
            if(index==0)
            {
                if(!isdigit((unsigned char)str[index]) && str[index]!='+' && str[index]!='-')
                {   
                    break;
                }
                else
                {
                    if(str[index]=='+' || str[index]=='-')
                    {
                        continue;
                    }
                    else
                    {
                        answer*=10;
                    
                        answer+=str[index]-'0';
                    }
                }
            }
            else
            {
                if(isdigit((unsigned char)str[index]))
                {
                    answer*=10;

                    answer+=str[index]-'0';

                    if(answer > 0)
                    {
                        answer*=-1;
                    }

                    if(answer < numeric_limits<int>::min())
                    {
                        return numeric_limits<int>::min();
                    }
                    else
                    {
                        answer*=-1;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }
    else
    {   
        for(int index=0;index<stringSize;++index)
        {
            if(index==0)
            {
                if(!isdigit((unsigned char)str[index]) && str[index]!='+' && str[index]!='-')
                {
                    break;
                }
                else
                {
                    if(str[index]=='+' || str[index]=='-')
                    {
                        continue;
                    }
                    else
                    {
                        answer*=10;
                    
                        answer+=str[index]-'0';
                    }
                }
            }
            else
            {
                if(isdigit((unsigned char)str[index]))
                {
                    answer*=10;

                    answer+=str[index]-'0';

                    if(answer > numeric_limits<int>::max())
                    {
                        return numeric_limits<int>::max();
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }

    if(isNegative)
    {
        answer*=-1;
    }

    return (int)answer;
}