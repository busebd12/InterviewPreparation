#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>
using namespace std;

deque<deque<int>> getPermutations(deque<int> Numbers)
{
    deque<deque<int>> permutationz;
    
    if(Numbers.size()==1)
    {
        deque<int> permutationOfOne;
        
        permutationOfOne.emplace_back(Numbers[0]);
        
        permutationz.emplace_back(permutationOfOne);
    }
    else
    {
        for(int index=0;index<Numbers.size();++index)
        {
            int firstNumberIndex=index;
            
            int firstNumber=Numbers[index];
            
            deque<int> rest;
            
            for(int innerIndex=0;innerIndex<Numbers.size();++innerIndex)
            {
                if(innerIndex!=index)
                {
                    rest.emplace_back(Numbers[innerIndex]);
                }
            }
            
            deque<deque<int>> permutationsMissingTheFirstNumber=getPermutations(rest);
            
            for(auto & permutation : permutationsMissingTheFirstNumber)
            {
                permutation.push_front(firstNumber);
                
                permutationz.emplace_back(permutation);
            }
        }
        
        return permutationz;
    }
}
