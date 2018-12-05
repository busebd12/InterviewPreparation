#include <iostream>
#include <vector>
using namespace std;

bool increasingTriplet(vector<int> & nums)
{
    int k=3;

    if(nums.size() < k)
    {
        return false;
    }

    int n=int(nums.size());

    vector<int> sequence;

    for(int i=0;i<n;++i)
    {
        if(sequence.empty() || nums[i] > sequence.back())
        {
            sequence.emplace_back(nums[i]);
        }
        else
        {
            int left=0;

            int right=int(sequence.size()-1);

            while(left < right)
            {
                int middle=(left+right)/2;

                if(sequence[middle] < nums[i])
                {
                    left=middle+1;
                }
                else
                {
                    right=middle;
                }
            }

            sequence[right]=nums[i];
        }
    }

    return sequence.size() >= k ? true : false;
}