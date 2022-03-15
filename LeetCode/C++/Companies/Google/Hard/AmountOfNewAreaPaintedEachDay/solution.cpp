#include <algorithm>
#include <limits>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

/*
Solution 1: see comments. Note, this solution gets Time Limit Exceeded when run.

Time complexity: O(n + r + (n * l))
[where n is the length of the paint vector, r is the numeric range of the intervals, and l is the average length of an interval]

Space complexity: O(r)
*/

class Solution
{
    public:
        vector<int> amountPainted(vector<vector<int>> & paint)
        {
            int n=paint.size();

            //Hashset used to store all numbers represented by the intervals
            unordered_set<int> hashset;

            //Smallest value in the intervals
            int minValue=numeric_limits<int>::max();
    
            //Largest value in the intervals
            int maxValue=numeric_limits<int>::min();

            //Calculate the min and max values
            for(const auto & interval : paint) //O(n)
            {
                minValue=min(minValue, interval[0]);

                maxValue=max(maxValue, interval[1]);
            }

            //Populate the hashset
            for(int number=minValue;number<=maxValue;number++) //O(r)
            {
                hashset.insert(number);
            }

            vector<int> result(n, 0);

            for(int i=0;i<n;i++) //O(n)
            {
                //Tracks how much we have painted on a given day
                int amount=0;

                //Start of the interval
                int start=paint[i][0];

                //End of the interval
                int end=paint[i][1];

                //Iterate through the interval
                for(int number=start;number<end;number++) //O(l)
                {
                    //If the value is in the hashset
                    if(hashset.count(number))
                    {
                        //Remove it
                        hashset.erase(number);
                        
                        amount++;
                    }
                }

                //Update the result vector with how much we painted on this day
                result[i]=amount;
            }

            return result;
        }
};

/*
Solution 2: see comments

Time complexity: O(n + r + n * (log(h) * l * log(h)))
[where n is the length of the paint vector, r is the numeric range of the all the intervals, l is average length of an interval, and h is the hashset size]

Space complexity: O(r)
*/
class Solution
{
    public:
        vector<int> amountPainted(vector<vector<int>> & paint)
        {
            int n=paint.size();

            //Hashset used to store all numbers represented by the intervals
            set<int> hashset;

            //Smallest value in the intervals
            int minValue=numeric_limits<int>::max();

            //Largest value in the intervals
            int maxValue=numeric_limits<int>::min();

            //Calculate the min and max values
            for(const auto & interval : paint) //O(n)
            {
                minValue=min(minValue, interval[0]);

                maxValue=max(maxValue, interval[1]);
            }

            //Populate the hashset
            for(int number=minValue;number<=maxValue;number++) //O(r)
            {
                hashset.insert(number);
            }

            vector<int> result(n, 0);

            for(int i=0;i<n;i++) //O(n)
            {
                //Tracks how much we have painted on a given day
                int amount=0;

                int startOfInterval=paint[i][0];

                int endOfInterval=paint[i][1];
                
                //Iterator pointing to the first value from the hashset that is not less than the start of the current interval (aka equal to the start of the current interval)
                auto itr=hashset.lower_bound(startOfInterval); //O(log(h))
                
                //Iterate through values contained within the current interval
                while(itr!=end(hashset) && *itr < endOfInterval) //O(l)
                {
                    //Erase the value
                    itr=hashset.erase(itr); //O(log(h))
                    
                    amount++;
                }

                //Update the result vector with how much we painted on this day
                result[i]=amount;
            }

            return result;
        }
};