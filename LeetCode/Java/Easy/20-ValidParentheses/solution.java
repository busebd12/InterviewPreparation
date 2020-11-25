import java.lang.String;
import java.util.Stack;

/*
	Solution: as we iterate over the string, we push any opening (, {, or ']' characters
	onto a stack. Then, for any ')', '}', or ']' characters, if the stack is not empty,
	we remove the top character if it matches the current closing character. Else,
	we return false. After looping through the string, we return true or fasle, depending
	on whether the stack is empty (the stack not being empty would be a case such as "(((((").
	Some edge cases to be aware of is if the string is null or empty.

	Time complexity: O(n) [where n is the length of the input string]
	Space complexity: O(n)
*/

class Solution
{
	public boolean isValid(String s)
	{
		if(s==null || s.isEmpty())
		{
			return true;
		}

		int n=s.length();

		Stack<Character> stack=new Stack<>();

		for(int index=0;index<n;index++)
		{
			char c=s.charAt(index);

			if(c=='(' || c=='{' || c=='[')
			{
				stack.push(c);
			}
			else if(c==')')
			{
				if(!stack.empty() && stack.peek()=='(')
				{
					stack.pop();
				}
				else
				{
					return false;
				}
			}
			else if(c=='}')
			{
				if(!stack.empty() && stack.peek()=='{')
				{
					stack.pop();
				}
				else
				{
					return false;
				}
			}
			else if(c==']')
			{
				if(!stack.empty() && stack.peek()=='[')
				{
					stack.pop();
				}
				else
				{
					return false;
				}
			}
		}

		return stack.empty();
	}
}