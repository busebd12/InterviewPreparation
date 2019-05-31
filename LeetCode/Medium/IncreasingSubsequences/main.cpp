#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <sstream>
using namespace std;

bool isIncreasing(vector<int> & subsequence)
{
    int n=int(subsequence.size());

    for(int i=1;i<n;++i)
    {
        if(subsequence[i-1] > subsequence[i])
        {
            return false;
        }
    }

    return true;
}

bool isDuplicate(vector<vector<int>> & results, vector<int> & subsequence)
{
    for(auto & result : results)
    {
        if(result.size()==subsequence.size())
        {
            if(equal(result.begin(), result.end(), subsequence.begin()))
            {
                return true;
            }
        }
    }

    return false;
}

void dfsBruteForce(vector<vector<int>> & results, vector<int> & nums, vector<int> subsequence, int k, int start)
{
    if(subsequence.size() >= k)
    {
        if(!isDuplicate(results, subsequence) && isIncreasing(subsequence))
        {
            results.emplace_back(subsequence);
        }
    }

    for(int i=start,n=int(nums.size());i<n;++i)
    {
        if(nums[i] < subsequence.back())
        {
            continue;
        }

        subsequence.emplace_back(nums[i]);

        dfsBruteForce(results, nums, subsequence, k, i+1);

        subsequence.pop_back();
    }
}

vector<vector<int>> findSubsequencesBruteForce(vector<int> & nums)
{
    vector<vector<int>> results;

    if(nums.empty())
    {
        return results;
    }

    vector<int> subsequence;

    int k=2;

    int start=0;

    dfsBruteForce(results, nums, subsequence, k, start);

    return results;
}

void dfs(vector<int> & nums, unordered_set<string> & cache, vector<string> & subsequence, int k, int start)
{
    if(subsequence.size() >= k)
    {
        string candidate{};

        int n=int(subsequence.size());

        for(int index=0;index<n;++index)
        {
            candidate+=subsequence[index];

            if(index < n-1)
            {
                candidate+="%";
            }
        }

        if(!cache.count(candidate))
        {
            cache.insert(candidate);
        }
    }

    for(int i=start,n=int(nums.size());i<n;++i)
    {
        if(!subsequence.empty())
        {
            int last=stoi(subsequence.back());

            if(nums[i] < last)
            {
                continue;
            }
        }

        subsequence.emplace_back(to_string(nums[i]));

        dfs(nums, cache, subsequence, k, i+1);

        subsequence.pop_back();
    }
}

vector<vector<int>> findSubsequences(vector<int> & nums)
{
    vector<vector<int>> results;

    if(nums.empty())
    {
        return results;
    }

    int n=int(nums.size());

    int k=2;

    int start=0;

    unordered_set<string> cache;

    vector<string> subsequence;

    dfs(nums, cache, subsequence, k, start);

    for(auto & element : cache)
    {
        stringstream ss(element);

        string part{};

        vector<int> v;

        while(getline(ss, part, '%'))
        {
            v.emplace_back(stoi(part));
        }

        results.emplace_back(v);
    }

    return results;
}