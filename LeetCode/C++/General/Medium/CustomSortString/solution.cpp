#include <string>
#include <unordered_map>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n + m) [where n is the length of s and m is the length of order]
Space complexity: O(u) [where u is the number of unique letters in s]
*/

class Solution
{
    public:
        string customSortString(string order, string s)
        {
            string result{};
            
            //Map each letter in s to its frequency
            unordered_map<char, int> frequencies;
            
            //Create the frequency mappings
            for(auto & letter : s)
            {
                frequencies[letter]+=1;
            }
            
            //Iterate through each letter in order
            for(auto letter : order)
            {
                //If the letter appears in the string s
                if(frequencies.find(letter)!=end(frequencies))
                {
                    int times=frequencies[letter];
                    
                    //Add all occurrences of the letter to the result
                    for(int count=0;count<times;count++)
                    {
                        result.push_back(letter);
                    }
                    
                    //Erase the letter once we're finished with it
                    frequencies.erase(letter);
                }
            }
            
            //Add any remaining letters from s that weren't in the order string
            for(auto & [letter, frequency] : frequencies)
            {
                int times=frequency;
                
                for(int count=0;count<times;count++)
                {
                    result.push_back(letter);
                }
            }
            
            return result;
        }
};