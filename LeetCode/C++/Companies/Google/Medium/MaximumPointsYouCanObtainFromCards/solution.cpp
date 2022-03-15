#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
Solution: inspired from this answer --> https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/discuss/597825/Simple-Clean-Intuitive-Explanation-with-Visualization

Time complexity: O(n) [where n is the number of card points]
Space complexity: O(n) [where n is the number of card points]
*/

class Solution
{
    public:
        int maxScore(vector<int> & cardPoints, int k)
        {
            int result=0;

            int n=cardPoints.size();

            vector<int> leftCumulativeSums(n+1, 0);

            vector<int> rightCumulativeSums(n+1, 0);

            int sum=0;

            for(int i=0;i<n;i++)
            {
                sum+=cardPoints[i];

                leftCumulativeSums[i+1]=sum;
            }

            sum=0;

            for(int i=n-1;i>=0;i--)
            {
                sum+=cardPoints[i];

                rightCumulativeSums[n-i]=sum;
            }

            for(int i=0;i<=k;i++)
            {
                result=max(result, leftCumulativeSums[i] + rightCumulativeSums[k-i]);
            }

            return result;
        }
};