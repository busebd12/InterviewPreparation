#include <string>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n + w * (l * log(indices)))
[where n is the length of s; w is the total number of words; l is the average length of a word; indices is the average number of indices per letter in s]

Space complexity: O(26) --> O(1)
*/

class Solution
{
    public:
        bool isSubsequence(vector<vector<int>> & hashtable, string & word)
        {
            //Keep track of the index we need to find the next letter at
            int j=-1;
            
            //For each letter in the word
            for(char & letter : word) //O(l)
            {
                //Correct index in the hashtable
                int index=letter - 'a';
                
                //Search for the index of the current letter that is greater (appears later in the string) than the index of the previous letter of word
                auto itr=upper_bound(begin(hashtable[index]), end(hashtable[index]), j); //O(log(indices))
                
                //If no such index exists, then the word can't be a subsequence
                if(itr==end(hashtable[index]))
                {
                    return false;
                }
                
                //Update j to be the index we just found
                j=*(itr);
            }
            
            return true;
        }
    
        int numMatchingSubseq(string s, vector<string> & words)
        {
            int result=0;
            
            int n=s.size();
            
            //Map each letter to all the indices of s at which this letter appears
            vector<vector<int>> hashtable(26);
            
            for(int i=0;i<n;i++) //O(n)
            {
                char letter=s[i];
                
                //Add the index of the letter to the vector for this particular letter
                hashtable[letter - 'a'].push_back(i);
            }
            
            //For each word
            for(string word : words) //O(w)
            {
                //Check if it is a subsequence
                if(isSubsequence(hashtable, word)==true)
                {
                    result+=1;
                }
            }
            
            return result;
        }
};