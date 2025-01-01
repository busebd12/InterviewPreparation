#include <map>
using namespace std;

class MyCalendarTwo
{
    private:
        //Map start time to 1 [(] and end time to -1 [)]
        //We can think of overlapping intervals as nesting of ()
        map<int, int> calendar;
    
    public:
        MyCalendarTwo()
        {
            
        }
        
        bool book(int start, int end) //O(n^2 * log(n))
        {
            calendar[start]+=1;

            calendar[end]-=1;

            int overlap=0;

            int bookingsAllowed=3;

            for(auto & [time, frequency] : calendar)
            {
                //Update the nesting depth
                overlap+=frequency;

                //If the nesting depth exceeds the allowed number of overlapping books, undo the booking we just made
                if(overlap >= bookingsAllowed)
                {
                    calendar[start]-=1;

                    calendar[end]+=1;
                    
                    return false;
                }
            }

            return true;
        }
};