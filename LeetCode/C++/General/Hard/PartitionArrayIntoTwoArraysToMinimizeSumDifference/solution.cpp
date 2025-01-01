#include <algorithm>
#include <limits>
#include <numeric>
#include <vector>
using namespace std;

/*
Solution: based on the following resources:

1) https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/solutions/1630774/python-explanation-with-pictures-binary-search/
2) https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/solutions/2538231/c-meet-in-the-middle-binary-search-explained/
3) https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/solutions/2850095/c-first-timers-explanation-meet-in-middle-simplest-code/

Submission result: accepted
*/

class Solution
{
    public:
        int minimumDifference(vector<int> & nums)
        {
            int result=numeric_limits<int>::max();

            int n=nums.size();

            int half=n/2;

            int total=accumulate(nums.begin(), nums.end(), 0);

            vector<int> firstHalf;

            for(int i=0;i<half;i++)
            {
                firstHalf.push_back(nums[i]);
            }

            vector<int> secondHalf;

            for(int i=half;i<n;i++)
            {
                secondHalf.push_back(nums[i]);
            }

            vector<vector<int>> firstHalfSubArraySums(half + 1, vector<int>());

            int length=0;

            int sum=0;

            int index=0;

            getSubArraySums(firstHalfSubArraySums, firstHalf, half, length, sum, index);

            vector<vector<int>> secondHalfSubArraySums(half + 1, vector<int>());

            length=0;

            sum=0;

            index=0;

            getSubArraySums(secondHalfSubArraySums, secondHalf, half, length, sum, index);

            for(vector<int> & sums : secondHalfSubArraySums)
            {
                sort(sums.begin(), sums.end());
            }

            for(int firstHalfLength=0;firstHalfLength<=half;firstHalfLength++)
            {
                int secondHalfLength=half - firstHalfLength;
                
                for(int firstHalfSum : firstHalfSubArraySums[firstHalfLength])
                {
                    int halfOfTotal=total / 2;
                    
                    int target=halfOfTotal - firstHalfSum;

                    auto itr=lower_bound(secondHalfSubArraySums[secondHalfLength].begin(), secondHalfSubArraySums[secondHalfLength].end(), target);

                    int index=itr - secondHalfSubArraySums[secondHalfLength].begin();

                    int difference=0;

                    int firstArraySum=0;

                    int secondArraySum=0;

                    if(index > 0)
                    {
                        firstArraySum=firstHalfSum + secondHalfSubArraySums[secondHalfLength][index - 1];
                        
                        secondArraySum=total - firstArraySum;

                        difference=abs(firstArraySum - secondArraySum);

                        result=min(result, difference);
                    }

                    if(index < secondHalfSubArraySums[secondHalfLength].size())
                    {
                        firstArraySum=firstHalfSum + secondHalfSubArraySums[secondHalfLength][index];
                        
                        secondArraySum=total - firstArraySum;

                        difference=abs(firstArraySum - secondArraySum);

                        result=min(result, difference);
                    }
                }
            }

            return result;
        }

        void getSubArraySums(vector<vector<int>> & subArraySums, vector<int> & subArray, int n, int length, int sum, int index)
        {
            if(index==n)
            {
                subArraySums[length].push_back(sum);

                return;
            }

            getSubArraySums(subArraySums, subArray, n, length + 1, sum + subArray[index], index + 1);

            getSubArraySums(subArraySums, subArray, n, length, sum, index + 1);
        }
};