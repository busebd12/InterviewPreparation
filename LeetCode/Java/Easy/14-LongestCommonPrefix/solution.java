import java.lang.Math;
import java.lang.String;
import java.lang.StringBuilder;
import java.util.Arrays;

/*
	Solution: the algorithm works as follows

	1. Edge cases: null or empty array --> return empty string

	2. Check for any empty strings within the array. If there are, then the longest common prefix will be the empty string.

	3. Edge case: the array only has one string --> return that one string

	4. Core part --> we move through each string from beginning to end, comparing each letter at the same index within all strings against one another
	until we reach an index where the letters are not all the same. After comparing all letters at a given index and finding that they are all the same,
	we append that common letter to our StringBuilder object. Note that the outer while loop only runs till we reach the end of the shortest string within
	the array as the longest common prefix cannot be longer than the shorted string within the array.

	5. Return our String result.

	Time complexity: O(n + (l * n)) [where n is the length of the input String array and l is the length of the smallest string from the array]
	Space complexity: O(length of the longest common prefix) [if we are counting the output as extra space] O(1) [if we are not counting the output as extra space]
*/

class Solution
{
	public String longestCommonPrefix(String[] strs)
	{
		StringBuilder sb=new StringBuilder();

		if(strs==null || strs.length==0)
		{
			return sb.toString();
		}

		int n=strs.length;
        
        boolean anyEmptyStrings=false;
        
        for(int i=0;i<n;i++)
        {
            if(strs[i].isEmpty())
            {
                anyEmptyStrings=true;
                
                break;
            }
        }
        
        if(anyEmptyStrings)
        {
            return sb.toString();
        }
        
        if(n==1)
        {
            return strs[0];
        }

		int smallestStringLength=strs[0].length();

		for(int i=1;i<n;i++)
		{
			smallestStringLength=Math.min(smallestStringLength, strs[i].length());
		}

		int length=0;

		int index=0;

		char current=strs[0].charAt(0);

		boolean done=false;

		while(length < smallestStringLength && !done)
		{
			for(int i=0;i<n;i++)
			{
				if(strs[i].charAt(index)!=current)
				{
					done=true;

					break;
				}
			}

			if(done)
			{
				break;
			}

			sb.append(current);

			index++;
            
            if(index < smallestStringLength)
            {
                current=strs[0].charAt(index);
            }

			length++;
		}

		return sb.toString();
	}
}