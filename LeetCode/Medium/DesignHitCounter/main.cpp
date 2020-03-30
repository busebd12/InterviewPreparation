#include <iostream>
#include <vector>

/*
 * Solution: we use a vector of integers to store the hits. Since the hits are given in ascending order,
 * there is no need to sort or group the hits in any way. Next, we calculate the window of time in which
 * we want to count hits in. Then, we loop through the vector of hits and if a hit falls within the desired
 * window we increment the count variable. After iterating through all the hits, we return the count.
 *
 * Time complexity: O(L) [where L is the largest timestamp value]
 * Space complexity: O(T) [where T is total number of timestamps]
 */

class HitCounter
{
    public:
        std::vector<int> hits;

        HitCounter()
        {

        }

        void hit(int timestamp)
        {
            hits.emplace_back(timestamp);
        }


        int getHits(int timestamp)
        {
            int difference=0;

            if(timestamp > 300)
            {
                difference=timestamp - 300;
            }

            int count=0;

            for(auto & hit : hits)
            {
                if(hit > difference && hit <= timestamp)
                {
                    count++;
                }
            }

            return count;
        }
};