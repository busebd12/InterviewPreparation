#include <algorithm>
#include <string>
#include <vector>

/*
Solution: see comments.

Time complexity: O(L * (n log n)) [where L is the average number of digits of a number and n is the length of nums]
Space complexity: O(n)

*/

class Solution
{
    public:
        string largestNumber(vector<int> & nums)
        {
            string result{};
            
            //Custom comparator used to sort nums that is the crux of the solution
            //The idea is for two numbers, X and Y, the custom comparator will not compare X and Y with each other,
            //but will compare XY and YX and the larger number will come first in the sorted order.
            //So, for example, if we have the two numbers 15 and 4, instead of comparing 15 and 4, the function will compare 154
            //(15 combined with 4) and 415 (4 combined with 15)
            //Note: the combined numbers will be compared as strings
            auto likeThis=[&nums] (int & num1, int & num2)
            {
                string s1=to_string(num1);
                
                string s2=to_string(num2);
                
                string s3=s1 + s2;
                
                string s4=s2 + s1;
                
                return s3 > s4;
            };
            
            //Sort the input based on the custom comparator
            sort(begin(nums), end(nums), likeThis);
            
            //Build the result string from the list of sorted numbers
            for(int & number : nums)
            {
                result.append(to_string(number));
            }
            
            //Corner case: the result string is composed of all zero digits (the input list of numbers was all zeros)
            //All we need to do is just remove all zeros except for one
            if(all_of(begin(result), end(result), [] (char & c) {return c=='0';}))
            {
                while(result.size() > 1)
                {
                    result.pop_back();
                }
            }
            
            return result;
        }
};