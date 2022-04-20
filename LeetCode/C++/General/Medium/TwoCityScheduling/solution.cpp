#include <queue>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: see comments

Time complexity: O((2n log n) + n + n) [where n is half the length of costs]
Space complexity: O(n)
*/

class Solution
{
    public:
        int twoCitySchedCost(vector<vector<int>> & costs)
        {
            int result=0;
            
            int twoN=costs.size();
            
            //Max heap of pairs, where each pair is composed of the difference between the cost of flying to city A 
            //and the cost of flying to city B, and the index within costs
            priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> maxHeap;
            
            //Populate the max heap
            for(int i=0;i<twoN;i++) //O(2n log n)
            {
                int savings=costs[i][0] - costs[i][1];
                
                maxHeap.emplace(savings, i);
            }
            
            int n=twoN/2;
            
            for(int count=0;count<n;count++) //O(n)
            {
                //Since we are using a max heap, the savings are sorted in descending order
                //A positve savings means the cost of flying to city A is higher than flying to city B
                //So, for the first n costs, choose flying to city B since it is cheaper
                result+=costs[maxHeap.top().second][1];
                
                maxHeap.pop();
            }
            
            for(int count=0;count<n;count++) //O(n)
            {
                //Since we choose to fly to city B the first n times, we now need to fly to city A for the next n choices
                result+=costs[maxHeap.top().second][0];
                
                maxHeap.pop();
            }
            
            return result;
        }
};