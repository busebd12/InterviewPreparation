#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/count-number-of-teams/discuss/554902/Greater-and-Smaller-Array-Explained-CPPPython-O(n2)-time

Time complexity: O(n^2) [where n is the length of rating]
Space complexity: O(n)
*/

class Solution
{
    public:
        int numTeams(vector<int> & rating)
        {
            int result=0;
            
            result+=helper(rating);
            
            reverse(begin(rating), end(rating));
            
            result+=helper(rating);
            
            return result;
        }
    
        int helper(vector<int> & rating)
        {
            int teams=0;
            
            int n=rating.size();
            
            vector<int> greaterThan(n, 0);
            
            for(int i=0;i<n;i++)
            {
                int currentRating=rating[i];
                
                int greaterThanCount=0;
                
                for(int j=i+1;j<n;j++)
                {
                    if(rating[j] > currentRating)
                    {
                        greaterThanCount+=1;
                    }
                }
                
                greaterThan[i]=greaterThanCount;
            }
            
            vector<int> lessThan(n, 0);
            
            for(int i=0;i<n;i++)
            {
                int currentRating=rating[i];
                
                int lessThanCount=0;
                
                for(int j=i-1;j>=0;j--)
                {
                    if(rating[j] < currentRating)
                    {
                        lessThanCount+=1;
                    }
                }
                
                lessThan[i]=lessThanCount;
            }
            
            for(int i=0;i<n;i++)
            {
                teams+=(greaterThan[i] * lessThan[i]);
            }
            
            return teams;
        }
};