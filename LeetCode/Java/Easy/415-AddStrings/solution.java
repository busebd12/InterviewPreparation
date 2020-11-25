import java.lang.String;
import java.lang.StringBuilder;

/*
	Solution: we are just writing the code version of the way we add numbers on paper in base 10.

	Time complexity: O(n + m) [where n is the length of num1 and m is the length of num2]
	Space complexity: O(s) [where s is the length of the resulting sum string]
*/

class Solution
{
	public String addStrings(String num1, String num2)
	{
		StringBuilder sb=new StringBuilder();

		int n=num1.length();

		int m=num2.length();

		int i=n-1;

		int j=m-1;

		int carry=0;

		while(i >= 0 && j >= 0)
		{
			int total=(num1.charAt(i) - '0') + (num2.charAt(j) - '0') + carry;

			carry=total/10;

			sb.append(total % 10);

			i--;

			j--;
		}

		while(i >= 0)
		{
			int total=(num1.charAt(i) - '0') + carry;

			carry=total/10;

			sb.append(total % 10);

			i--;
		}

		while(j >= 0)
		{
			int total=(num2.charAt(j) - '0') + carry;

			carry=total/10;

			sb.append(total % 10);

			j--;
		}

		if(carry > 0)
		{
			sb.append(carry);
		}

		sb.reverse();

		return sb.toString();
	}
}