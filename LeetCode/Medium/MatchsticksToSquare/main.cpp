#include <iostream>
#include <vector>
using namespace std;

/*bool dfs(vector<int> & nums, vector<bool> & used, int & firstSide, int & secondSide, int & thirdSide, int & fourthSide, int & matchsticksUsed, const int & n, int start)
{
    if(matchsticksUsed==n)
    {
        if(firstSide==secondSide && secondSide==thirdSide && thirdSide==fourthSide)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    for(int i=start;i<n;++i)
    {
        if(!used[i])
        {
            used[i]=true;

            matchsticksUsed++;

            int matchstick=nums[i];

            firstSide+=matchstick;

            if(dfs(nums, used, firstSide, secondSide, thirdSide, fourthSide, matchsticksUsed, n, i+1))
            {
                return true;
            }

            firstSide-=matchstick;

            secondSide+=matchstick;

            if(dfs(nums, used, firstSide, secondSide, thirdSide, fourthSide, matchsticksUsed, n, i+1))
            {
                return true;
            }

            secondSide-=matchstick;

            thirdSide+=matchstick;

            if(dfs(nums, used, firstSide, secondSide, thirdSide, fourthSide, matchsticksUsed, n, i+1))
            {
                return true;
            }

            thirdSide-=matchstick;

            fourthSide+=matchstick;

            if(dfs(nums, used, firstSide, secondSide, thirdSide, fourthSide, matchsticksUsed, n, i+1))
            {
                return true;
            }

            fourthSide-=matchstick;

            used[i]=false;

            matchsticksUsed--;
        }
    }

    return false;
}

bool makesquare(vector<int> & nums)
{
    if(nums.size() < 4)
    {
        return false;
    }

    int n=int(nums.size());

    vector<bool> used(n, false);

    int firstSide=0;

    int secondSide=0;

    int thirdSide=0;

    int fourthSide=0;

    int matchsticksUsed=0;

    int start=0;

    return dfs(nums, used, firstSide, secondSide, thirdSide, fourthSide, matchsticksUsed, n, start);
}*/

bool dfs(const vector<int> & nums, vector<int> & sides, int index, const int target)
{
    if(index==nums.size())
    {
        return sides[0]==sides[1] && sides[1]==sides[2] && sides[2]==sides[3];
    }

    for(int i=0;i<4;++i)
    {
        if(sides[i] + nums[index] > target)
        {
            continue;
        }

        int j=i;

        while(--j >= 0)
        {
            if(sides[i]==sides[j])
            {
                break;
            }
        }

        if(j!=-1)
        {
            continue;
        }


        sides[i]+=nums[index];

        if(dfs(nums, sides, index + 1, target))
        {
            return true;
        }

        sides[i]-=nums[index];
    }

    return false;
}

bool makesquare(vector<int> & nums)
{
    if(nums.size() < 4)
    {
        return false;
    }

    int sum=0;

    for(const int val: nums)
    {
        sum += val;
    }

    if(sum % 4 != 0)
    {
        return false;
    }

    sort(nums.begin(), nums.end(), greater<int>());

    vector<int> sides(4, 0);

    int index=0;

    int target=sum/4;

    return dfs(nums, sides, index, target);
}