#include <deque>
#include <string>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        string findContestMatch(int n)
        {
            string result="";

            deque<string> queue;

            //Generate list of n teams (as strings) and store them in a deque
            for(int number=1;number<=n;number++)
            {
                queue.emplace_back(to_string(number));
            }

            //While we haven't found a winning team
            while(queue.size() > 1)
            {
                //The winning teams from this round
                deque<string> next;

                //While there are still matches to be played
                while(!queue.empty())
                {
                    //Combine the highest and lowest ranked teams
                    string combined='(' + queue.front() + ',' + queue.back() + ')';

                    queue.pop_front();

                    queue.pop_back();

                    //Add to the next level
                    next.push_back(combined);
                }

                //Make the next level the current level
                queue=next;
            }

            //The result will be the single remaining team
            result=queue.front();

            return result;
        }
};