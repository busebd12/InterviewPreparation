#include <unordered_set>
#include <vector>
using namespace std;

/*
Solution: see this alternate explanation: https://leetcode.com/problems/card-flipping-game/discuss/162216/For-God's-Sake-let-me-try-to-rephrase-the-problem.

Time complexity: O(n) [where n is the length of fronts and backs]
Space complexity: O(u) [where u is the number of unique numbers from pairs of duplicates values in fronts and backs]
*/

class Solution
{
    public:
        int flipgame(vector<int> & fronts, vector<int> & backs)
        {
            int result=0;
            
            int n=fronts.size();
            
            unordered_set<int> duplicates;
            
            for(int i=0;i<n;i++)
            {
                int front=fronts[i];
                
                int back=backs[i];
                
                if(front==back)
                {
                    duplicates.insert(front);
                }
            }
            
            for(int i=0;i<n;i++)
            {
                int front=fronts[i];
                
                int back=backs[i];
                
                if(duplicates.find(front)==end(duplicates))
                {
                    if(result==0)
                    {
                        result=front;
                    }
                    else
                    {
                        result=min(result, front);
                    }
                }
                
                if(duplicates.find(back)==end(duplicates))
                {
                    if(result==0)
                    {
                        result=back;
                    }
                    else
                    {
                        result=min(result, back);
                    }
                }
            }
            
            return result;
        }
};