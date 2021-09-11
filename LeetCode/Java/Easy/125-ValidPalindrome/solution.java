import java.lang.Character;
import java.lang.String;
import java.util.Arrays;

/*
	Solution: the algorithm works as follows

		1. Edge/Corner case checking --> null or empty string

		2. Store the length of the string and create our two "pointers", start and end

		3. while start is less than end, we do the following
			a. Conver the characters pointed to by start and end to lowercase

			b. Check if either the letter s.charAt(left) or s.charAt(right) is not alphanumeric.
			Return false if this is the case.

			c. If the characters are alphanumeric, then make sure that they are equal.
			If they are not, return false. Move the start and end "pointers".

		4. After iterating over the input string, if we didn't return false, then the string must be
		a valid palindrome and return true.

	Time complexity: O(n) [where n is the length of the input string]
	Space complexity: O(1)
*/

class Solution
{
	public boolean isPalindrome(String s)
    {
        if(s==null || s.isEmpty())
        {
        	return true;
        }

        int n=s.length();

        int start=0;

        int end=n-1;

        while(start < end)
        {
        	char left=Character.toLowerCase(s.charAt(start));

        	char right=Character.toLowerCase(s.charAt(end));

        	if(!Character.isLetterOrDigit(left))
        	{
        		start++;
        	}
        	else if(!Character.isLetterOrDigit(right))
        	{
        		end--;
        	}
        	else
        	{
        		if(left!=right)
        		{
        			return false;
        		}

        		start++;

        		end--;
        	}
        }

        return true;
    }
}