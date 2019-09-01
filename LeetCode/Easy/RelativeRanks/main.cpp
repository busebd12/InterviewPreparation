#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*
 * Approach: First, hash each element in the input vector to the index at which it appears in a hashtable (unordered_map<int, int>).
 * Then, sort the input vector so that the scores are ranked from least to greatest. Then, loop over the sorted vecotr
 * in reverse and for the first three top scores, put "Gold Medal", "Silver Medal" , and "Bronze Medal" in their
 * respective places in our result vector. Finally, if the score falls outside the top three, add the rank of the
 * score, not the score itself, to the result vector.
 *
 * Time complexity: O(n log n) [where n is the size of the input vector]
 * Space complexity: O(n)
 */

vector<string> findRelativeRanks(vector<int>& nums)
{
    if(nums.empty())
    {
        return {};
    }

    int n=int(nums.size());

    vector<string> result(n);

    unordered_map<int, int> hashtable;

    for(int index=0;index<n;++index)
    {
        int number=nums[index];

        hashtable[number]=index;
    }

    sort(nums.begin(), nums.end());

    int count=1;

    for(int i=n-1;i>=0;--i,count++)
    {
        int number=nums[i];

        int targetIndex=hashtable[number];

        if(count==1)
        {
            result[targetIndex]="Gold Medal";
        }
        else if(count==2)
        {
            result[targetIndex]="Silver Medal";
        }
        else if(count==3)
        {
            result[targetIndex]="Bronze Medal";
        }
        else
        {
            result[targetIndex]=to_string(count);
        }
    }

    return result;
}