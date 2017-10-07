#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s)
{
	stack<char> Stack;

	size_t stringSize=s.size();

	for(int index=0;index<stringSize;++index)
	{
		//push any type of opening parenthesis on to the stack
		if(s[index]=='(' || s[index]=='[' || s[index]=='{')
		{
			Stack.push(s[index]);
		}
		//if we find any type of closing parenthesis, check top of stack for matching parenthesis
		//if we don't find one, not a valid parenthesis set; return false
		else if(s[index]==')' && !Stack.empty() && Stack.top()=='(')
		{
			Stack.pop();
		}
		else if(s[index]==']' && !Stack.empty() && Stack.top()=='[')
		{
			Stack.pop();
		}
		else if(s[index]=='}' && !Stack.empty() && Stack.top()=='{')
		{
			Stack.pop();
		}
		else
		{
			return false;
		}
	}

	//if we get here, the stack must be empty, meaning we were able to match all the parenthesis
	//so, Stack.empty() will return true
	return Stack.empty();
}