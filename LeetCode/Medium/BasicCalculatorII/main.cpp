#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
using namespace std;

void trimLeadingAndTrailingSpaces(string & s)
{
    size_t p=s.find_first_not_of(" \t");

    s.erase(0, p);

    p=s.find_last_not_of(" \t");

    if(p!=string::npos)
    {
        s.erase(p+1);
    }
}

int calculate(string & s)
{
    int answer=0;

    if(s.empty())
    {
        return answer;
    }

    auto end_position=remove(s.begin(), s.end(), ' ');

    s.erase(end_position, s.end());

    trimLeadingAndTrailingSpaces(s);

    if(s.empty())
    {
        return answer;
    }

    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='*')
        {
            s[i]='M';
        }
        if(s[i]=='/')
        {
            s[i]='D';
        }
        if(s[i]=='+')
        {
            s[i]='A';
        }
        if(s[i]=='-')
        {
            s[i]='S';
        }
    }

    deque<char> dq;

    int i=0;

    while(i < s.size())
    {
        if(s[i]=='M' || s[i]=='D')
        {
            string first{};

            while(dq.back() != 'M' && dq.back() != 'D' && dq.back() != 'A' && dq.back() != 'S')
            {
                first+=dq.back();

                dq.pop_back();

                if(dq.empty())
                {
                    break;
                }
            }

            reverse(first.begin(), first.end());

            int start=i+1;

            string second{};

            while(s[start]!='M' && s[start]!='D' && s[start]!='A' && s[start]!='S')
            {
                second+=s[start];

                if(start==s.size() - 1)
                {
                    break;
                }

                ++start;
            }

            int firstAsNumber=stoi(first);

            int secondAsNumber=stoi(second);

            int result=0;

            if(s[i]=='M')
            {
                result = firstAsNumber * secondAsNumber;
            }
            else
                result = firstAsNumber / secondAsNumber;
            }

            string resultAsString=to_string(result);

            const int resultLength=int(resultAsString.length());

            for(int index=0;index<resultLength;++index)
            {
                dq.push_back(resultAsString[index]);
            }

            i=start;

            if (i == s.size() - 1)
            {
                break;
            }
        }
        else
        {
            dq.push_back(s[i]);

            ++i;
        }
    }

    s.clear();

    while(!dq.empty())
    {
        s+=dq.front();

        dq.pop_front();
    }

    int j=0;

    while(j < s.size())
    {
        if(s[j]=='A' || s[j]=='S')
        {
            string first{};

            while(dq.back()!='M' && dq.back()!='D' && dq.back()!='A' && dq.back()!='S')
            {
                first+=dq.back();

                dq.pop_back();

                if(dq.empty())
                {
                    break;
                }
            }

            reverse(first.begin(), first.end());

            int start=j+1;

            string second{};

            while(s[start]!='M' && s[start]!='D' && s[start]!='A' && s[start]!='S')
            {
                second+=s[start];

                if(start==s.size()-1)
                {
                    break;
                }

                ++start;
            }

            int firstAsNumber=stoi(first);

            int secondAsNumber=stoi(second);

            int result;

            if(s[j]=='A')
            {
                result=firstAsNumber + secondAsNumber;
            }
            else
            {
                result=firstAsNumber - secondAsNumber;
            }

            string resultAsString=to_string(result);

            const int resultLength=int(resultAsString.length());

            for(int index=0;index<resultLength;++index)
            {
                dq.push_back(resultAsString[index]);
            }

            j=start;

            if(j==s.size()-1)
            {
                break;
            }
        }
        else
        {
            dq.push_back(s[j]);

            ++j;
        }
    }

    s.clear();

    while(!dq.empty())
    {
        s+=dq.front();

        dq.pop_front();
    }

    answer=stoi(s);

    return answer;
}