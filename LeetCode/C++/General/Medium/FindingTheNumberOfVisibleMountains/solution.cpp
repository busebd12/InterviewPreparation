#include <map>
#include <utility>
#include <vector>
using namespace std;

/*
Time complexity: O((p * log(u)) + O(u)) [where p=number of peaks and u=unique intervals representing the base of the mountains]
Space complexity: O(u)
*/

class Solution
{
    public:
        int visibleMountains(vector<vector<int>> & peaks)
        {
            int result=0;

            //Custom comparator for comparing two intervals representing the base width of two mountains
            //Each mountain base interval is of the form {left point on x-axis, right point on the x-axis}
            auto compareLikeThis=[] (const pair<int, int> & lhs, const pair<int, int> & rhs)
            {
                //If the left x-axis points for the two mountains is not the same
                if(lhs.first!=rhs.first)
                {
                    //Put the mountain with the smaller left x-axis point first   
                    return lhs.first < rhs.first;
                }
                //Else, the left x-axis points for the two mountains are the same
                else
                {
                    //Put the mountain with the larger right x-axis point first
                    return lhs.second > rhs.second;
                }
            };

            //Map each interval representing the width of the mountain base to its frequency
            map<pair<int, int>, int, decltype(compareLikeThis)> uniqueMountainBaseIntervals(compareLikeThis);

            //Iterate through the peaks
            for(const vector<int> & peak : peaks)
            {
                int peakX=peak[0];

                int peakY=peak[1];

                int baseLeftX=peakX - peakY;

                int baseRightX=peakY + peakX;

                //Create the interval representing the mountain base
                pair<int, int> mountainBaseInterval(baseLeftX, baseRightX);

                //Increase the frequency of the interval
                uniqueMountainBaseIntervals[mountainBaseInterval]+=1;
            }

            //Result starts as the number of unique mountains (since two of the same mountain will count as zero peaks -> see the second example test case)
            result=uniqueMountainBaseIntervals.size();

            auto leftMountainItr=uniqueMountainBaseIntervals.begin();

            auto rightMountainItr=next(leftMountainItr);

            while(rightMountainItr!=uniqueMountainBaseIntervals.end())
            {
                int leftMountainBaseEnd=leftMountainItr->first.second;

                int rightMountainBaseEnd=rightMountainItr->first.second;

                //If the right end of the base of the left mountain is greater than or equal to the right end of the base of the right mountain,
                //then we know the left mountain eclipses or obscures the right mountain from view.
                //How do we know this? Since the intervals representing the base of the mountains are sorted by starting point,
                //the left mountain's base starts before the right mountains base.
                //Therefore, the left side of the base of the left mountain contains the left side of the base of the right mountain
                //and the right side of the base of the left mountain contains the right sideo of the base of the right mountain.
                //Thus, the entirety of the right mountain is blocked by the left mountain, including the peak
                if(leftMountainBaseEnd >= rightMountainBaseEnd)
                {
                    //Decrement the number of the right mountain since it is blocked by the left mountainBaseInterval
                    rightMountainItr->second-=1;

                    //Decrease our result
                    result-=1;

                    rightMountainItr++;
                }
                //Else, the right mountain is not blocked by the left mountain
                else
                {
                    leftMountainItr=rightMountainItr;

                    rightMountainItr++;
                }
            }

            //At this point, we need to check for cases like [[1,3],[1,3]] where we have multiple copies of the same mountain
            for(auto & [mountainBaseInterval, frequency] : uniqueMountainBaseIntervals)
            {
                //If there is more than one copy of the same mountain
                if(frequency > 1)
                {
                    //Reduce result by one since we are only interested in the total number of unique mountain peaks we can see
                    result-=1;
                }
            }

            return result;
        }
};