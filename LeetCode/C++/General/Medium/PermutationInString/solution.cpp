#include <algorithm>
#include <string>
#include <vector>

/*
Solution 1: Brute force.

Time complexity: O((n log n) + (n * m) + m) [where n is the length of s1 and m is the length of s2]
Space complexity: O(1)
*/

class Solution
{
    public:
        bool checkInclusion(string s1, string s2)
        {
            sort(begin(s1), end(s1)); //O(n log n)
            
            while(next_permutation(begin(s1), end(s1))) //O(n)
            {
                if(s2.find(s1)!=string::npos) //O(m)
                {
                    return true;
                }
            }
            
            if(s2.find(s1)!=string::npos) //O(m)
            {
                return true;
            }
            
            return false;
        }
};

/*
Solution 2: inspired by this post --> https://leetcode.com/problems/permutation-in-string/discuss/1762469/C%2B%2B-oror-SLIDING-WINDOW-OPTIMIZED-oror-Well-Explained

Time complexity: O(m * n)
Space complexity: O(1)
*/

class Solution
{
    public:
        bool checkInclusion(string s1, string s2)
        {   
            int n=s1.size();
            
            int m=s2.size();
            
            vector<int> s1Frequencies(26, 0);
            
            for(char & letter : s1)
            {
                s1Frequencies[letter - 'a']+=1;
            }
            
            vector<int> s2Frequencies(26, 0);
            
            int back=0;
            
            int front=0;
            
            while(front < m)
            {
                s2Frequencies[s2[front] - 'a']+=1;
                
                int length=(front - back) + 1;
                
                if(length==n)
                {
                    if(equal(begin(s1Frequencies), end(s1Frequencies), begin(s2Frequencies)))
                    {
                        return true;
                    }
                }
                
                if(length < n)
                {
                    front+=1;
                }
                else
                {
                    s2Frequencies[s2[back] - 'a']-=1;
                    
                    back+=1;
                    
                    front+=1;
                }
            }
            
            return false;
        }
};