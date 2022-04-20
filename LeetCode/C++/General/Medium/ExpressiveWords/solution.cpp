#include <string>
#include <utility>
#include <vector>

/*
Solution: see comments.

Also, see this post for futher clarification of the problem statement: https://leetcode.com/problems/expressive-words/discuss/122069/Problem-setter-should-work-harder-on-his-English.

Time complexity: O(m + w(l + (um + ul)))
[where m is the length of s; w is the length of words; l is the average length of a word; ul is the number of unique letters in a word; um is the unique number of letters in s]

Space complexity: O(um + w(ul))
*/

class Solution
{
    public:
        vector<pair<char, int>> getPairs(string & word)
        {
            //Vector of pairs where each pair is composed of a character and how many times it is repeated it in the string starting at a particular index
            vector<pair<char, int>> pairs;
            
            int w=word.size();
            
            int count=0;
            
            int i=0;
            
            while(i < w)
            {
                char letter=word[i];
                
                int j=i;
                
                while(j < w && letter==word[j])
                {
                    count+=1;
                    
                    j+=1;
                }
                
                pairs.emplace_back(letter, count);
                
                i=j;
                
                count=0;
            }
            
            return pairs;
        }
    
        bool isStretchy(vector<pair<char, int>> & sPairs, vector<pair<char, int>> & wordPairs)
        {
            int n=wordPairs.size();
            
            //If the vector of pairs aren't the same length, then the two words don't have the same characters
            if(sPairs.size()!=wordPairs.size())
            {
                return false;
            }
            
            for(int index=0;index<n;index++)
            {
                auto sPair=sPairs[index];
                
                auto wordPair=wordPairs[index];
                
                //If the two letters at the index aren't the same
                if(sPair.first!=wordPair.first)
                {
                    return false;
                }
                //Else, letters are the same
                else
                {
                    //If the letter at this index only has a frequency of one
                    if(wordPair.second==1)
                    {
                        //The group of the same letter starting at the same position in s must be of length one or three or more
                        if(sPair.second==2)
                        {
                            return false;
                        }
                    }
                    //If the grouping of same letters at this index has size two, then the corresponding group of letters in s must be of size two or more
                    else if(wordPair.second==2)
                    {
                        if(sPair.second < 2)
                        {
                            return false;
                        }
                    }
                    //If the group of the same letters at this index in the word is already greater than the corresponding grouping of letters in s, then no stretching is possible
                    else if(wordPair.second > sPair.second)
                    {
                        return false;
                    }
                }
            }
            
            return true;
        }
    
        int expressiveWords(string s, vector<string> & words)
        {
            int result=0;
            
            vector<pair<char, int>> sPairs=getPairs(s); //O(m) [where m is the length of s]
            
            for(string & word : words) // O(w) [where w is the length of words]
            {
                vector<pair<char, int>> wordPairs=getPairs(word); //O(l) [where l is the average length of a word]
                
                if(isStretchy(sPairs, wordPairs)) //O(m + l)
                {
                    result+=1;
                }
            }
            
            return result;
        }
};