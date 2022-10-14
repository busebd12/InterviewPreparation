#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/split-array-into-consecutive-subsequences/discuss/2450588/C%2B%2BorDetailed-Explanation-w-Dry-Run-or-Each-Step-Explained-or-Commented-Code

Time complexity: O(n) [where n is the length of nums]
Space complexity: O(u) [where u is the number of unique numbers in nums]
*/

class Solution
{   
    public:
        bool isPossible(vector<int> & nums)
        {
            int n=nums.size();
            
            unordered_map<int, int> frequencies;
            
            for(int number : nums)
            {
                frequencies[number]+=1;
            }
            
            unordered_map<int, int> subsequencesEndingWith;
            
            for(int i=0;i<n;i++)
            {
                int number=nums[i];
                
                if(frequencies[number]==0)
                {
                    continue;
                }
                
                frequencies[number]-=1;
                
                int previousNumber=number - 1;
                
                int secondNumberInSubsequence=number + 1;
                
                int thirdNumberInSubsequence=number + 2;
                
                if(subsequencesEndingWith.find(previousNumber)!=end(subsequencesEndingWith) and subsequencesEndingWith[previousNumber] > 0)
                {
                    subsequencesEndingWith[previousNumber]-=1;
                    
                    if(subsequencesEndingWith.find(number)==end(subsequencesEndingWith))
                    {
                        subsequencesEndingWith.emplace(number, 0);
                    }
                    
                    subsequencesEndingWith[number]+=1;
                }
                else if(frequencies[secondNumberInSubsequence] > 0 and frequencies[thirdNumberInSubsequence] > 0)
                {
                    frequencies[secondNumberInSubsequence]-=1;
                    
                    frequencies[thirdNumberInSubsequence]-=1;
                    
                    if(subsequencesEndingWith.find(thirdNumberInSubsequence)==end(subsequencesEndingWith))
                    {
                        subsequencesEndingWith.emplace(thirdNumberInSubsequence, 0);
                    }
                    
                    subsequencesEndingWith[thirdNumberInSubsequence]+=1;
                }
                else
                {
                    return false;
                }
            }
            
            return true;
        }
};