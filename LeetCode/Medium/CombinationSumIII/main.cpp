#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int>> & result, vector<int> & combination, int k, int n, int & sum, int start, int upperBound)
{
    if(combination.size()==k && sum==n)
    {
        result.emplace_back(combination);

        return;
    }

    for(int i=start;i<=upperBound;++i)
    {
        combination.emplace_back(i);

        sum+=i;

        helper(result, combination, k, n, sum, i+1, upperBound);

        combination.pop_back();

        sum-=i;
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> result;

    if(k==0 || n==0)
    {
        return result;
    }

    vector<int> combination;

    int sum=0;

    int start=1;

    int upperBound=9;

    helper(result, combination, k, n, sum, start, upperBound);

    return result;
}