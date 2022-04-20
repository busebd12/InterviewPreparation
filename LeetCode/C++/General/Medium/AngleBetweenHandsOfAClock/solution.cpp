/*
Solution: inspired by this video: https://www.youtube.com/watch?v=SZMMkJv0_UI

Time complexity: O(1)
Space complexity: O(1)
*/

class Solution
{
    public:
        double angleClock(int hour, int minutes)
        {
            double result{};
            
            //Hour hand moves 30 degrees every hour
            double hourDegrees=30 * hour;
            
            //Minute hand moves 6 degrees every hour
            double minuteDegrees=6 * minutes;
            
            //Hour hand moves 0.5 degrees every minute
            double extraHourDegrees=0.5 * minutes;
            
            //If there are more than zero minutes, then the hour hand moves an additional 0.5 degree for each minute
            hourDegrees+=extraHourDegrees;
            
            result=abs(minuteDegrees - hourDegrees);
            
            //The largest angle that can be formed is when the hour hand is on 12 and the minute hand is on 6 --> 180 degree
            //If the angle is larger than that, we need to make it acute
            if(result > 180)
            {
                result=360 - result;
            }
            
            return result;
        }
};