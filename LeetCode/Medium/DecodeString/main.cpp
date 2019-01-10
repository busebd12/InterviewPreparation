#include <iostream>
#include <string>
#include <cctype>
#include <stack>
using namespace std;

string decodeString(string s)
{
    int length=int(s.length());

    int index=0;

    stack<char> stk;

    while(index < length)
    {
        if(s[index]!=']')
        {
            stk.push(s[index]);
        }
        else
        {
            string str{};

            while(!stk.empty() && isalpha(stk.top()))
            {
                char c=stk.top();

                str+=c;

                stk.pop();
            }

            reverse(str.begin(), str.end());

            if(!stk.empty())
            {
                stk.pop();
            }

            string k{};

            while(!stk.empty() && isdigit(stk.top()))
            {
                char c=stk.top();

                k+=c;

                stk.pop();
            }

            reverse(k.begin(), k.end());

            int kNum=stoi(k);

            string result{};

            for(int i=0;i<kNum;++i)
            {
                result+=str;
            }

            for(auto & letter : result)
            {
                stk.push(letter);
            }
        }

        ++index;
    }

    string answer{};

    while(!stk.empty())
    {
        answer+=stk.top();

        stk.pop();
    }

    reverse(answer.begin(), answer.end());

    return answer;
}