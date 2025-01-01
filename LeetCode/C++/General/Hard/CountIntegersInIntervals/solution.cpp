#include <set>
#include <utility>
using namespace std;

class CountIntervals
{
    private:
        using Interval=pair<int, int>;

        //Custom comparator for the set of intervals
        //This comparator enforces the rule that the set must only contain non-overlapping intervals
        struct Comparator
        {
            bool operator() (const Interval & lhs, const Interval & rhs) const
            {
                return lhs.second < rhs.first;
            }
        };

        set<Interval, Comparator> intervals;

        int integersInIntervals;
    
    public:
        CountIntervals()
        {
            integersInIntervals=0;
        }
        
        void add(int left, int right)
        {
            //Use std::set's equal_range method to search for intervals that overlap with [left, right]
            auto [begin, end]=intervals.equal_range({left, right});

            //If there's at least one overlapping interval
            if(begin!=end)
            {
                int firstOverlappingIntervalBegin=begin->first;

                int lastOverlappingIntervalEnd=prev(end)->second;

                //Calculate the bounds of the interval resulting from merging all the overlapping intervals
                left=min(left, firstOverlappingIntervalBegin);

                right=max(right, lastOverlappingIntervalEnd);

                auto iterator=begin;

                //Iterate through all the overlapping intervals
                while(iterator!=end)
                {
                    int intervalStart=iterator->first;

                    int intervalEnd=iterator->second;

                    //Calculate the number of integers to remove from the rolling count
                    int integersToRemove=(intervalEnd - intervalStart) + 1;

                    //Remove the integers
                    integersInIntervals-=integersToRemove;

                    iterator++;
                }

                intervals.erase(begin, end);
            }

            //Calculate the integers to add to the rolling count
            int integersToAdd=(right - left) + 1;

            integersInIntervals+=integersToAdd;

            intervals.emplace(left, right);
        }
        
        int count()
        {
            return integersInIntervals;
        }
};