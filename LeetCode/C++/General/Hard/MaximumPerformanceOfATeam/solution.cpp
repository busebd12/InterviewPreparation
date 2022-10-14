#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

/*
Time complexity: O(n + (n log n) + (n * log(k)))
Space complexity: O(n + k)
*/

class Solution
{
    public:
        int maxPerformance(int n, vector<int> & speed, vector<int> & efficiency, int k)
        {
            long result=0;
            
            const int MOD=1e9 + 7;
            
            vector<pair<int, int>> engineers;
            
            for(int i=0;i<n;i++) //O(n)
            {
                engineers.emplace_back(speed[i], efficiency[i]);
            }
            
            //Custom comparator for engineer's efficiency
            auto compareLikeThis=[] (pair<int, int> & lhs, pair<int, int> & rhs)
            {
                return lhs.second > rhs.second;
            };
            
            //Sort the engineers based on their efficiencies in descending order
            sort(begin(engineers), end(engineers), compareLikeThis); //O(n log n)
            
            //Minimum heap to used to store engineer's speed
            priority_queue<int, vector<int>, greater<int>> minHeap;
            
            long speedSum=0;
            
            for(auto & [engineerSpeed, engineerEfficiency] : engineers) //O(n * log(k))
            {
                //Add current engineer's speed to the minHeap
                minHeap.emplace(engineerSpeed);
                
                //Add the speed to the speed sum
                speedSum+=engineerSpeed;
                
                //Since we can only choose at most k engineers, whenever the heap size becomes larger than k, we remove the speed of the slowest engineer, which is the top of the heap since we are using a min heap
                if(minHeap.size() > k)
                {
                    speedSum-=minHeap.top();
                    
                    minHeap.pop();
                }
                
                //Calculate the performance of the team created so far
                long performance=speedSum * engineerEfficiency;
                
                result=max(result, performance);
            }
            
            return static_cast<int>(result % MOD);
        }
};