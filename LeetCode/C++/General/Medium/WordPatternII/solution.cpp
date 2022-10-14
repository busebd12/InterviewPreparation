#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
    private:
        //Map a character from pattern to a substring from s
        unordered_map<char, string> patternMap;
    
        //Map a substring from s to a character from pattern
        unordered_map<string, char> sMap;
    
    public:
        bool dfs(string pattern, string s, int n, int m, int i, int j)
        {
            //If we've reached the end of pattern or s, in order for the mapping to be valid, we have to be at the end of both
            if(i==n or j==m)
            {
                return (i==n and j==m);
            }
            
            //Mark whether the character from pattern to substring from s mapping is made,
            //and whether the mapping from a substring of s to a character from pattern is made
            bool mapped=false;
            
            for(int substringEnd=i;substringEnd<n;substringEnd++)
            {
                //Generate a substring of s
                string substring=s.substr(i, substringEnd - i + 1);
                
                //If the current letter in pattern has a mapping
                if(patternMap.find(pattern[j])!=end(patternMap))
                {
                    //Check to see if the letter maps to the current substring
                    if(patternMap[pattern[j]]!=substring)
                    {
                        continue;
                    }
                }
                //If the substring has a mapping already
                else if(sMap.find(substring)!=end(sMap))
                {
                    //Check to see if it maps to the current character
                    if(sMap[substring]!=pattern[j])
                    {
                        continue;
                    }
                }
                //Neither the current character from pattern nor the current substring from s has a mapping
                else
                {
                    //Create the mappings
                    patternMap[pattern[j]]=substring;
                    
                    sMap[substring]=pattern[j];
                    
                    mapped=true;
                }
                
                //If the current recursive path we are on leads to a pattern match
                if(dfs(pattern, s, n, m, substringEnd + 1, j + 1)==true)
                {
                    return true;
                }
                
                //If a mapping between the current substring of s and the current letter in pattern was created
                if(mapped==true)
                {
                    //Erase the mapping so we can backtrack when returning from the recursive call
                    patternMap.erase(pattern[j]);
                    
                    sMap.erase(substring);
                }
            }
            
            return false;
        }
    
        bool wordPatternMatch(string pattern, string s)
        {
            int n=s.size();
            
            int m=pattern.size();
            
            int i=0;
            
            int j=0;
            
            return dfs(pattern, s, n, m, i, j);
        }
};