#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

/*
Time complexity: O((r log r) + (r log r)) [where r is the number of rides]
Space complexity: O(r)
*/

typedef long long ll;

class Solution
{
    public:
        long long maxTaxiEarnings(int n, vector<vector<int>> & rides)
        {
            long long result=0;
            
            for(auto & ride : rides)
            {
                int start=ride[0];
                
                int end=ride[1];
                
                int tip=ride[2];
                
                ride[2]=(end - start) + tip;
            }
            
            auto sortLikeThis=[] (vector<int> & lhs, vector<int> & rhs)
            {
                if(lhs[0]==rhs[0])
                {
                    return lhs[1] < rhs[1];
                }
                else
                {
                    return lhs[0] < rhs[0];
                }
            };
            
            sort(begin(rides), end(rides), sortLikeThis); //O(r log r)
            
            priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> minHeap;
            
            ll maxEarningsFromPreviousRides=0;
            
            for(auto & ride : rides) //O(r log r)
            {
                int start=ride[0];
                
                int end=ride[1];
                
                int earningsFromCurrentRide=ride[2];
                
                while(!minHeap.empty() && minHeap.top().first <= start)
                {
                    ll earningsFromPreviousRide=minHeap.top().second;
                    
                    maxEarningsFromPreviousRides=max(maxEarningsFromPreviousRides, earningsFromPreviousRide);

                    minHeap.pop();
                }
                
                result=max(result, maxEarningsFromPreviousRides + earningsFromCurrentRide);
                
                minHeap.emplace(end, maxEarningsFromPreviousRides + earningsFromCurrentRide);
            }
            
            return result;
            
        }
};