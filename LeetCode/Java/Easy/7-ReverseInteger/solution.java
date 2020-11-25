import java.lang.Integer;
import java.lang.String;
import java.lang.StringBuilder;

/*
	Solution: we first create a long copy of the input integer value. Then, we check if the input value is negative.
	If it is, we make it positive and set our flag variable to true. Then, we simply take the digits from the input
	number and form the reverse value and store it in a long. Next, we multiply the result by -1 if our isNegative flag
	is true. Finally, we check to if the value overflows the range of an integer. If it does, we return zero. Else,
	we return the result cast as an integer.

	Time complexity: O(d) [where d is the number of digits in the input number]
	Space complexity: O(1)
*/

class Solution
{
	public int reverse(int x)
	{
		boolean isNegative=false;

		long copy=x;

		if(copy < 0)
		{
			isNegative=true;

			copy*=-1;
		}

		long result=0;

		while(copy > 0)
		{
			result*=10;

			result+=(copy % 10);

			copy/=10;
		}

		if(isNegative)
		{
			result*=-1;
		}

		return (result > Integer.MAX_VALUE || result < Integer.MIN_VALUE) ? 0 : (int)result;
	}
}