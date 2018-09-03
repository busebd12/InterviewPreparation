#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

string trimLeadingAndTrailingSpaces(string str)
{
    if(str.empty())
    {
        return str;
    }

    size_t start=str.find_first_not_of(' ');

    size_t first=((start==string::npos) ? str.length() : start);

    size_t last=str.find_last_not_of(' ');

    return str.substr(first, last-first+1);
}

void reverseWords(string & s)
{
    if(s.empty())
    {
        return;
    }

    s=trimLeadingAndTrailingSpaces(s);

    if(s.length() <= 1)
    {
        return;
    }

    string word{};

    stack<string> words;

    for(int i=0;i<s.length();++i)
    {
        if(isspace(s[i]))
        {
            if(!word.empty())
            {
                words.push(word);

                word.clear();
            }
        }
        else
        {
            word+=s[i];

            if(i==s.length()-1)
            {
                words.push(word);

                word.clear();
            }
        }
    }

    s.clear();

    while(!words.empty())
    {
        word=words.top();

        if(words.size()==1)
        {
            s+=word;
        }
        else
        {
            s+=(word + " ");
        }

        words.pop();
    }
}