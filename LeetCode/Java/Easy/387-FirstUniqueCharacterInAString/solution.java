import java.lang.Math;
import java.lang.String;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/*
	Solutions:

	1.
*/

class Solution
{
    public int firstUniqChar(String s)
    {
        int result=-1;

		if(s==null || s.isEmpty())
		{
			return result;
		}

		int n=s.length();

		Map<Character, Integer> hashtable=new HashMap<>();
        
        boolean[] seen=new boolean[26];

		for(int i=0;i<n;i++)
		{
		    char letter=s.charAt(i);
            
            if(seen[letter - 'a'])
            {
                if(hashtable.containsKey(letter))
                {
                    hashtable.remove(letter);
                }
            }
			else
			{
				seen[letter - 'a']=true;
                
                hashtable.put(letter, i);
			}
		}

		for(Integer element : hashtable.values())
		{
			if(result==-1)
			{
				result=element;
			}
			else
			{
				result=Math.min(result, element);
			}
		}

		return result;
    }
}

class Solution
{
	public int firstUniqChar(String s)
	{
		int result=-1;

		if(s==null || s.isEmpty())
		{
			return result;
		}

		int n=s.length();

		int[] hashtable=new int[26];
        
        Arrays.fill(hashtable, -1);
        
        boolean[] seen=new boolean[26];

		for(int i=0;i<n;i++)
		{
			char letter=s.charAt(i);

			if(seen[letter - 'a'])
			{
				if(hashtable[letter - 'a'] >= 0)
				{
					hashtable[letter - 'a']=-1;
				}
			}
			else
			{
				seen[letter - 'a']=true;

				hashtable[letter - 'a']=i;
			}
		}

		for(int index=0;index<hashtable.length;index++)
		{
			if(hashtable[index] > -1)
            {
                if(result==-1)
                {
                    result=hashtable[index];
                }
                else
                {
                    result=Math.min(result, hashtable[index]);
                }
            }
		}

		return result;
	}
}