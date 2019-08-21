#include <iostream>
#include <deque>
using namespace std;

/*
 * Approach: use a deque as our sliding window. Every time we add a new element,
 * we check to see if the size of our deque is the same size as our sliding window.
 * If it is we remove the oldest element from the deque, subtract the oldest element
 * from our average, add the new value to our average, and then add the new value to the deque.
 * If the size of our deque is less than the sliding window size, then we just add the new
 * value to the deque and add the new value to our average.
 *
 * Time complexity: O(number of calls to next)
 * Space complexity: O(size of the sliding window)
 */

class MovingAverage
{
    public:
        deque<int> slidingWindow;

        int slidingWindowSize;

        double average=0;

        MovingAverage(int size)
        {
            slidingWindowSize=size;
        }

        double next(int val)
        {
            if(slidingWindow.size() < slidingWindowSize || slidingWindow.empty())
            {
                average+=val;

                slidingWindow.push_back(val);
            }
            else if(slidingWindow.size()==slidingWindowSize)
            {
                average-=slidingWindow.front();

                slidingWindow.pop_front();

                average+=val;

                slidingWindow.push_back(val);
            }

            return (average/double(slidingWindow.size()));
    }

};