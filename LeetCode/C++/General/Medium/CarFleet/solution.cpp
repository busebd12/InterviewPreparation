#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

/*
Time complexity: O(n + (n * log(n)) + n) [where n is the length of position and speed]
Space complexity: O(n)
*/

class Solution
{
    public:
        int carFleet(int target, vector<int> & position, vector<int> & speed)
        {
            int result=0;
            
            int n=position.size();
            
            //Intervals of the form {carPosition, arrivalTime}
            vector<pair<int, double>> intervals;
            
            for(int i=0;i<n;i++)
            {
                int carPosition=position[i];
                
                int carSpeed=speed[i];
                
                double arrivalTime=static_cast<double>(target - carPosition) / static_cast<double>(carSpeed);
                
                intervals.emplace_back(carPosition, arrivalTime);
            }
            
            //Sort the intervals in increasing order of car position on the road
            sort(begin(intervals), end(intervals));
            
            //Initially, the fleet starts off as size 1
            pair<int, double> fleet=intervals[intervals.size() - 1];
            
            //Now, that we have created the intervals, we can re-frame creating the fleets as simply merging the intervals.
            //Since the car's positions are sorted in ascending order, and we are looping backwards through the vector,
            //each car's position will be greater than or equal to the car's position that comes before it.
            //So, if the fleet's arrival time is less than the current car's arrival time, then we need to start another
            //fleet (a.k.a start another interval) since a car that has position less than the current fleet cannot
            //arrive before the current fleet (due to the fact that cars cannot pass each other on the road).
            for(int i=intervals.size()-2;i>=0;i--)
            {
                double currentArrivalTime=intervals[i].second;
                
                double fleetArrivalTime=fleet.second;
                
                if(currentArrivalTime > fleetArrivalTime)
                {
                    result+=1;
                    
                    fleet=intervals[i];
                }
            }
            
            result+=1;
            
            return result;
        }
};