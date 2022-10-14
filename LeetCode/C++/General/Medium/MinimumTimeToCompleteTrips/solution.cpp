#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
    public:
        long long minimumTime(vector<int> & time, int totalTrips)
        {
            long long result=0;
            
            int t=time.size();
            
            int minTimeToCompleteOneTrip=numeric_limits<int>::max();
            
            for(int timePoint : time)
            {
                minTimeToCompleteOneTrip=min(minTimeToCompleteOneTrip, timePoint);
            }
            
            long long maxTime=(long long)totalTrips * (long long)minTimeToCompleteOneTrip;
            
            long long low=1;
            
            long long high=maxTime;
            
            int tripCount=0;
            
            while(low <= high)
            {
                long long timePoint=low + ((high - low)/2);
                
                long long trips=getTotalTrips(time, t, timePoint);
                
                if(trips==totalTrips)
                {
                    result=timePoint;
                    
                    high=timePoint - 1;
                }
                else if(trips > totalTrips)
                {
                    high=timePoint - 1;
                }
                else if(trips < totalTrips)
                {
                    low=timePoint + 1;
                }
            }
            
            return low;
        }
        
        long long getTotalTrips(vector<int> & time, int t, long long timePoint)
        {
            long long total=0;
                
            for(int index=0;index<t;index++)
            {
                int trips=timePoint / time[index];

                total+=trips;
            }
            
            return total;
        }
};