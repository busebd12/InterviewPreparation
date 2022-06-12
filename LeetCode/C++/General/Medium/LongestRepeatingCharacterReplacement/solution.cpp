#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n * u) [where n is the length of the string and u is the total number of unique characters in the string]
Space complexity: O(u)
*/

class Solution
{
    public:
        int getHighestCharacterFrequency(unordered_map<char, int> & frequencies)
        {
            int highest=0;
            
            for(auto & [character, frequency] : frequencies)
            {
                highest=max(highest, frequency);
            }
            
            return highest;
        }
    
        int characterReplacement(string s, int k)
        {
            int result=0;
            
            int n=s.size();
            
            unordered_map<char, int> frequencies;
            
            int left=0;
            
            int right=0;
            
            while(right < n)
            {
                frequencies[s[right]]+=1;
                
                //Get the frequency of the most occuring character in the current window
                int highestCharacterFrequency=getHighestCharacterFrequency(frequencies);
                
                //Size of the current window
                int windowSize=(right - left) + 1;
                
                //If there are at most k characters that are not the most occuring character, then we can perform the k replacements
                if(windowSize - highestCharacterFrequency <= k)
                {
                    result=max(result, windowSize);
                }
                else
                {
                    frequencies[s[left]]-=1;
                    
                    if(frequencies[s[left]]==0)
                    {
                        frequencies.erase(s[left]);
                    }
                    
                    left+=1;
                }
                
                right+=1;
            }
            
            return result;
        }
};