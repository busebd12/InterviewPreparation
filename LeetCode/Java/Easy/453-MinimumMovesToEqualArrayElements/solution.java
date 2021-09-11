import java.lang.String;
import java.util.Arrays;

/*
	Solution: Incrementing all but one element is equivalent to decrementing that one element. So let's do that instead.
	How many single-element decrements to make all equal? No point to decrementing below the current minimum.
	If we did that, then we would have to then make more moves by changing the minimum value (since it would no longer be the minimum)
	and we can't change all values in the array at once, just all but one. So how many single-element decrements to make all equal to the current minimum?
	Just find the minimum and for each element add the difference between the current element and the minimum to the total moves.

	Time complexity: O(n) [where n is the total number of elements in the input vector]
	Space complexity: O(1)
*/

class Solution
{
	int getMinimum(int[] nums)
	{
		int minimum=nums[0];

		for(int number : nums)
		{
			if(number < minimum)
			{
				minimum=number;
			}
		}

		return minimum;
	}

	public int minMoves(int[] nums)
	{
		int result=0;

		if(nums==null || nums.length==0)
		{
			return result;
		}

		int minimum=getMinimum(nums);

		for(int number : nums)
		{
			result+=(number - minimum);
		}

		return result;
	}
}