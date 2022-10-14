#include <queue>
#include <vector>
using namespace std;

/*
Time complexity: O(n log n) [where n is the length of restaurants]
Space complexity: O(n)
*/

class Solution
{
    public:
        vector<int> filterRestaurants(vector<vector<int>> & restaurants, int veganFriendly, int maxPrice, int maxDistance)
        {
            vector<int> result;
            
            int n=restaurants.size();
            
            auto compareLikeThis=[] (vector<int> & lhs, vector<int> & rhs)
            {
                if(lhs[1]==rhs[1])
                {
                    return lhs[0] < rhs[0];
                }
                else
                {
                    return lhs[1] < rhs[1];
                }
            };
            
            priority_queue<vector<int>, vector<vector<int>>, decltype(compareLikeThis)> maxHeap(compareLikeThis);
            
            for(vector<int> & restaurant : restaurants)
            {
                int price=restaurant[3];
                
                int dist=restaurant[4];
                
                if(price <= maxPrice and dist <= maxDistance)
                {
                    if(veganFriendly==1)
                    {
                        int isVeganFriendly=restaurant[2];
                        
                        if(isVeganFriendly==1)
                        {
                            maxHeap.push(restaurant);
                        }
                    }
                    else
                    {
                        maxHeap.push(restaurant);
                    }
                }
            }
            
            while(!maxHeap.empty())
            {
                auto restaurant=maxHeap.top();
                
                maxHeap.pop();
                
                result.emplace_back(restaurant[0]);
            }
            
            return result;
        }
};