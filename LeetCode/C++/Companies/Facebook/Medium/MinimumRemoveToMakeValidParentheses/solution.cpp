#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*

	Solution: as we iterate through the input string, if we see a '(' character, we push its numeric index onto our stack.
	If we see a ')' character, we check if the stack is empty. If it is not, then we know we have a valid pair of parentheses
	and we can remove the index of the corresponding '(' from the stack. If the stack is empty, then we have a mismatched ')'
	character and we mark it with the $ character. After iterating through the string, if the stack is not empty, then we have
	mismatched '(' characters as well. As we pop from the stack, we mark the mismatched '(' character with a $ using its index.
	Finally, we iterate over the original string and append all characters that are not $ to our result string, and return
	the resulting string.

	Time complexity: O(n) [where n is the length of the input string]
	Space conmplexity: O(n)

*/

class Solution
{
	public:
		string minRemoveToMakeValid(string s)
		{
			if(s.empty())
			{
				return s;
			}

			if(s.find('(')==std::string::npos && s.find(')')==std::string::npos)
			{
				return s;
			}

			stack<int> stk;

			int n=s.size();

			for(int index=0;index<n;index++)
			{
				char letter=s[index];

				if(letter=='(')
				{
					stk.push(index);
				}
				else if(letter==')')
				{
					if(!stk.empty())
					{
						stk.pop();
					}
					else
					{
						s[index]='$';
					}
				}
			}

			while(!stk.empty())
			{
				int index=stk.top();

				s[index]='$';

				stk.pop();
			}

			string result="";

			for(char & letter : s)
			{
				if(letter!='$')
				{
					result+=letter;
				}
			}

			return result;
		}
};