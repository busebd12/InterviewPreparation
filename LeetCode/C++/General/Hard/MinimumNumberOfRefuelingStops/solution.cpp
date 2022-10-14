#include <queue>
#include <vector>
using namespace std;

class Solution
{
    public:
        int minRefuelStops(int target, int startFuel, vector<vector<int>> & stations)
        {
            int result=0;
            
            if(startFuel >= target)
            {
                return result;
            }
            
            int n=stations.size();
            
            //Maximum heap to hold the amounts of fuel we collected from refueling stations we visited along the way to our destination
            priority_queue<int, vector<int>, less<int>> maxHeap;
            
            int position=startFuel;
            
            int i=0;
            
            while(position < target)
            {
                //While there are still re-fueling stations available and the positions of the refeuling stations are reachable given the
                //total amount of fuel we have, add the fuel we can get at those stations to the max heap
                while(i < n and stations[i][0] <= position)
                {
                    maxHeap.emplace(stations[i][1]);
                    
                    i+=1;
                }
                
                //If we run out of fuel and there isn't any fuel from previous stations that we have already visted,
                //then we can't reach the destination, so return -1
                if(maxHeap.empty())
                {
                    return -1;
                }
                
                //By using a max heap, the different amounts of fuel we have collected from prior stations will be ordered from greatest to least,
                //so the largest amont of fuel we can use to refuel will be at the top of the heap
                //So, when we run out of fuel, we greedily select the largest refueling amount available and continue to drive towards the destination
                position+=maxHeap.top();
                
                //Increment the number of refueling stops used
                result+=1;
                
                //Remove fuel amount from the max heap
                maxHeap.pop();
            }
            
            //We were able to reach our destination, so return the number of refueling stops it took
            return result;
        }
};