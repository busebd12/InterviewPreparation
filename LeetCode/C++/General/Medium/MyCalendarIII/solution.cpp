#include <algorithm>
#include <set>
#include <utility>
using namespace std;

/*
Solution: the idea is view the start and ending points of an interval as a pair of parenthesis where the starting point is a (
and the ending point is a ). Then, we can think of finding the k-intersection as simply finding the maximum nesting depth for
some group of parenthesis. We use a multiset<pair<int, int>> to store the intervals in sorted, ascending order. Then, each time
we insert an interval, we associate a 1 with the start [to mark is as the start or a (] and -1 with the end of the interval
[to mark it as the end or a )]. So, each time we want to find the k-booking, we simply insert the new interval and then
iterate over all the intervals we have so far and for each start of an interval, we increment the "nesting depth" or overlap
by 1. and for each end of an interval, we decrement the "nesting depth" or overlap by 1. After either incrementing or decrementing,
we update our max k-booking value by comparing it against the current overlap or "nesting depth".

Time complexity: O(n^2 * log(n)) [where n is the total number of intervals]
Space complexity: O(n)
*/

class MyCalendarThree
{
    private:
        multiset<pair<int, int>> intervals;
    
    public:
        MyCalendarThree()
        {
            
        }
        
        int book(int start, int end)
        {               
            intervals.emplace(start, 1);

            intervals.emplace(end, -1);

            int k=0;

            int overlap=0;

            for(auto itr=intervals.begin();itr!=intervals.end();itr++)
            {
                overlap+=itr->second;

                k=max(k, overlap);
            }

            return k;
        }
};