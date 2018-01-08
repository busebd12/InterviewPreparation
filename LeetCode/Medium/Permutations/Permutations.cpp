#include <iostream>
#include <deque>
using namespace std;

deque<deque<int>> permuteHelper(vector<int> & nums)
{
    deque<deque<int>> permutationz;
  
    if(nums.size()==1)
    {
        deque<int> permutationOfOne;
      
        permutationOfOne.emplace_back(nums[0]);
      
        permutationz.emplace_back(permutationOfOne);
    }
    else
    {
        for(int i=0;i<nums.size();++i)
        {
            int firstNumberIndex=i;
          
            int firstNumber=nums[i];
          
            vector<int> rest;
          
            for(int j=0;j<nums.size();++j)
            {
                if(j!=i)
                {
                    rest.emplace_back(nums[j]);
                }
            }
          
            deque<deque<int>> permutationsMissingTheFirstNumber=permuteHelper(rest);
          
            for(auto & permutation : permutationsMissingTheFirstNumber)
            {
                permutation.push_back(firstNumber);
              
                permutationz.emplace_back(permutation);
            }
        }
    }
  
    return permutationz;
}

vector<vector<int>> permute(vector<int> & nums)
{
    vector<vector<int>> result;
  
    if(nums.empty())
    {
        return result;
    }
  
    auto permutations=permuteHelper(nums);
  
    for(const auto & permutation : permutations)
    {
        vector<int> p(begin(permutation), end(permutation));
      
        result.emplace_back(p);
    }
  
    return result;
}