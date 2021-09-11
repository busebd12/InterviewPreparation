import java.lang.String;
import java.lang.StringBuilder;
import java.util.Arrays;

/*
	Solutions:

	1. We iterate over the two strings, a and b, from left-to-right peforming grade school addition as we go.
	We keep track of a carry value as we perform the addition for the cases where the total is greater than 1.
	The key difference  here is that we are in base-2, not base-10, so the carry value will either be 0 or 1,
	same with the value we append to our StringBuilder object after doing the addition. After looping through
	both strings, if one was longer than the other, we finish the addition using the remainder of that string.
	At this point, if the carry value is greater than zero, then we need to append it to the StringBuilder
	object.Then, we reverse the StringBuilder object and return the String version.

	Time complexity: O(n + m) [where n is the length of string a and m is the length of string b]
	Space complexity: O(space required to hold the sum string) [if you count the output as extra space] O(1) [if you don't count the output as extra space]

	2. Almost the same as the first solution except that we don't have specific cases for the sum of two characters from a and b and the carry
	value being greater than 1. Instead, we use the % operator to determine the value we append to the StringBuilder object and to set as the
	carry value.

	Time complexity: O(n + m) [where n is the length of string a and m is the length of string b]
	Space complexity: O(space required to hold the sum string) [if you count the output as extra space] O(1) [if you don't count the output as extra space]
*/

class Solution
{
    public String addBinary(String a, String b)
    {
        if((a==null || a.isEmpty()) && (b==null || b.isEmpty()))
        {
        	return "";
        }

        if(a==null || a.isEmpty())
        {
        	return b;
        }

        if(b==null || b.isEmpty())
        {
        	return a;
        }

        StringBuilder sb=new StringBuilder();

        int n=a.length();

        int m=b.length();

        int i=n-1;

        int j=m-1;

        int carry=0;

        while(i >= 0 && j >= 0)
        {
        	int total=(a.charAt(i) - '0') + (b.charAt(j) - '0') + carry;

        	if(total==3)
        	{
        		carry=1;

        		sb.append(1);
        	}
            else if(total==2)
            {
                carry=1;
                
                sb.append(0);
            }
        	else
        	{
        		sb.append(total);

        		carry=0;
        	}

        	i--;

        	j--;
        }

        while(i >= 0)
        {
        	int total=(a.charAt(i) - '0') + carry;

        	if(total==3)
        	{
        		carry=1;

        		sb.append(1);
        	}
            else if(total==2)
            {
                carry=1;
                
                sb.append(0);
            }
        	else
        	{
        		sb.append(total);

        		carry=0;
        	}

        	i--;
        }

        while(j >= 0)
        {
        	int total=(b.charAt(j) - '0') + carry;

        	if(total==3)
        	{
        		carry=1;

        		sb.append(1);
        	}
            else if(total==2)
            {
                carry=1;
                
                sb.append(0);
            }
        	else
        	{
        		sb.append(total);

        		carry=0;
        	}

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

class Solution
{
    public String addBinary(String a, String b)
    {
        if((a==null || a.isEmpty()) && (b==null || b.isEmpty()))
        {
        	return "";
        }

        if(a==null || a.isEmpty())
        {
        	return b;
        }

        if(b==null || b.isEmpty())
        {
        	return a;
        }

        StringBuilder sb=new StringBuilder();

        int n=a.length();

        int m=b.length();

        int i=n-1;

        int j=m-1;

        int carry=0;

        while(i >= 0 && j >= 0)
        {
        	int total=(a.charAt(i) - '0') + (b.charAt(j) - '0') + carry;

        	carry=total/2;
            
            sb.append(total % 2);

        	i--;

        	j--;
        }

        while(i >= 0)
        {
        	int total=(a.charAt(i) - '0') + carry;

        	carry=total/2;
            
            sb.append(total % 2);

        	i--;
        }

        while(j >= 0)
        {
        	int total=(b.charAt(j) - '0') + carry;

        	carry=total/2;
            
            sb.append(total % 2);

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