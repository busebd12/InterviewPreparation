import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/*
	Solution: for each number in the input array, nums, we calculate the value that, when added to
	the current number, will total the target number we are trying to reach. Then, we check to see
	if the current number is in the HashMap, then we know that this number is the missing value
	that a prior number needed to sum with in order to reach the target value. So, we set the
	0th index of our result array with the index of the prior number and the 1st index equal
	to the index of the current number. Else, we insert the difference and the current index
	into the HashMap.

	Time complexity: O(n) [where n is the length of the input array, nums]
	Space complexity: O(n) [where n is the length of the input array, nums]
*/

class Solution
{
	public int[] twoSum(int [] nums, int target)
	{
		int[] result=new int[2];

		if(nums==null || nums.length==0)
		{
			return result;
		}

		Map<Integer, Integer> hashtable=new HashMap<>();

		for(int i=0;i<nums.length;i++)
		{
			int difference=target - nums[i];

			if(hashtable.containsKey(nums[i]))
			{
				result[0]=hashtable.get(nums[i]);

				result[1]=i;
			}
			else
			{
				hashtable.put(difference, i);
			}
		}

		return result;
	}
}