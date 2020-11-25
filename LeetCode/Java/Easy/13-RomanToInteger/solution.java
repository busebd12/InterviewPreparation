import java.lang.String;
import java.util.Arrays;
import java.util.HashMap;

/*
	Solutions:

	1. We use a HashMap to map all the character combinations we want fast access for to their numeric values.
	Then, we iterate through the string each character or pair of characters in the case of 'IV', 'IX', etc to their
	numeric value and add that value to our result variable. Then, after we are done iterating, we simply return our result.

	Time complexity: O(n) [where n is the length of the input string]
	Space complexity: 13 entires into our HashMap => O(13) => O(1)

	2. Practically identical logic to the first solution except that we use a function to compute the numeric value of single or double letters instead of our HashMap.

	Time complexity: O(n) [where n is the lenth of the input string]
	Space complexity: O(1)
*/

class Solution
{
	public int romanToInt(String s)
	{
		int result=0;

		if(s==null || s.isEmpty())
		{
			return result;
		}

		int n=s.length();

		HashMap<String, Integer> hashtable=new HashMap<>();

		hashtable.put("I", 1);

		hashtable.put("V", 5);

		hashtable.put("X", 10);

		hashtable.put("L", 50);

		hashtable.put("C", 100);

		hashtable.put("D", 500);

		hashtable.put("M", 1000);

		hashtable.put("IV", 4);

		hashtable.put("IX", 9);

		hashtable.put("XL", 40);

		hashtable.put("XC", 90);

		hashtable.put("CD", 400);

		hashtable.put("CM", 900);

		for(int i=0;i<n;)
		{
			char character=s.charAt(i);

			if(character=='I')
			{
				if((i + 1) < n)
				{
					if(s.charAt(i + 1)=='V')
					{
						result+=hashtable.get("IV");

						i+=2;
					}
					else if(s.charAt(i + 1)=='X')
					{
						result+=hashtable.get("IX");

						i+=2;
					}
					else
					{
						result+=hashtable.get(String.valueOf(character));

						i++;
					}
				}
				else
				{
					result+=hashtable.get(String.valueOf(character));

					i++;
				}
			}
			else if(character=='X')
			{
				if((i + 1 < n))
				{
					if(s.charAt(i + 1)=='L')
					{
						result+=hashtable.get("XL");

						i+=2;
					}
					else if(s.charAt(i + 1)=='C')
					{
						result+=hashtable.get("XC");

						i+=2;
					}
					else
					{
						result+=hashtable.get(String.valueOf(character));

						i++;
					}
				}
				else
				{
					result+=hashtable.get(String.valueOf(character));

					i++;
				}
			}
			else if(character=='C')
			{
				if((i + 1 < n))
				{
					if(s.charAt(i + 1)=='D')
					{
						result+=hashtable.get("CD");

						i+=2;
					}
					else if(s.charAt(i + 1)=='M')
					{
						result+=hashtable.get("CM");

						i+=2;
					}
					else
					{
						result+=hashtable.get(String.valueOf(character));

						i++;
					}
				}
				else
				{
					result+=hashtable.get(String.valueOf(character));

					i++;
				}
			}
			else
			{
				result+=hashtable.get(String.valueOf(character));

				i++;
			}
		}

		return result;
	}
}

class Solution
{
    public int getValue(String s)
    {
        switch(s)
        {
            case "I":
                return 1;
                
            case "V":
                return 5;
                
            case "X":
                return 10;
                
            case "L":
                return 50;
                
            case "C":
                return 100;
                
            case "D":
                return 500;
                
            case "M":
                return 1000;
                
            case "IV":
                return 4;
                
            case "IX":
                return 9;
                
            case "XL":
                return 40;
                
            case "XC":
                return 90;
                
            case "CD":
                return 400;
                
            case "CM":
                return 900;
                
            default:
                return 0;
        }
    }
    
    public int romanToInt(String s)
    {
        int result=0;

		if(s==null || s.isEmpty())
		{
			return result;
		}

		int n=s.length();

		for(int i=0;i<n;)
		{
			char character=s.charAt(i);

			if(character=='I')
			{
				if((i + 1) < n)
				{
					if(s.charAt(i + 1)=='V')
					{
						result+=getValue("IV");

						i+=2;
					}
					else if(s.charAt(i + 1)=='X')
					{
						result+=getValue("IX");

						i+=2;
					}
					else
					{
						result+=getValue(String.valueOf(character));

						i++;
					}
				}
				else
				{
					result+=getValue(String.valueOf(character));

					i++;
				}
			}
			else if(character=='X')
			{
				if((i + 1 < n))
				{
					if(s.charAt(i + 1)=='L')
					{
						result+=getValue("XL");

						i+=2;
					}
					else if(s.charAt(i + 1)=='C')
					{
						result+=getValue("XC");

						i+=2;
					}
					else
					{
						result+=getValue(String.valueOf(character));

						i++;
					}
				}
				else
				{
					result+=getValue(String.valueOf(character));

					i++;
				}
			}
			else if(character=='C')
			{
				if((i + 1 < n))
				{
					if(s.charAt(i + 1)=='D')
					{
						result+=getValue("CD");

						i+=2;
					}
					else if(s.charAt(i + 1)=='M')
					{
						result+=getValue("CM");

						i+=2;
					}
					else
					{
						result+=getValue(String.valueOf(character));

						i++;
					}
				}
				else
				{
					result+=getValue(String.valueOf(character));

					i++;
				}
			}
			else
			{
				result+=getValue(String.valueOf(character));

				i++;
			}
		}

		return result;
    }