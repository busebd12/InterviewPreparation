#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution 1: sliding window + unordered_map to keep track of character frequencies.

Time complexity: O(n) [where n is the length of s]
Space complexity: O(u) [where u is the total number of unique chraracters in s]
*/

class Solution
{
    public:
        int lengthOfLongestSubstringKDistinct(string s, int k)
        {
            int result=0;
            
            int n=s.size();
            
            unordered_map<char, int> hashtable;
            
            int distinct=0;
            
            int back=0;
            
            int front=0;
            
            while(k > 0 and front < n)
            {   
                if(hashtable.find(s[front])==end(hashtable))
                {
                    hashtable.emplace(s[front], 1);
                    
                    distinct+=1;
                    
                    if(distinct > k)
                    {
                        while(back < front and distinct > k)
                        {
                            hashtable[s[back]]-=1;
                            
                            if(hashtable[s[back]]==0)
                            {
                                hashtable.erase(s[back]);
                                
                                distinct-=1;
                            }
                            
                            back+=1;
                        }
                    }
                    
                    int length=(front - back) + 1;
                    
                    result=max(result, length);
                }
                else
                {
                    hashtable[s[front]]+=1;
                    
                    int length=(front - back) + 1;
                    
                    result=max(result, length);
                }
                
                front+=1;
            }
            
            return result;
        }
};

/*
Solution 1: sliding window + vector<int> to keep track of character frequencies.

Time complexity: O(n) [where n is the length of s]
Space complexity: O(128) --> O(1)
*/

class Solution
{
    public:
        int lengthOfLongestSubstringKDistinct(string s, int k)
        {
            int result=0;
            
            int n=s.size();
            
            vector<int> hashtable(128, 0);
            
            int distinct=0;
            
            int back=0;
            
            int front=0;
            
            while(k > 0 and front < n)
            {   
                if(hashtable[int(s[front])]==0)
                {
                    hashtable[int(s[front])]+=1;
                    
                    distinct+=1;
                    
                    if(distinct > k)
                    {
                        while(back < front and distinct > k)
                        {
                            hashtable[int(s[back])]-=1;
                            
                            if(hashtable[int(s[back])]==0)
                            {   
                                distinct-=1;
                            }
                            
                            back+=1;
                        }
                    }
                    
                    int length=(front - back) + 1;
                    
                    result=max(result, length);
                }
                else
                {
                    hashtable[int(s[front])]+=1;
                    
                    int length=(front - back) + 1;
                    
                    result=max(result, length);
                }
                
                front+=1;
            }
            
            return result;
        }
};