#include <deque>
#include <string>
#include <unordered_map>
#include <vector>

/*
Solution: based on this post --> https://leetcode.com/problems/number-of-matching-subsequences/discuss/117598/Java-solution-using-HashMap-and-Queue

Time complexity: O(n + (w * l)) [where n is the length of s, w is the number of words, and l is length of every word]
Space complexity: O(w)
*/

class Solution
{
    public:
        int numMatchingSubseq(string s, vector<string> & words)
        {
            int result=0;
            
            //Hashtable that maps a character to a deque of strings
            unordered_map<char, deque<string>> hashtable;
            
            //For each word in words, group each word in the hashtable based on the first letter
            for(auto & word : words)
            {   
                hashtable[word[0]].emplace_back(word);
            }
            
            //Iterate through the s string
            for(char letter : s)
            {
                //If the letter is in the hashtable, then there are words that being with that letter
                if(hashtable.count(letter))
                {
                    int size=hashtable[letter].size();

                    //Iterate through the list of words beginning with the current letter
                    for(int i=0;i<size;i++)
                    {
                        //Remove the first word
                        string word=hashtable[letter].front();

                        hashtable[letter].pop_front();

                        //If the word size is one, then this subsequence is found within s, so increment result
                        if(word.size()==1)
                        {
                            result++;
                        }
                        //Else, the word size is greater than one, so remove the first letter and add the remaining string to its bucket
                        else
                        {
                            string rest=word.substr(1, string::npos);

                            hashtable[rest[0]].emplace_back(rest);
                        }
                    }
                }
            }
            
            return result;
        }
};