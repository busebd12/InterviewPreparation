import java.lang.Integer;
import java.lang.String;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
	Solutions:

	1. The algorithm works as follows

		a. Some corner case checking --> null or empty input array

		b. Initialize necessary data structures and store the length of the input array. We use the HashMap to create
		a mapping between the domains/subdomains and the respective counts.

		c. As we iterate through the input array, we do the following
			i. Split the count-pair domain around the space, resulting in two parts: the count and the domain.
			We store these two parts in a String array

			ii. Now, there are two cases to handle: either, the domain will have one or two '.' characters.
			Since a domain will always have at least one subdomain in either case (for example, the 'com' in google.mail.com or yahoo.com),
			we just extract that last domain from the string and either add or update its count in the HashMap.

			iii. If the domain contains two '.', then we need to account for the correct subdomain (for example, mail.com in google.mail.com)
			so we parse it out and either add or update its count in the HashMap.

			iv. Finally, we need to account for the entire domain, i.e. google.mail.com and either add or update its count in the HashMap.

		d. We iterate through the HashMap and build each result string and add it our result ArrayList.

		e. Return the ArrayList

	Time complexity: O(n * L) [where n is the length of the input array and L is the average length of a count-domain pair string]
	Space complexity: O(u) [where u is the number of unique domains/subdomains]


	2. Almost exactly the same logic except that we can avoid using the String.split() function and just use String.indexOf()
	to find the index of the space in the count-domain pair since we know there will only be one space in the string. Everything
	else remains the same in the algorithm.

	Time complexity: O(n * L) [where n is the length of the input array and L is the average length of a count-domain pair string]
	Space complexity: O(u) [where u is the number of unique domains/subdomains]
*/

class Solution
{
	int countPeriods(String domain)
	{
		char needle='.';

		int count=0;

		int d=domain.length();

		for(int index=0;index<d;index++)
		{
			if(domain.charAt(index)==needle)
			{
				count++;
			}
		}

		return count;
	}

	public List<String> subdomainVisits(String[] cpdomains)
    {
        if(cpdomains==null || cpdomains.length==0)
        {
        	return new ArrayList<String>();
        }

        int n=cpdomains.length;

        List<String> result=new ArrayList<>();

        Map<String, Integer> hashtable=new HashMap<>();

        for(String domain : cpdomains)
        {
        	String[] tokens=domain.split(" ");

        	int periods=countPeriods(domain);

        	int lastPeriodIndex=tokens[1].lastIndexOf('.');

        	String lastDomain=tokens[1].substring(lastPeriodIndex + 1);

        	if(hashtable.containsKey(lastDomain))
        	{
        		hashtable.put(lastDomain, hashtable.get(lastDomain) + Integer.parseInt(tokens[0]));
        	}
        	else
        	{
        		hashtable.put(lastDomain, Integer.parseInt(tokens[0]));
        	}

        	if(periods==2)
        	{
        		int firstPeriodIndex=tokens[1].indexOf('.');

        		String secondHalf=tokens[1].substring(firstPeriodIndex + 1);

        		if(hashtable.containsKey(secondHalf))
	        	{
	        		hashtable.put(secondHalf, hashtable.get(secondHalf) + Integer.parseInt(tokens[0]));
	        	}
	        	else
	        	{
	        		hashtable.put(secondHalf, Integer.parseInt(tokens[0]));
	        	}
        	}

        	if(hashtable.containsKey(tokens[1]))
        	{
        		hashtable.put(tokens[1], hashtable.get(tokens[1]) + Integer.parseInt(tokens[0]));
        	}
        	else
        	{
        		hashtable.put(tokens[1], Integer.parseInt(tokens[0]));
        	}
        }

        for(Map.Entry<String, Integer> element : hashtable.entrySet())
        {
        	String string=String.valueOf(element.getValue()) + " " + element.getKey();

        	result.add(string);
        }

        return result;
    }
}

class Solution
{
    int countPeriods(String domain)
	{
		char needle='.';

		int count=0;

		int d=domain.length();

		for(int index=0;index<d;index++)
		{
			if(domain.charAt(index)==needle)
			{
				count++;
			}
		}

		return count;
	}

	public List<String> subdomainVisits(String[] cpdomains)
    {
        if(cpdomains==null || cpdomains.length==0)
        {
        	return new ArrayList<String>();
        }

        int n=cpdomains.length;

        List<String> result=new ArrayList<>();

        Map<String, Integer> hashtable=new HashMap<>();

        for(String domain : cpdomains)
        {
        	int spaceIndex=domain.indexOf(' ');
            
            int count=Integer.parseInt(domain.substring(0, spaceIndex));
            
            String address=domain.substring(spaceIndex + 1);

        	int periods=countPeriods(address);

        	int lastPeriodIndex=address.lastIndexOf('.');

        	String lastDomain=address.substring(lastPeriodIndex + 1);

        	if(hashtable.containsKey(lastDomain))
        	{
        		hashtable.put(lastDomain, hashtable.get(lastDomain) + count);
        	}
        	else
        	{
        		hashtable.put(lastDomain, count);
        	}

        	if(periods==2)
        	{
        		int firstPeriodIndex=address.indexOf('.');

        		String secondHalf=address.substring(firstPeriodIndex + 1);

        		if(hashtable.containsKey(secondHalf))
	        	{
	        		hashtable.put(secondHalf, hashtable.get(secondHalf) + count);
	        	}
	        	else
	        	{
	        		hashtable.put(secondHalf, count);
	        	}
        	}

        	if(hashtable.containsKey(address))
        	{
        		hashtable.put(address, hashtable.get(address) + count);
        	}
        	else
        	{
        		hashtable.put(address, count);
        	}
        }

        for(Map.Entry<String, Integer> element : hashtable.entrySet())
        {
        	String string=String.valueOf(element.getValue()) + " " + element.getKey();

        	result.add(string);
        }

        return result;
    }
}