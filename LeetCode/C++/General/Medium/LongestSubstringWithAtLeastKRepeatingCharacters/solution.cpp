#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/*
Solution 1: brute force; generate all possible substrings and check for the longest one that meets the condition.

Time complexity: O(n^2) [where n is the length of s]
Space complexity: O(26) --> O(1)
*/

class Solution
{
    public:
        int longestSubstring(string s, int k)
        {
            int result=0;
            
            int n=s.size();
            
            for(int substringStart=0;substringStart<n;substringStart++)
            {
                vector<int> hashtable(26, 0);
                
                for(int substringEnd=substringStart;substringEnd<n;substringEnd++)
                {
                    int index=s[substringEnd] - 'a';
                    
                    hashtable[index]+=1;
                    
                    if(hashtable[index] < k)
                    {
                        continue;
                    }
                    
                    if(isValidSubstring(hashtable, k)==true)
                    {
                        int length=(substringEnd - substringStart) + 1;
                        
                        result=max(result, length);
                    }
                }
            }
            
            return result;
        }
    
        bool isValidSubstring(vector<int> & hashtable, int k)
        {
            for(int index=0;index<26;index++)
            {
                if(hashtable[index] > 0 and hashtable[index] < k)
                {
                    return false;
                }
            }
            
            return true;
        }
};

/*
Solution 2: inspired by this post --> https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/discuss/170010/Java-O(n)-Solution-with-Detailed-Explanation-Sliding-Window

Time complexity: O(n)
Space complexity: O(26) --> O(1)
*/

class Solution
{
    public:
        int longestSubstring(string s, int k)
        {
            int result=0;
            
            int n=s.size();
            
            for(int uniqueCharacters=1;uniqueCharacters<=26;uniqueCharacters++)
            {
                vector<int> hashtable(26, 0);
                
                int back=0;
                
                int front=0;
                
                int unique=0;
                
                int kOrMore=0;
                
                while(front < n)
                {
                    if(unique <= uniqueCharacters)
                    {
                        char c=s[front];
                        
                        int index=c - 'a';
                        
                        hashtable[index]+=1;
                        
                        if(hashtable[index]==1)
                        {
                            unique+=1;
                        }
                        
                        if(hashtable[index]==k)
                        {
                            kOrMore+=1;
                        }
                        
                        front+=1;
                    }
                    else
                    {
                        char c=s[back];
                        
                        int index=c - 'a';
                        
                        hashtable[index]-=1;
                        
                        if(hashtable[index]==0)
                        {
                            unique-=1;
                        }
                        
                        if(hashtable[index]==k-1)
                        {
                            kOrMore-=1;
                        }
                        
                        back+=1;
                    }
                    
                    if(kOrMore==unique)
                    {
                        int length=front - back;
                        
                        result=max(result, length);
                    }
                }
            }
            
            return result;
        }
};