#include <iostream>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

/*
 * Approach: using a hashtable (unordered_map), as messages come in, we check to see if the message is in the hashtable.
 * If the message is not in the hashtable, then it hasn't been logged before and we can map it to its timestamp in the hashtable.
 * If the message is in the hashtable, then if the difference between the previous timestamp and its current timestamp is
 * less than the allotted time (10 seconds), we don't logg the message. Else, we do log the message and update the timestamp
 * with the most current one.
 *
 * Time complexity: O(number of calls to shouldPrintMessage function)
 * Space complexity: O(number of unique messages)
 */
class Logger
{
    public:
        unordered_map<string, int> hashtable;

        int window=10;

        Logger()
        {

        }

        bool shouldPrintMessage(int timestamp, string message)
        {
            if(!hashtable.count(message))
            {
                hashtable.insert(make_pair(message, timestamp));

                return true;
            }
            else
            {
                int lag=abs(hashtable[message] - timestamp);

                if(lag < window)
                {
                    return false;
                }
                else
                {
                    hashtable[message]=timestamp;

                    return true;
                }
            }
        }
};