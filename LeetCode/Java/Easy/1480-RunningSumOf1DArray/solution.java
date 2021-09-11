import java.lang.String;
import java.util.Arrays;

/*
	Solution: the algorithm works as follows

	1. Check for edge cases --> input array is null or empty

	2. Create the result array having the same size as the input array

	3. Since the first element of the running sum will be just the first number in the input array, set the result[0] value appropriately

	4. Use a for loop to calculate the rest of the running sum values. They key is to realize that each value is calculated by adding
	the previous running sum value with the current number in nums.

	5. Return the result array

	Time complexity: O(n) [where n is the length of the input array]
	Space complexity: O(n) [if you count the output as extra space] O(1) [if you don't count the output as extra space]
*/

class Solution
{
	public int[] runningSum(int[] nums)
	{
		if(nums==null || nums.length==0)
		{
			return new int[0];
		}

		int n=nums.length;

		int[] result=new int[n];

		result[0]=nums[0];

		for(int i=1;i<n;i++)
		{
			result[i]=result[i - 1] + nums[i];
		}

		return result;
	}
}