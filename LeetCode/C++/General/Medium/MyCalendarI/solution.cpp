#include <utility>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the total number of date intervals]
Space complexity: O(n)
*/

class MyCalendar
{
    private:
        vector<pair<int, int>> dates;
    
    public:
        MyCalendar()
        {

        }

        bool book(int start, int end)
        {
            bool canAdd=true;
            
            auto itr=begin(dates);
            
            while(itr!=std::end(dates))
            {
                //The beginning of the interval we are trying to add overlaps with another interval already in the calendar
                bool condition1=(itr->first <= start && start < itr->second);
                
                //The start of another interval in the calendar overlaps with the interval we are trying to add
                bool condition2=(start <= itr->first && itr->first < end);
                
                //The end of another interval in the calendar overlaps with the interval we are trying to add
                bool condition3=(start < itr->second && itr->second < end);
                
                //If any of the above three conditions are true
                if(condition1 || condition2 || condition3)
                {
                    //We can't add the interval to the calendar
                    canAdd=false;
                    
                    break;
                }
                
                itr++;
            }
            
            if(canAdd==true)
            {
                dates.emplace_back(start, end);
            }
            
            return canAdd;
        }
};