#include <algorithm>
#include <deque>
#include <string>
#include <unordered_map>
#include <vector>

/*
Solution 1: breadth-first search + building each vowel string as we go. This solution receives Time Limit Exceeded when run.
*/

class Solution
{
    public:
        int countVowelStrings(int n)
        {
            int result=0;
            
            unordered_map<char, vector<char>> hashtable;
            
            hashtable['a']=vector<char>{'a', 'e', 'i', 'o', 'u'};
            
            hashtable['e']=vector<char>{'e', 'i', 'o', 'u'};
            
            hashtable['i']=vector<char>{'i', 'o', 'u'};
            
            hashtable['o']=vector<char>{'o', 'u'};
            
            hashtable['u']=vector<char>{'u'};
            
            deque<string> queue;
            
            queue.emplace_back("");
            
            for(int count=0;count<n;count++)
            {
                auto qSize=queue.size();
                
                for(int i=0;i<qSize;i++)
                {
                    string current=queue.front();
                    
                    queue.pop_front();
                    
                    if(current.empty())
                    {
                        for(auto & [letter, letters] : hashtable)
                        {
                            queue.emplace_back(current + letter);
                        }
                    }
                    else
                    {
                        for(char letter : hashtable[current.back()])
                        {
                            queue.emplace_back(current + letter);
                        }
                    }
                }
            }
            
            result=queue.size();
            
            return result;
        }
};


/*
Solution 2: inspired by this post --> //https://leetcode.com/problems/count-sorted-vowel-strings/discuss/2029765/Stupid-count-mechanism

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution
{
    public:
        int countVowelStrings(int n)
        {
            int result=0;
            
            vector<int> counts(5, 1);
            
            for(int count=1;count<n;count++)
            {
                for(int i=0;i<5;i++)
                {
                    counts[i]+=accumulate(begin(counts) + (i + 1), end(counts), 0);
                }
            }
            
            result=accumulate(begin(counts), end(counts), 0);
            
            return result;
        }
};