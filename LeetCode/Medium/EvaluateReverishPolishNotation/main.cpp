#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int evalRPN(vector<string> & tokens)
{
    stack<int> s;

    int tokensSize=int(tokens.size());

    for(int i=0;i<tokensSize;++i)
    {
        if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
        {
            int b=s.top();

            s.pop();

            int a=s.top();

            s.pop();

            if(tokens[i]=="+")
            {
                a=a+b;
            }
            else if(tokens[i]=="-")
            {
                a=a-b;
            }
            else if(tokens[i]=="*")
            {
                a=a*b;
            }
            else
            {
                a=a/b;
            }

            s.push(a);
        }
        else
        {
            s.push(stoi(tokens[i]));
        }
    }

    return s.top();
}