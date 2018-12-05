#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

void wiggleSort(vector<int> & nums)
{
    int n=int(nums.size());

    if(n <= 1)
    {
        return;
    }

    vector<int> sorted(nums);

    sort(sorted.begin(), sorted.end());

    int middleIndex=(n+1)/2;

    for(int k=n-1,i=0,j=middleIndex;k>=0;--k)
    {
        //nums[k]=sorted[k&1 ? j++ : i++]; //faster check for odd/even indices using &

        if(k%2==0)
        {
            nums[k]=sorted[i++];
        }
        else
        {
            nums[k]=sorted[j++];
        }
    }
}