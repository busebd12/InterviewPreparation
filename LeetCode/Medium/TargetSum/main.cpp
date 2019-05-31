#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int getTotal(vector<string> & input)
{
    int total=0;

    for(string & str : input)
    {
        int number=stoi(str.substr(1));

        if(str[0]=='+')
        {
            total+=number;
        }
        else
        {
            total-=number;
        }
    }

    return total;
}

void dfs(vector<string> input, int S, int & ways, int index)
{
    if(index > input.size()-1)
    {
        int total=getTotal(input);

        if(total==S)
        {
            ways++;
        }

        return;
    }
    else
    {
        input[index]="+" + input[index];

        dfs(input, S, ways, index+1);

        input[index][0]='-';

        dfs(input, S, ways, index+1);
    }
}

int findTargetSumWaysBruteForce(vector<int> & nums, int S)
{
    int ways=0;

    if(nums.empty())
    {
        return ways;
    }

    vector<string> input;

    int index=0;

    for(auto & number : nums)
    {
        input.emplace_back(to_string(number));
    }

    dfs(input, S, ways, index);

    return ways;
}

long dfs(vector<int> & nums, long sum, int index)
{
    if(index==nums.size())
    {
        return sum==0;
    }

    long result=dfs(nums, sum+nums[index], index+1) + dfs(nums, sum-nums[index], index+1);

    return result;
}

long findTargetSumWaysRecursive(vector<int> & nums, int S)
{
    int index=0;

    long sum=long(S);

    return dfs(nums, S, index);
}

long dfs(vector<int> & nums, vector<unordered_map<int, long>> & memoization, long sum, int index)
{
    if(index==nums.size())
    {
        return sum==0;
    }

    auto itr=memoization[index].find(sum);

    if(itr!=memoization[index].end())
    {
        return itr->second;
    }

    return memoization[index][sum]=dfs(nums, memoization, sum+nums[index], index+1) + dfs(nums, memoization, sum-nums[index], index+1);

}

long findTargetSumWays(vector<int> & nums, int S)
{
    vector<unordered_map<int, long>> memoization(int(nums.size()));

    long sum=long(S);

    int index=0;

    return dfs(nums, memoization, sum, index);
}