#include <iostream>
#include <vector>
using namespace std;

void backtracking(vector<vector<int>> & combinations, vector<int> combination, int n, int k, int start)
{
    if(combination.size()==k)
    {
        combinations.emplace_back(combination);

        return;
    }

    //loop till less than or equal to and not just less than n because, when we've incremented
    //start for the nth time, start will be greater than n at that point
    for(int i=start;i<=n;++i)
    {
        combination.emplace_back(i);

        backtracking(combinations, combination, n, k, ++start);

        combination.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> combinations;

    if(n==0 || k==0)
    {
        return combinations;
    }

    vector<int> combination;

    int start=1;

    backtracking(combinations, combination, n, k, start);

    return combinations;
}