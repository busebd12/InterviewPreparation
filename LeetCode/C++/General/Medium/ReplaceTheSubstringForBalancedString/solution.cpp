#include <string>
#include <unordered_map>
using namespace std;

/*
Time complexity: O(n)
Space complexity: O(u) [where u is the total number of unique letter frequencies in s]
*/

class Solution
{
    public:
        int balancedString(string s)
        {
            int result=0;

            int n=s.size();

            int k=n / 4;

            //Map each character in s to its frequency
            unordered_map<char, int> frequencies;

            //Create the frequency mappings
            for(char letter : s)
            {
                frequencies[letter]+=1;
            }

            //For each letter in s, subtract the maximum allowed amount from its frequency
            for(auto & [letter, frequency] : frequencies)
            {
                frequency-=k;
            }

            //String that will store any excess letters - i.e. amount Q's, W's, E's, and/or R's that make the frequency of that letter more than the allowed amount
            string targetLetters="";

            for(auto & [letter, frequency] : frequencies)
            {
                //There's an excess of this letter
                if(frequency > 0)
                {
                    //Add "excess" number of this letter to targetLetters
                    for(int count=0;count<frequency;count++)
                    {
                        targetLetters.push_back(letter);
                    }
                }
            }

            //If the string is empty, then the frequency of Q, W, E, and R is n / 4
            if(targetLetters.empty())
            {
                return result;
            }

            //Map each letter in targetLetters to its frequency
            unordered_map<char, int> targetLetterFrequencies;

            //Create the frequency mappings
            for(char letter : targetLetters)
            {
                targetLetterFrequencies[letter]+=1;
            }

            //The total number of letters that need to be replaced
            int lettersToRemove=targetLetterFrequencies.size();

            //Sliding window time
            int left=0;

            int right=0;

            while(right < n)
            {
                //If s[left] is a letter that we want to replace
                if(targetLetterFrequencies.find(s[right])!=targetLetterFrequencies.end())
                {
                    //Decrement the frequency
                    targetLetterFrequencies[s[right]]-=1;

                    //If we have removed all occurrances of this letter
                    if(targetLetterFrequencies[s[right]]==0)
                    {
                        lettersToRemove-=1;
                    }
                }

                //At this point, we have found a window that contains all the letters that need to be replaced
                //Now, we just keep shrinking the window until it doesn't contain all the letters that need to be replaced.
                while(left <= right and lettersToRemove==0)
                {
                    int length=(right - left) + 1;

                    if(result==0 or length < result)
                    {
                        result=length;
                    }

                    //Letter that needs to be replaced is taken out of the window
                    if(targetLetterFrequencies.find(s[left])!=targetLetterFrequencies.end())
                    {
                        //Increment the frequency
                        targetLetterFrequencies[s[left]]+=1;

                        //If we have removed all occurrances of the letter from the window
                        if(targetLetterFrequencies[s[left]]==1)
                        {
                            lettersToRemove+=1;
                        }
                    }

                    left+=1;
                }

                right+=1;
            }

            return result;
        }
};