#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Backtracking approach
//However, times out
void canJumpHelper(unordered_map<int, pair<int, bool>> & distances, int index, const int lastIndex, bool & result)
{
    if(index==lastIndex)
    {
        result=true;

        return;
    }

    if(distances[index].second)
    {
        result=false;

        return;
    }

    if(distances[index].first==0)
    {
        result=false;

        return;
    }

    int next=distances[index].first;

    distances[index].second=true;

    cout << "next: " << next << endl;

    cout << endl;

    for(int jump=1;jump<=next;++jump)
    {
        index+=jump;

        cout << "index: " << index << endl;

        cout << endl;

        canJumpHelper(distances, index, lastIndex, result);

        if(result==true)
        {
            return;
        }

        index-=jump;

        distances[index].second=false;
    }
}

bool canJump(vector<int> & nums)
{
    const int numsSize=int(nums.size());

    if(numsSize <= 1)
    {
        return true;
    }

    const int lastIndex=numsSize-1;

    unordered_map<int, pair<int, bool>> distances;

    for(int index=0;index<numsSize;++index)
    {
        auto p=make_pair(nums[index], false);

        distances.insert(make_pair(index, p));
    }

    int start=0;

    bool result=false;

    canJumpHelper(distances, start, lastIndex, result);

    return result;
}

bool canJump(vector<int> & nums)
{
    int numsSize=int(nums.size());

    int position=0;

    for(int i=0;i<=position && i<numsSize;++i)
    {
        position=max(position, i + nums[i]);
    }

    return (position >= numsSize-1);
}