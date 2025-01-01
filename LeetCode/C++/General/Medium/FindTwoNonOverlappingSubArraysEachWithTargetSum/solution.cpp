#include <algorithm>
#include <deque>
#include <limits>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n=length of arr]
Space complexity: O(p) [where p=number of pairs of subarray start and end indices]
*/

class Solution
{
    public:
        int minSumOfLengths(vector<int> & arr, int target)
        {
            int result=-1;

            int n=arr.size();

            int sum=0;

            int previousMinSubarrayLength=numeric_limits<int>::max();

            deque<pair<int, int>> previousSubarrayIndices;

            int left=0;

            for(int right=0;right<n;right++)
            {
                sum+=arr[right];

                while(sum > target and left < right)
                {
                    sum-=arr[left];

                    left+=1;
                }

                while(!previousSubarrayIndices.empty() and previousSubarrayIndices.front().second < left)
                {
                    int length=(previousSubarrayIndices.front().second - previousSubarrayIndices.front().first) + 1;

                    previousSubarrayIndices.pop_front();

                    previousMinSubarrayLength=min(previousMinSubarrayLength, length);
                }

                if(sum==target)
                {
                    if(previousMinSubarrayLength!=numeric_limits<int>::max())
                    {
                        int currentLength=(right - left) + 1;

                        int total=currentLength + previousMinSubarrayLength;

                        if(result==-1 or total < result)
                        {
                            result=total;
                        }
                    }

                    previousSubarrayIndices.emplace_back(left, right);
                }
            }

            return result;
        }
};