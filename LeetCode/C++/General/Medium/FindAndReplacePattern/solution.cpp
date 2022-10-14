#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Time complexity: O(w * L) [where w is the length of words and L is average length of a word]
Space complexity: O(w * L)
*/

class Solution
{
    public:
        vector<string> findAndReplacePattern(vector<string> & words, string pattern)
        {
            vector<string> result;
            
            for(string & word : words)
            {
                if(matches(word, pattern)==true)
                {
                    result.push_back(word);
                }
            }
            
            return result;
        }
    
        bool matches(string & word, string & pattern)
        {
            unordered_map<char, char> wordLetterToPatternLetter;
            
            unordered_map<char, char> patternLetterToWordLetter;
            
            int n=word.size();
            
            for(int i=0;i<n;i++)
            {
                char wordLetter=word[i];

                char patternLetter=pattern[i];
                
                if(wordLetterToPatternLetter.find(wordLetter)==end(wordLetterToPatternLetter) and patternLetterToWordLetter.find(patternLetter)==end(patternLetterToWordLetter))
                {   
                    wordLetterToPatternLetter[wordLetter]=patternLetter;
                    
                    patternLetterToWordLetter[patternLetter]=wordLetter;
                }
                else
                {
                    if(wordLetterToPatternLetter.find(wordLetter)!=end(wordLetterToPatternLetter))
                    {
                        if(patternLetter!=wordLetterToPatternLetter[wordLetter])
                        {
                            return false;
                        }
                    }
                    
                    if(patternLetterToWordLetter.find(patternLetter)!=end(patternLetterToWordLetter))
                    {
                        if(wordLetter!=patternLetterToWordLetter[patternLetter])
                        {
                            return false;
                        }
                    }
                }
            }
            
            return true;
        }
};