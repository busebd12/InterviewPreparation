#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

string removeKdigits(string & num, int k)
{
    int length=int(num.size());

    if(length==k)
    {
        return "0";
    }

    stack<char> stk;

    int i=0;

    while(i < length)
    {
        while(k > 0 && !stk.empty() && stk.top() > num[i])
        {
            stk.pop();

            k--;
        }

        stk.push(num[i]);

        i++;
    }

    while(k > 0)
    {
        stk.pop();

        k--;
    }

    string result{};

    while(!stk.empty())
    {
        result+=stk.top();

        stk.pop();
    }

    reverse(begin(result), end(result));

    while(result.size() > 1 && result[0]=='0')
    {
        result.erase(0, 1);
    }

    return result;
}