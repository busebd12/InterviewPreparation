#include <algorithm>
#include <string>
#include <string_view>
#include <vector>
using namespace std;

/*
Solution 1: brute-force which gets Time Limit Exceed when executed.

Time complexity: O(n^2) [where n is the length of s]
Space complexity: O(26) --> O(1)
*/

class Solution
{
    public:
        int numSplits(string s)
        {
            int result=0;
            
            int n=s.size();
            
            string_view sView=s;
            
            for(int i=0;i<n-1;i++)
            {
                string_view left=sView.substr(0, i + 1);
                
                string_view right=sView.substr(i + 1, string::npos);
                
                vector<int> leftFrequencies=getFrequencies(left);
                
                vector<int> rightFrequencies=getFrequencies(right);
                
                int leftUniqueLetters=count_if(begin(leftFrequencies), end(leftFrequencies), [] (int & frequency) {return frequency > 0;});
                
                int rightUniqueLetters=count_if(begin(rightFrequencies), end(rightFrequencies), [] (int & frequency) {return frequency > 0;});
                
                if(leftUniqueLetters==rightUniqueLetters)
                {
                    result+=1;
                }
            }
            
            return result;
        }
    
        vector<int> getFrequencies(string_view & substring)
        {
            vector<int> frequencies(26, 0);
            
            for(char letter : substring)
            {
                int index=letter - 'a';
                
                frequencies[index]+=1;
            }
            
            return frequencies;
        }
};

/*
Solution 2: inspired by this post --> https://leetcode.com/problems/number-of-good-ways-to-split-a-string/discuss/754719/Some-hints-to-help-you-solve-this-problem-on-your-own

Time complexity: O(n) [where n is the length of s]
Space complexity: O(n)
*/

class Solution
{
    public:
        int numSplits(string s)
        {
            int result=0;
            
            int n=s.size();
            
            unordered_set<char> unique;
            
            vector<int> prefix(n, 0);
            
            for(int i=0;i<n;i++)
            {
                char letter=s[i];
                
                if(unique.find(letter)==end(unique))
                {
                    unique.insert(letter);
                }
                
                prefix[i]=unique.size();
            }
            
            unique.clear();
            
            vector<int> suffix(n, 0);
            
            for(int i=n-1;i>=0;i--)
            {
                char letter=s[i];
                
                if(unique.find(letter)==end(unique))
                {
                    unique.insert(letter);
                }
                
                suffix[i]=unique.size();
            }
            
            for(int i=1;i<n;i++)
            {
                if(prefix[i - 1]==suffix[i])
                {
                    result+=1;
                }
            }
            
            return result;
        }
};