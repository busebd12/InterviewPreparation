import java.lang.Character;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

/*
	Solution: we make use of two data structures, a PriorityQueue and an ArrayList.
	The PriorityQueue is used to store the ordered letter-logs and the ArrayList
	is used to store the digit-logs. We make use of a custom comparator for the
	PriorityQueue that says if the non-identifier parts of two letter-logs are
	equal, then those two letter-logs are ordered by the identifier (if the
	identifiers are not the same) or the non-identifier parts (if the identifiers
	are the same). We iterate through the log files and if a log is a letter log,
	we split the log into two parts, the identifier and the rest. We then add
	those parts (as a String array) to the PriorityQueue. If the log is a digit-log,
	then we add the log to the ArrayList. Then, while the PriorityQueue is not empty,
	we add each element to the result String array. Finally, we add all the digit logs
	to the result String array.

	Time complexity: O((n * (L * log(L))) + (L * log(L)) + (D))
	[where L is the total number of letter-logs, log(L) is the PriorityQueue insertion time && deletion cost, D is the total number of digit-logs, and n is the total number of log files in the input array]
	
	Space complexity: O(n) [where n is the total number of log files in the input logs array]
*/

class Solution
{
	public String[] reorderLogFiles(String[] logs)
	{
        String[] result=new String[logs.length];

        if(logs==null || logs.length==0)
        {
        	return result;
        }

        List<String> digitLogs=new ArrayList<>();

        Queue<String[]> pq=new PriorityQueue<>((a, b) -> a[1].compareTo(b[1])==0 ? a[0].compareTo(b[0]) : a[1].compareTo(b[1]));

        for(String log : logs)
        {
        	int firstSpaceIndex=log.indexOf(" ");

        	String identifier=log.substring(0, firstSpaceIndex);

        	String rest=log.substring(firstSpaceIndex + 1);

        	if(Character.isLetter(rest.charAt(0)))
        	{
        		pq.add(new String[] {identifier, rest});
        	}
        	else
        	{
        		digitLogs.add(log);
        	}	
        }

        int index=0;

        while(!pq.isEmpty())
        {
        	String[] current=pq.poll();

        	result[index]=current[0] + " " + current[1];

        	index++;
        }

        for(int i=0;i<digitLogs.size();i++)
        {
        	result[index]=digitLogs.get(i);

        	index++;
        }

        return result;
    }
}