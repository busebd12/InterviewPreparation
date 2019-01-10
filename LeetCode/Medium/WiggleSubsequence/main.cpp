#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int wiggleMaxLength(vector<int> & nums)
{
    if(nums.empty())
    {
        return 0;
    }

    int n=int(nums.size());

    int positiveDifference=1;

    int negativeDiffernece=1;

    for(int i=1;i<n;++i)
    {
        if(nums[i] > nums[i-1])
        {
            positiveDifference=negativeDiffernece + 1;
        }
        else if(nums[i] < nums[i-1])
        {
            negativeDiffernece=positiveDifference + 1;
        }
    }

    return max(positiveDifference, negativeDiffernece);
}