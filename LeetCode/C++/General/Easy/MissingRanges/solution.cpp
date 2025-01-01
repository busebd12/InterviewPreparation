#include <string>
#include <vector>
using namespace std;

/*
Time complexity: O(d) [where d is the difference between upper and lower]
Space complexity: O(m) [where m is the total number of missing ranges]
*/

class Solution
{
    public:
        vector<string> findMissingRanges(vector<int> & nums, int lower, int upper)
        {
            vector<string> result;

            int n=nums.size();

            if(n==0)
            {
                string range=createRange(lower, upper);

                result.push_back(range);

                return result;
            }

            const int inf=1e9 + 1;

            int previous=lower;

            for(int index=0;index<n;index++)
            {
                if(nums[index]!=previous)
                {
                    int rangeStart=inf;

                    int rangeEnd=inf;
                    
                    if(index==0)
                    {
                        rangeStart=lower;

                        rangeEnd=nums[index] - 1;
                    }
                    else
                    {
                        rangeStart=nums[index - 1] + 1;

                        rangeEnd=nums[index] - 1;
                    }

                    string range=createRange(rangeStart, rangeEnd);

                    result.push_back(range);
                }

                previous=nums[index] + 1;
            }

            if(previous <= upper)
            {
                string finalRange=createRange(previous, upper);

                result.push_back(finalRange);
            }

            return result;
        }

        string createRange(int rangeStart, int rangeEnd)
        {
            string range="";

            if(rangeStart==rangeEnd)
            {
                range=to_string(rangeStart);
            }
            else
            {
                range=to_string(rangeStart) + "->" + to_string(rangeEnd);
            }

            return range;
        }
};