#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of security]
Space complexity: O(n)
*/

class Solution
{
    public:
        vector<int> goodDaysToRobBank(vector<int> & security, int time)
        {
            vector<int> result;
            
            int n=security.size();
            
            //nonIncreasingMemo[i] = number of guards for the bank before day i that are non-increasing
            vector<int> nonIncreasingMemo(n, 0);
            
            //Pre-calculate the number of non-increasing guards before each day i
            for(int i=1;i<n;i++)
            {
                if(security[i] <= security[i - 1])
                {
                    nonIncreasingMemo[i]=nonIncreasingMemo[i - 1] + 1;
                }
            }
            
            //nonDecreasingMemo[i] = number of guards for the bank after day i that are non-decreasing
            vector<int> nonDecreasingMemo(n, 0);
            
            //Pre-calculate the number of non-decreasing guards for the bank after i that are non-decreasing
            for(int i=n-2;i>=0;i--)
            {
                if(security[i] <= security[i + 1])
                {
                    nonDecreasingMemo[i]=nonDecreasingMemo[i + 1] + 1;
                }
            }
            
            //For each day
            for(int i=0;i<n;i++)
            {
                //If there are at least time days before and after the current day
                if(i - time >= 0 and i + time <= n-1)
                {
                    //If there are the correct number of non-increasing guards before this day, and the correct number of non-decreasing guards after this day,
                    //then this is a valid day to rob the bank
                    if(nonIncreasingMemo[i] >= time and nonDecreasingMemo[i] >= time)
                    {
                        result.push_back(i);
                    }
                }
            }
            
            return result;
        }
};