#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
using namespace std;

/*
Solution: based on this video --> https://www.youtube.com/watch?v=UtGwxAyJq7Y
Submission result: accepted
Time complexity: O(n * 2^(n/2))
Space complexity: O(2^(n/2))
*/

class Solution
{
    public:
        int minAbsDifference(vector<int> & nums, int goal)
        {
            int result=numeric_limits<int>::max();

            int n=nums.size();

            //Divide the input vector into two halves
            vector<int> firstHalf;

            for(int i=0;i<n/2;i++)
            {
                firstHalf.push_back(nums[i]);
            }

            vector<int> secondHalf;

            for(int i=n/2;i<n;i++)
            {
                secondHalf.push_back(nums[i]);
            }

            vector<int> firstHalfSums;

            int length=firstHalf.size();

            int sum=0;

            int index=0;

            //Generate all subset sums for the first half
            getSubsetSums(firstHalf, firstHalfSums, length, sum, index);

            vector<int> secondHalfSums;

            length=secondHalf.size();

            sum=0;

            index=0;

            //Generate all subset sums for the second half
            getSubsetSums(secondHalf, secondHalfSums, length, sum, index);

            sort(secondHalfSums.begin(), secondHalfSums.end());

            //For each subset sum in the first half subset sums
            for(int firstHalfSum : firstHalfSums)
            {
                //Target is the remaining amount we need to find in the second half subset sums vector in order to reach goal
                int target=goal - firstHalfSum;

                //Use binary search to find the value closest to target in secondHalfSums vector
                //Note: std::lower_bound is one the binary search algorithms from the Standard Template Library
                //which returns an iterator to the first value that is greater than or equal to target
                auto itr=lower_bound(secondHalfSums.begin(), secondHalfSums.end(), target);

                int index=itr - secondHalfSums.begin();

                int total=0;

                //If index is greater than zero, then this means there could be a number smaller than
                //the result found by lower_bound which could give us a smaller answer, so let's check
                if(index > 0)
                {
                    total=secondHalfSums[index - 1] + firstHalfSum;
                    
                    result=min(result, abs(goal - total));
                }

                //If index is less than secondHalfSums.size(), then the index of the value found by lower_bound is valid
                //and we need to calculate the absolute value difference using this value at this index
                if(index < secondHalfSums.size())
                {   
                    total=secondHalfSums[index] + firstHalfSum;
                    
                    result=min(result, abs(goal - total));
                }
            }

            return result;
        }

        void getSubsetSums(vector<int> & half, vector<int> & subsetSums, int length, int sum, int index)
        {
            if(index==length)
            {
                subsetSums.push_back(sum);

                return;
            }

            getSubsetSums(half, subsetSums, length, sum + half[index], index + 1);

            getSubsetSums(half, subsetSums, length, sum, index + 1);
        }
};