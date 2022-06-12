#include <map>
#include <utility>
#include <vector>

/*
Solution: see comments.

Time complexity: O(n + (n * log(l1)) + (n * log(l2)) + (l1 * l2))
[where n is the length of nums, l1 is the total number of subarrays with length firstLen, and l2 is the total number of subarrays with length secondLen]

Space complexity: O(n + nl1 + l2)
*/

class Solution
{
    public:
        int maxSumTwoNoOverlap(vector<int> & nums, int firstLen, int secondLen)
        {
            int result=0;
            
            int n=nums.size();
            
            vector<int> prefixSums(n, 0);
            
            prefixSums[0]=nums[0];
            
            for(int i=1;i<n;i++) //O(n)
            {
                prefixSums[i]=prefixSums[i - 1] + nums[i];
            }
            
            //Map the start and end indices (as a pair<int, int>) of all subarrays of length "firstLen" to their respective sums
            map<pair<int, int>, int> firstLengthMap;
            
            int back=0;
            
            int front=firstLen - 1;
            
            while(front < n) //O(n)
            {
                int sum=0;
                
                if(back - 1 >= 0)
                {
                    sum=prefixSums[front] - prefixSums[back - 1];
                }
                else
                {
                    sum=prefixSums[front];
                }
                
                //Add <start index, end index> pair and sum to the map
                firstLengthMap.emplace(make_pair(back, front), sum); //O(l1)
                
                front+=1;
                
                back+=1;
            }
            
            //Map the start and end indices (as a pair<int, int>) of all subarrays of length "secondLen" to their respective sums
            map<pair<int, int>, int> secondLengthMap;
            
            back=0;
            
            front=secondLen - 1;
            
            while(front < n) //O(n)
            {
                int sum=0;
                
                if(back - 1 >= 0)
                {
                    sum=prefixSums[front] - prefixSums[back - 1];
                }
                else
                {
                    sum=prefixSums[front];
                }
                
                //Add <start index, end index> pair and sum to the map
                secondLengthMap.emplace(make_pair(back, front), sum); //O(l2)
                
                front+=1;
                
                back+=1;
            }
            
            //Iterate through all the start and end index pairs of subarrays of length "firstLen"
            for(auto & [firstIndexPair, firstSum] : firstLengthMap) //O(l1)
            {
                int back=firstIndexPair.first;
                
                int front=firstIndexPair.second;
                
                //Iterate through all the start and end index pairs of subarrays of length "secondLen"
                for(auto & [secondIndexPair, secondSum] : secondLengthMap) //O(l2)
                {
                    int i=secondIndexPair.first;
                    
                    int j=secondIndexPair.second;
                    
                    //Make sure that the arrays don't overlap
                    if(j < back || i > front)
                    {
                        int currentSum=firstSum + secondSum;
                        
                        result=max(result, currentSum);
                    }
                }
            }
            
            return result;
        }
};