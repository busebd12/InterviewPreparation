#include <algorithm>
#include <string>
#include <vector>

/*
Solution: see comments for details

Time complexity: O(n) [where n is the total number of time points]
Space complexity: O(24 * 60) => O(1440) => O(1)
*/

class Solution
{
    public:
        int findMinDifference(vector<string> & timePoints)
        {
            int result=numeric_limits<int>::max();
            
            int totalMinutesInADay=24 * 60;
            
            //Since there are only 1440 minutes possible in a day (24 hours * 60 minutes per hour),
            //we can use bucket sort (one bucket for each amount of minutes [0, 1440]) to list the
            //total amount of minutes in each time point in an increasing manner.
            vector<bool> buckets(totalMinutesInADay, false);
            
            //The smallest amount of minutes
            int minMinutes=numeric_limits<int>::max();
            
            //The largest amount of minutes
            int maxMinutes=numeric_limits<int>::min();
            
            //Iterate through the time points
            for(string timePoint : timePoints)
            {
                //Get the index of the ':' character
                int colonIndex=timePoint.find_first_of(':');
                
                //Parse the hour part of the time point
                string hours=timePoint.substr(0, colonIndex);
                
                //Parse the minutes part of the time point
                string minutes=timePoint.substr(colonIndex + 1, string::npos);
                
                //Calculate the total minutes represented by the time point
                int totalMinutes=(stoi(hours) * 60) + stoi(minutes);
                
                //If we have already seen the amount of minutes represented by the time point,
                //then this is a repeat time point and the minimum difference will be zero
                if(buckets[totalMinutes]==true)
                {
                    return 0;
                }
                
                //Mark the amount of minutes in the current time point as seen
                buckets[totalMinutes]=true;
                
                //Keep track of the smallest and largest amount of minutes
                minMinutes=min(minMinutes, totalMinutes);
                
                maxMinutes=max(maxMinutes, totalMinutes);
            }
            
            int previous=0;
            
            //Iterate through the buckets and calculate the minimum difference between the time points (in terms of minutes)
            for(int minute=1;minute<totalMinutesInADay;minute++)
            {
                if(buckets[minute]==true)
                {   
                    if(previous > 0)
                    {
                        result=min(result, minute - previous);
                    }
                    
                    previous=minute;
                }
            }
            
            //Handle the corner case with the time points "00:00" and "23:59"
            //It takes one minute to go from "23:59" to "00:00", but a lot more to go from "00:00" to "23:59"
            int cornerCase=(totalMinutesInADay + minMinutes) - maxMinutes;
            
            result=min(result, cornerCase);
            
            return result;
        }
};