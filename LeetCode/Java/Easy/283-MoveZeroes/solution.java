import java.lang.String;
import java.util.Arrays;
import java.util.Deque;
import java.util.ArrayDeque;

/*
	Solutions:

	1. As we are iterating through the array, if we see a zero, we increment our zeroes counter variable.
	If we come across a non-zero value, then we move the value to the left in the array by the number
	zeroes we have counted so far. After the loop completes, we will have put all the non-zero values
	at the beginning of the array (while maintaining their original order) and all the zero values
	will be at the end of the array.

	Time complexity: O(n^2) [where n is the length of the input array]
	Space complexity: O(1)

	2. We make three passes through the array. On the first pass, we add all zero values to the end of a deque (double-ended queue).
	On the second pass, we iterate from the end of the array and add all non-zero values to the front of the deque as we iterate.
	For the third pass, we replace each value in the array with the correct one from the left-end of the deque.

	Time complexity: O(n) [where n is the length of the input array]
	Space complexity: O(n)

	3. As we are iterating through the array, we keep a count of the number of zero values.
	Every time we come across a non-zero value, we use the number of zeroes as an offset
	to determine the index at which we should put the non-zero value. On the second pass
	through the array, we simply put the correct number of zeroes at the end of the array.

	Time complexity: O(n) [where n is the length of the input array]
	Space complexity: O(1)
*/

class Solution
{
	public void swap(int[] nums, int front, int back)
	{
		int temp=nums[back];

		nums[back]=nums[front];

		nums[front]=temp;
	}

	public void moveZeroes(int[] nums)
	{
		if(nums==null || nums.length==0)
		{
			return;
		}

		int n=nums.length;

		int zeroes=0;

		for(int i=0;i<n;i++)
		{
			if(nums[i]==0)
			{
				zeroes++;
			}
			else
			{
				if(zeroes > 0)
				{
					int count=0;

					int front=i;

					int back=i-1;

					while(count < zeroes)
					{
						swap(nums, front, back);

						front--;

						back--;

						count++;
					}
				}
			}
		}
	}
}

class Solution
{
	public void moveZeroes(int[] nums)
	{
		if(nums==null || nums.length==0)
		{
			return;
		}

		Deque<Integer> dq=new ArrayDeque<>();

		int n=nums.length;

		for(int i=0;i<n;i++)
		{
			if(nums[i]==0)
			{
				dq.addFirst(nums[i]);
			}
		}

		for(int j=n-1;j>=0;j--)
		{
			if(nums[j]!=0)
			{
				dq.addFirst(nums[j]);
			}
		}

		for(int k=0;k<n&&!dq.isEmpty();k++)
		{
			nums[k]=dq.poll();
		}
	}
}

class Solution
{
    public void moveZeroes(int[] nums)
	{
		if(nums==null || nums.length==0)
		{
			return;
		}

		int n=nums.length;

		int zeroes=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                zeroes++;
            }
            else
            {
                nums[i - zeroes]=nums[i];
            }
        }
        
        for(int count=0;count<zeroes;count++)
        {
            nums[(n - 1) - count]=0;
        }
	}
}