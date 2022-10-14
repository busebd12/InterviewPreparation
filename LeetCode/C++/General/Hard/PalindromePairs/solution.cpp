#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/palindrome-pairs/discuss/2589144/Java-or-Hashing-or-Explained

Time complexity: O(n * w^2) [where n is the length of words and w is the length of the longest word]
Space complexity: O(n * w)
*/


class Solution
{
    public:
    vector<vector<int>> palindromePairs(vector<string> & words)
    {
        vector<vector<int>> result;
        
        int w=words.size();
        
        unordered_map<string, int> hashmap;
        
        for(int i=0;i<w;i++)
        {
            string reversed=words[i];
            
            reverse(begin(reversed), end(reversed));
            
            hashmap.emplace(reversed, i);
        }
        
        string emptyString="";
        
        if(hashmap.find(emptyString)!=end(hashmap))
        {
            for(int i=0;i<w;i++)
            {
                if(i!=hashmap[emptyString])
                {
                    if(isPalindrome(words[i])==true)
                    {
                        result.emplace_back(vector<int>{i, hashmap[emptyString]});
                    }
                }
            }
        }
        
        for(int i=0;i<w;i++)
        {
            string suffix=words[i];
            
            string prefix="";
            
            for(int j=0;j<words[i].size();j++)
            {
                prefix.push_back(words[i][j]);
                
                suffix.erase(begin(suffix));
                
                if(hashmap.find(prefix)!=end(hashmap) and isPalindrome(suffix)==true and hashmap[prefix]!=i)
                {
                    result.emplace_back(vector<int>{i, hashmap[prefix]});
                }
                
                if(hashmap.find(suffix)!=end(hashmap) and isPalindrome(prefix)==true and hashmap[suffix]!=i)
                {
                    result.emplace_back(vector<int>{hashmap[suffix], i});
                }
            }
        }
        
        return result;
    }
    
    bool isPalindrome(string & word)
    {
        int n=word.size();

        int left=0;

        int right=n - 1;

        while(left <= right)
        {
            if(word[left]!=word[right])
            {
                return false;
            }

            left+=1;

            right-=1;
        }

        return true;
    }
};