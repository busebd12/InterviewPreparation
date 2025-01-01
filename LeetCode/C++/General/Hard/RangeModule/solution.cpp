#include <set>
#include <utility>
using namespace std;

/*
Solution: see comments.

https://leetcode.com/problems/range-module/solutions/1225934/c-fast-set-equal-range-solution-with-explanation/

Time complexity: O(n log n) [where n is the number of calls to addRange, queryRange, and removeRange]
Space complexity: O(n)
*/

class RangeModule
{
    private:
        using Interval=pair<int, int>;

        struct Comparator
        {
            bool operator()(const Interval & lhs, const Interval & rhs) const
            {
                //The end of one interval must be strictly less than the start of the next interval
                return lhs.second < rhs.first;
            }
        };

        //Set of Intervals (pair<int, int>) that we order using the custom comparator like so: (1, 2), (3, 4), (5, 6), etc...
        set<Interval, Comparator> intervals;
    
    public:
        RangeModule()
        {
            
        }
        
        void addRange(int left, int right)
        {
            //std::set's equal_range function will help us find intervals that overlap with [left, right)
            //begin is an iterator pointing to the first overlapping interval
            //end is an interator pointing to the interval after the last overlapping interval
            auto [begin, end]=intervals.equal_range({left, right});

            //If begin is not equal to end, then there is at least one overlapping interval
            if(begin!=end)
            {
                int firstOverlappingIntervalBegin=begin->first;

                int lastOverlappingIntervalEnd=prev(end)->second;
                
                //Calculate the interval left over after we've removed all the overlapping ones
                left=min(left, firstOverlappingIntervalBegin);

                right=max(right, lastOverlappingIntervalEnd);

                //Erasing all overlapping intervals
                intervals.erase(begin, end);
            }

            //Inserting the remaining range into the set
            intervals.emplace(left, right);
        }

        bool queryRange(int left, int right)
        {
            auto [begin, end]=intervals.equal_range({left, right});

            int firstOverlappingIntervalBegin=begin->first;

            int firstOverlappingIntervalEnd=begin->second;

            return begin!=end and firstOverlappingIntervalBegin <= left and right <= firstOverlappingIntervalEnd;
        }
        
        void removeRange(int left, int right)
        {
            auto [begin, end]=intervals.equal_range({left, right});

            if(begin!=end)
            {
                int firstOverlappingIntervalBegin=begin->first;

                int lastOverlappingIntervalEnd=prev(end)->second;

                //Erase the overlapping intervals
                intervals.erase(begin, end);

                //If there is a left over range to the left of the overlapping intervals, insert it into the set
                if(firstOverlappingIntervalBegin < left)
                {
                    intervals.emplace(firstOverlappingIntervalBegin, left);
                }

                //If there is a left over range to the right of the overlapping intervals, insert it into the set
                if(right < lastOverlappingIntervalEnd)
                {
                    intervals.emplace(right, lastOverlappingIntervalEnd);
                }
            }
        }
};