#include <deque>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: see comments

Time complexity: O(2^n)
Space complexity: O(2^n)
*/

class Solution
{
    public:
        int racecar(int target)
        {
            //Queue to hold pairs - <position, speed>
            deque<pair<int, long>> queue;
    
            //unordered_set<string> used to hold string representations of <position, speed> pairs we've seen before
            unordered_set<string> seen;

            int startingPosition=0;

            long startingSpeed=1;

            seen.insert(to_string(startingPosition) + "|" + to_string(startingSpeed));

            queue.emplace_back(make_pair(startingPosition, startingSpeed));

            int result=0;

            while(!queue.empty())
            {
                int qSize=queue.size();

                bool done=false;

                //Iterate through the current level
                for(int count=0;count<qSize;count++)
                {
                    auto [currentPosition, currentSpeed]=queue.front();

                    queue.pop_front();

                    //If we have reached the target, we are done
                    if(currentPosition==target)
                    {
                        done=true;

                        break;
                    }

                    int forwardPosition=currentPosition + currentSpeed;

                    long forwardSpeed=currentSpeed * 2;

                    //String representation of forward state
                    string forwardState=to_string(forwardPosition) + "|" + to_string(forwardSpeed);

                    //If we haven't seen this pair of position + speed and the new forward position moves us closer to our target (not away from it)
                    if(!seen.count(forwardState) && abs(target - forwardPosition) < target)
                    {
                        //Mark forward state as seen
                        seen.insert(forwardState);

                        //Enqueue forward state pair
                        queue.emplace_back(make_pair(forwardPosition, forwardSpeed));
                    }

                    int backwardsPosition=currentPosition;

                    long backwardsSpeed=(currentSpeed > 0) ? -1 : 1;

                    //String representation of backwards state (go in reverse)
                    string backwardsState=to_string(backwardsPosition) + "|" + to_string(backwardsSpeed);

                    //If we haven't seen this pair of position + speed and the new backwards position moves us closer to our target (not away from it)
                    if(!seen.count(backwardsState) && abs(target - backwardsPosition) < target)
                    {
                        //Mark backwards state as seen
                        seen.insert(backwardsState);

                        //Enqueue backwards state pair
                        queue.emplace_back(make_pair(backwardsPosition, backwardsSpeed));
                    }
                }

                //If we are done, break out of the while loop
                if(done)
                {
                    break;
                }

                //Increment the number of instructions after iterating through the current level
                result+=1;
            }

            return result;
        }
};