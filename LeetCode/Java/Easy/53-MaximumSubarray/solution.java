import java.lang.Math;
import java.util.Arrays;

/*
	Solution: use Kadane’s Algorithm. See the links below for explanations.
	https://hackernoon.com/kadanes-algorithm-explained-50316f4fd8a6
	https://en.wikipedia.org/wiki/Maximum_subarray_problem
	https://medium.com/@rsinghal757/kadanes-algorithm-dynamic-programming-how-and-why-does-it-work-3fd8849ed73d

	Time complexity: O(n) [where n is the length of the input nums array]
	Space complexity: O(1)
*/

class Solution
{
	public int maxSubArray(int[] nums)
    {
        if(nums==null || nums.length==0)
        {
        	return 0;
        }

        int n=nums.length;

        int result=nums[0];

        int currentSum=nums[0];

        for(int i=1;i<n;i++)
        {
        	int current=nums[i];

        	currentSum=Math.max((currentSum + current), current);

        	result=Math.max(result, currentSum);
        }

        return result;
    }
}