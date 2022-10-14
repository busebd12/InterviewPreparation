#include <map>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/shopping-offers/discuss/1905796/100-space-efficient-70-time-efficient-algortithm
*/

class Solution
{
    public:
        int shoppingOffers(vector<int> & price, vector<vector<int>> & special, vector<int> & needs)
        {   
            int result=0;
            
            int p=price.size();
            
            int s=special.size();
            
            int n=needs.size();
            
            int cost=0;
            
            map<vector<int>, int> memo;
            
            result=helper(price, special, needs, memo, p, s, n);
            
            return result;
        }
    
        int helper(vector<int> & price, vector<vector<int>> & special, vector<int> & needs, map<vector<int>, int> & memo, int p, int s, int n)
        {
            if(memo.find(needs)!=end(memo))
            {
                return memo[needs];
            }
            
            int subproblemSolution=0;
            
            int needsCost=getRemainingCost(needs, price, n);
            
            subproblemSolution=needsCost;
            
            for(vector<int> & offer : special)
            {
                int costUsingOffer=0;
                
                if(canUseOffer(needs, offer, n)==true)
                {
                    updateNeeds(needs, offer, n, '-');
                    
                    costUsingOffer+=offer.back();
                    
                    costUsingOffer+=helper(price, special, needs, memo, p, s, n);
                    
                    updateNeeds(needs, offer, n, '+');
                    
                    subproblemSolution=min(subproblemSolution, costUsingOffer);
                }
            }
            
            memo.emplace(needs, subproblemSolution);
            
            return subproblemSolution;
        }
    
        bool canUseOffer(vector<int> & needs, vector<int> & offer, int n)
        {
            for(int i=0;i<n;i++)
            {
                if(offer[i] > needs[i])
                {
                    return false;
                }
            }
            
            return true;
        }
    
        void updateNeeds(vector<int> & needs, vector<int> & offer, int n, char op)
        {
            for(int i=0;i<n;i++)
            {
                if(op=='+')
                {
                    needs[i]+=offer[i];
                }
                else
                {
                    needs[i]-=offer[i];
                }
            }
        }
    
        int getRemainingCost(vector<int> & price, vector<int> & needs, int n)
        {
            int remainingCost=0;
            
            for(int i=0;i<n;i++)
            {
                if(needs[i] > 0)
                {
                    remainingCost+=(price[i] * needs[i]);
                }
            }
            
            return remainingCost;
        }
};