import java.lang.Math;
import java.lang.String;
import java.util.Collections;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

/*
	Solutions:

	1. This problem is similar to asking if a given list of words is ordered correctly based on the order of the English dictionary.
	How do we solve that problem? By going letter-by-letter through two given words and if we find two letters that are not the same,
	we compare the letters to see which one comes first in the alphabet. If the letter from the first word comes first, then the
	two words are in order. Else, the two words are not in order. We apply the same logic except that the given order is different
	than the normal order of letters in the English alphabet. We also use a hashtable (int[]) to map each letter to its index in the ordering
	so that, when we compare two letters, we can quicly see which one comes first. Then, we simply iterate over the words and compare
	them two at a time and if any two are not in the correct order, then we return false. After iterating through all the words, if
	we do not find any out-of-order, then all of them are in-order and we return true. A corner case that we have to account for
	is if one of the words is a prefix of another word. We handle this by making sure that when comparing two words, w1 and w2,
	the length of w1 is less than or equal to the length of w2.

	Time complexity: O(o + (w * min(w1, w2)) [where o is the length of the input order String, w is the length of the input words array, and min(w1, w2) is the minimum length between two words, w1 and w2]
	Space complexity: O(1)

	2. Exact same logic as the first solution except that we use an ArrayList<> for the hashtable instead of a integer array.

	Time complexity: O(o + (w * min(w1, w2))
	Space complexity: O(1)
*/

class Solution
{
	public boolean isOrdered(int[] hashtable, String word1, String word2)
	{
		int w1=word1.length();

		int w2=word2.length();

		for(int i=0;i<Math.min(w1, w2);i++)
		{
			char c1=word1.charAt(i);

			char c2=word2.charAt(i);

			if(c1!=c2)
			{
				return hashtable[c1 - 'a'] < hashtable[c2 - 'a'];
			}
		}

		return w1 <= w2;
	}

	public boolean isAlienSorted(String[] words, String order)
	{
		int w=words.length;

		int o=order.length();

		int[] hashtable=new int[26];

		for(int i=0;i<o;i++)
		{
			int index=order.charAt(i) - 'a';

			hashtable[index]=i;
		}

		for(int index=0;index<w-1;index++)
		{
			if(!isOrdered(hashtable, words[index], words[index + 1]))
			{
				return false;
			}
		}

		return true;
	}
}

class Solution
{
	public boolean isOrdered(List<Integer> hashtable, String word1, String word2)
	{
		int w1=word1.length();

		int w2=word2.length();

		for(int i=0;i<Math.min(w1, w2);i++)
		{
			char c1=word1.charAt(i);

			char c2=word2.charAt(i);

			if(c1!=c2)
			{
				return hashtable.get(c1 - 'a') < hashtable.get(c2 - 'a');
			}
		}

		return w1 <= w2;
	}

	public boolean isAlienSorted(String[] words, String order)
	{
		int w=words.length;

		int o=order.length();

		List<Integer> hashtable=new ArrayList<>(Collections.nCopies(26, 0));

		for(int i=0;i<o;i++)
		{
			int index=order.charAt(i) - 'a';

			hashtable.set(index, i);
		}

		for(int index=0;index<w-1;index++)
		{
			if(!isOrdered(hashtable, words[index], words[index + 1]))
			{
				return false;
			}
		}

		return true;
	}
}