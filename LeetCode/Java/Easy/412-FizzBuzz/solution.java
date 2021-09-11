import java.lang.String;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

/*
	Solution: we loop from [1, n] inclusive and make the necessary checks for divisibility by 3, 5, both 3 and 5, and other, and add the appropriate string to our result list.

	Time complexity: O(n) [where n is the input integer]
	Space complexity: O(n) [if we count the result list as extra space]; O(1) [if we don't count the result list as extra space]
*/

class Solution
{
	List<String> fizzBuzz(int n)
	{
		List<String> result=new ArrayList<>();

		for(int number=1;number<=n;number++)
		{
			if((number % 3)==0)
			{
				if((number % 5)==0)
				{
					result.add("FizzBuzz");
				}
				else
				{
					result.add("Fizz");
				}
			}
			else if((number % 5)==0)
			{
				result.add("Buzz");
			}
			else
			{
				result.add(String.valueOf(number));
			}
		}

		return result;
	}
}