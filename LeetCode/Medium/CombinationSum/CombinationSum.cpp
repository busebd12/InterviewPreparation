#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combinationSum(vector<vector<int>> & result, vector<int> & candidates, vector<int> & combination, int target, int start, const size_t candidatesSize)
{
    if(target==0)
    {
        result.emplace_back(combination);
        
        return;
    }
  
    for(int index=start;index<candidatesSize && target >= candidates[index];++index)
    {
        combination.emplace_back(candidates[index]);
      
        combinationSum(result, candidates, combination, target-candidates[index], index, candidatesSize);
      
        combination.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> & candidates, int target)
{
    vector<vector<int>> result;
    
    if(candidates.empty())
    {
        return result;
    }
  
    const size_t candidatesSize=candidates.size();
    
    if(!is_sorted(begin(candidates), end(candidates)))
    {
        sort(begin(candidates), end(candidates));
    }
  
    vector<int> combination;
  
    combinationSum(result, candidates, combination, target, 0, candidatesSize);
  
    return result;
}