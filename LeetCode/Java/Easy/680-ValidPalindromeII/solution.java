import java.lang.String;
import java.lang.StringBuilder;
import java.util.Arrays;

/*
	Solutions:

	1. As we iterate over the string, we create a copy of the string using a StringBuilder and delete the character at the current index.
	We then check if the StringBuilder is a palindrome. After iterating over the string, if we haven't found a palindrome, then we can't
	delete any one character from the string and create a palindrome.

	Time complexity: O(n^2) [where n is the length of the input string]
	Space complexity: O(n)

	2. Same logic as the first solution except that we use the string substring method instead of a StringBuilder object to
	create the string copy with just one character missing for each iteration.

	Time complexity: O(n^2) [where n is the length of the input string]
	Space complexity: O(n)

	3. As we iterate over the string, from both the left and the right, if we come across two characters that are not the same,
	then we have an opportunity to erase each one and check if the resulting string is a palindrome. However, instead of erasing
	each character, we simply skip each character's index when we iterate over the resulting string to check if it's a palindrome.

	Time complexity: O(n)
	Space complexity: O(1)
*/

class Solution
{
	public boolean isPalindrome(StringBuilder sb)
	{
		int m=sb.length();

		int left=0;

		int right=m - 1;

		while(left < right)
		{
			if(sb.charAt(left)!=sb.charAt(right))
			{
				return false;
			}

			left++;

			right--;
		}

		return true;
	}

	public boolean validPalindrome(String s)
    {
        int n=s.length();

        for(int i=0;i<n;i++)
        {
        	StringBuilder sb=new StringBuilder(s);

        	sb.deleteCharAt(i);

        	if(isPalindrome(sb))
        	{
        		return true;
        	}
        }

        return false;
    }
}

class Solution
{
	public boolean isPalindrome(String str)
	{
		int m=str.length();

		int left=0;

		int right=m - 1;

		while(left < right)
		{
			if(str.charAt(left)!=str.charAt(right))
			{
				return false;
			}

			left++;

			right--;
		}

		return true;
	}

	public boolean validPalindrome(String s)
    {
        int n=s.length();

        for(int i=0;i<n;i++)
        {
        	String str=s.substring(0, i) + s.substring(i + 1);

        	if(isPalindrome(str))
        	{
        		return true;
        	}
        }

        return false;
    }
}

class Solution
{
	public boolean isPalindrome(String str, int left, int right)
	{
		while(left < right)
		{
			if(str.charAt(left)!=str.charAt(right))
			{
				return false;
			}

			left++;

			right--;
		}

		return true;
	}

	public boolean validPalindrome(String s)
    {
        int n=s.length();

        int left=0;

        int right=n - 1;

        while(left < right)
        {
        	if(s.charAt(left)!=s.charAt(right))
        	{
        		return isPalindrome(s, left, right - 1) || isPalindrome(s, left + 1, right);
        	}

        	left++;

        	right--;
        }

        return true;
    }
}