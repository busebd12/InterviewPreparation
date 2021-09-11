#include <iostream>
#include <unordered_set>
#include <deque>
using namespace std;

/*
 * Approaches:
 *
 * 1) We maintain a sliding window of pings that happened within the last 3000 milliseconds using an unordered_set<int> us.
 * Each time we add a new ping time, we check all the previously stored ping and erase all pings that fall outside of our window.
 *
 * Time complexity: O(n) [where n is the number of pings from the start up till the current ping t]
 * Space complexity: O(p) [where p is the number of pings from the start up till now that fall within our desired window]
 *
 * 2) Same logic just using a deque instead of an unordered_set for our sliding window.
 *
 * Time complexity: O(n) [where n is the number of pings from the start up till the current ping t]
 * Space complexity: O(p) [where p is the number of pings from the start up till now that fall within our desired window]
 */

class RecentCounter
{
    public:
        unordered_set<int> us;

        RecentCounter()
        {

        }

        int ping(int t)
        {
            us.insert(t);

            for(auto itr=us.begin();itr!=us.end();)
            {
                if(t - (*(itr)) > 3000)
                {
                    itr=us.erase(itr);
                }
                else
                {
                    ++itr;
                }
            }

            return int(us.size());
        }
};


class RecentCounter
{
    public:
        deque<int> dq;

        RecentCounter()
        {

        }

        int ping(int t)
        {
            dq.push_back(t);

            while(t - dq.front() > 3000)
            {
                dq.pop_front();
            }

            return int(dq.size());
        }
};