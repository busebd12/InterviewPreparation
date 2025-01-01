#include <set>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n log n) [where n is the length of paint]
Space complexity: O(n)
*/

class Solution
{
    private:
        using Interval=pair<int, int>;

        struct IntervalComparator
        {
            bool operator() (const Interval & lhs, const Interval & rhs) const
            {
                //The end of an interval can only be less than the start of the next interval
                //For example, the intervals (1, 2) and (3, 4) would be allowed in the set using this custom comparator
                //However, the intervals (0, 1), (1, 3), (3, 5) would not be allowed because there is overlap between those three intervals
                return lhs.second < rhs.first;
            }
        };

        //Set of Intervals (pair<int, int>) where we painted on a particular day
        //We use the custom comparator IntervalComparator to order the intervals within the set like so: (1, 2), (3, 4), (4, 5), (5, 6), etc...
        set<Interval, IntervalComparator> intervals;
    
    public:
        vector<int> amountPainted(vector<vector<int>> & paint)
        {
            vector<int> result;

            int n=paint.size();

            result.resize(n, 0);

            for(int day=0;day<n;day++)
            {
                int amountPainted=getAmountPainted(paint[day]);

                result[day]=amountPainted;
            }

            return result;
        }

        int getAmountPainted(vector<int> & interval)
        {
            //Assume that we can paint the entire interval
            int amountPainted=interval[1] - interval[0];

            //Beginning of the final merged interval
            int mergedIntervalBegin=interval[0];

            //End of the final merged interval
            int mergedIntervalEnd=interval[1];

            //std::set's equal_range member function will help us find any intervals that overlap with the one we are currently trying to paint
            //begin is an iterator that points to the very first overlapping interval
            //end is an interator that points to the interval after the last overlapping interval
            auto [begin, end]=intervals.equal_range({interval[0], interval[1]});

            //If begin is not equal to end, then there is at least one overlapping interval
            if(begin!=end)
            {
                //Iterate through all the overlapping intervals
                for(auto itr=begin;itr!=end;itr++)
                {
                    int intervalBegin=itr->first;

                    int intervalEnd=itr->second;

                    //Calculate the actual interval of overlap
                    int overlapBegin=max(intervalBegin, interval[0]);

                    int overlapEnd=min(intervalEnd, interval[1]);

                    //Since this overlapping interval has already been painted, we don't paint it again
                    int notPainted=overlapEnd - overlapBegin;

                    amountPainted-=notPainted;
                }

                //Construct the merged interval
                mergedIntervalBegin=min(begin->first, interval[0]);

                mergedIntervalEnd=max(interval[1], prev(end)->second);

                //Erase all overlapping intervals
                intervals.erase(begin, end);
            }

            //Insert the merged interval
            intervals.emplace(mergedIntervalBegin, mergedIntervalEnd);

            return amountPainted;
        }
};