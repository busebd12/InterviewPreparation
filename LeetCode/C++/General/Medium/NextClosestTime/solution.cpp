#include <set>
#include <string>
using namespace std;

/*
Solution: see comments.

Time complexity: O(log(4)) --> O(1)
Space complexity: O(4) --> O(1)
*/

class Solution
{
    public:
        string nextClosestTime(string time)
        {
            string result=time;

            int n=time.size();

            //Use a set to sort the digits of time in increasing order
            set<char> ordered;

            //Insert each numerical digit
            for(char digit : time)
            {
                if(digit!=':')
                {
                    ordered.insert(digit);
                }
            }

            int smallest=*(ordered.begin());

            //limits[i]=the largest possible value for each digit of the time
            vector<char> limits={'2', '9', '0', '5', '9'};

            //Iterate through time in reverse order and greedily try to increase the value of each digit
            for(int i=n-1;i>=0;i--)
            {
                //If we are dealing with a digit
                if(time[i]!=':')
                {
                    //Use std::set's upper_bound (binary search) function to search for the next larger digit to replace the current one with
                    auto itr=ordered.upper_bound(time[i]);

                    //If there isn't a next larger digit or the next larger digit is too big
                    if(itr==ordered.end() or *itr > limits[i])
                    {
                        //Just use the smallest digit instead
                        time[i]=smallest;
                    }
                    //Else, we found a valid next larger digit
                    else
                    {
                        //Do the replacement
                        time[i]=*(itr);

                        //We want to break since after this replacement we have formed the smallest
                        //next larger time and we don't want to do any more replacements after this
                        break;
                    }
                }
            }

            //If the first digit in the resulting time is 2, then the second digit can only have a max value of 3
            if(time[0]=='2' and time[1] > '3')
            {
                //Replace the digit with the smallest value
                time[1]=smallest;
            }

            return time;
        }
};