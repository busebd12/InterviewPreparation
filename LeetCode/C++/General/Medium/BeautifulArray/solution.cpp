#include <algorithm>
#include <vector>

/*
Solution: inspired by this post

https://leetcode.com/problems/beautiful-array/discuss/1370870/Java%3A-break-up-every-arithmetic-sequence-(with-visual-intuition)

Time complexity: O(n + (n log n))
Space complexity: O(n + log(n))
*/
class Solution
{
    public:
        vector<int> beautifulArray(int n)
        {
            vector<int> ordered(n);
            
            iota(begin(ordered), end(ordered), 1);
            
            vector<int> result=helper(ordered);
            
            return result;
        }
    
        vector<int> helper(vector<int> & numbers)
        {
            if(numbers.size() <= 2)
            {
                return numbers;
            }
            
            vector<int> leftHalf;
            
            vector<int> rightHalf;
            
            for(int i=0;i<numbers.size();i++)
            {
                if((i % 2)==0)
                {
                    leftHalf.emplace_back(numbers[i]);
                }
                else
                {
                    rightHalf.emplace_back(numbers[i]);
                }
            }
            
            vector<int> arrangedLeft=helper(leftHalf);
            
            vector<int> arrangedRight=helper(rightHalf);
            
            for(int number : arrangedRight)
            {
                arrangedLeft.push_back(number);
            }
            
            return arrangedLeft;
        }
};