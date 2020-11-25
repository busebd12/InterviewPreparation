import java.util.Arrays;

/*
	Solutions:
	
	1. Allocate a third array that has space equal to m + n. Then, merge the elements from num1 and nums2 into the third array.
	Finally, copy all the elements from the third array into nums1.

	Time complexity: O(n + m)
	Space complexity: O(n + m)

	2. Start at index m-1 in the first array and n-1 in the second array, and merge the numbers from nums1 and nums2 into nums1 while iterating backwards through both arrays.

	Time complexity: O(n + m)
	Space complexity: O(1)
*/

class Solution
{
	public void merge(int[] nums1, int m, int[] nums2, int n)
	{
		int[] nums3=new int[m + n];

		int index=0;

		int i=0;

		int j=0;

		while(i < m && j < n)
		{
			if(nums1[i] <= nums2[j])
			{
				nums3[index]=nums1[i];

				i++;

				index++;
			}
			else
			{
				nums3[index]=nums2[j];

				j++;

				index++;
			}
		}

		while(i < m)
		{
			nums3[index]=nums1[i];

			i++;

			index++;
		}

		while(j < n)
		{
			nums3[index]=nums2[j];

			j++;

			index++;
		}

		for(int k=0;k<nums3.length;k++)
		{
			nums1[k]=nums3[k];
		}
	}
}

class Solution
{
	public void merge(int[] nums1, int m, int[] nums2, int n)
	{
		int index=(m + n) - 1;

		int i=m-1;

		int j=n-1;

		while(i >= 0 && j >= 0)
		{
			if(nums1[i] >= nums2[j])
			{
				nums1[index]=nums1[i];

				i--;

				index--;
			}
			else
			{
				nums1[index]=nums2[j];

				j--;

				index--;
			}
		}

		while(i >= 0)
		{
			nums1[index]=nums1[i];

			i--;

			index--;
		}

		while(j >= 0)
		{
			nums1[index]=nums2[j];

			j--;

			index--;
		}
	}
}