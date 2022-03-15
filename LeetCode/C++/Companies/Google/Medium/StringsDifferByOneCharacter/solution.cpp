#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*
Solution 1: brute force. See comments.

Time complexity: O(n * (n * w)) [where n is the number of words in the dictionary and w is average length of a word]
Space complexity: O(1)
*/

class Solution
{
    public:
        bool differByOne(vector<string> & dict)
        {
            if(dict.empty())
            {
                return false;
            }
            
            int n=dict.size();
            
            //Iterate through the dictionary
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    //Compare the words if they're not the same
                    if(i!=j)
                    {
                        int w=dict[i].size();
                        
                        //Keep track of the number of mismatching characters
                        int mismatches=0;
                        
                        for(int index=0;index<w;index++)
                        {
                            if(dict[i][index]!=dict[j][index])
                            {
                                mismatches+=1;
                            }
                        }
                        
                        //If there is exactly one mismatch
                        if(mismatches==1)
                        {
                            return true;
                        }
                    }
                }
            }
            
            return false;
        }
};

/*
Solution 2: see comments

Time complexity: O((n * w) + (n * w)) [where n is the number of words in the dictionary and w is the average length of a word]
Space compleity: O(n)
*/
class Solution
{
    public:
        bool differByOne(vector<string> & dict)
        {
            if(dict.empty())
            {
                return false;
            }
            
            int n=dict.size();
            
            //Hashtable to map a word from the dictionary to a vector of copies of the word
            //where each copy has the * character at different indices within the word
            //Example: word=abcd would map to {*bcd, a*cd, ab*d, abc*}
            unordered_map<string, vector<string>> hashtable;
            
            //For each word in the dictionary
            for(auto & word : dict)
            {
                int w=word.size();
                
                string copy=word;
                
                //Generate the vector of strings the word maps to
                //Example: for the word=abcd, generate the strings {*bcd, a*cd, ab*d, abc*}
                for(int i=0;i<w;i++)
                {
                    char letter=copy[i];
                    
                    copy[i]='*';
                    
                    hashtable[word].emplace_back(copy);
                    
                    copy[i]=letter;
                }
            }
            
            unordered_set<string> cache;
            
            //Iterate through the hashtable
            for(const auto & [word, copies] : hashtable)
            {
                //Iterate through the list of words associated with each word
                for(const auto & copy : copies)
                {
                    //If the cache doesn't have the copy, add it
                    if(!cache.count(copy))
                    {
                        cache.insert(copy);
                    }
                    //Else, the cache does have the copy and we know that two words in the dictionary fit the criteria
                    //Example:
                    //word=abcd maps to {*bcd, a*cd, ab*d, abc*}
                    //word=aacd maps to {*acd, a*cd, aa*d, aac*}
                    //For the two words, the common string with the * in it that they both share is a*cd
                    //If a*cd is already in the cache, and we see a*cd again, we know that both of these words meet the 
                    //criteria since the * character could be replaced with two different letters.
                    else
                    {
                        return true;
                    }
                }
            }
            
            return false;
        }
};