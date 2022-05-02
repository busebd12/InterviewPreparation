#include <algorithm>
#include <string>
using namespace std;

/*
Solution: see comments.

Time complexity: O((d log d) + d) [where d is the number of digits in n]
Space complexity: O(d)

*/

class Solution
{
    public:
        int nextGreaterElement(int n)
        {
            int result=-1;
            
            //Convert input number to a string
            string digits=to_string(n);
    
            //Sort the digits of the number as the digits have to be sorted to use std::nex_permutation function
            sort(begin(digits), end(digits));

            //While there is a next permutation
            while(next_permutation(begin(digits), end(digits)))
            {
                //Convert the string to a long to check for case of the number being larger than INT_MAX
                long next=stol(digits);
                
                //Make sure the next number is greater than n and less than INT_MAX
                if(next > n && next <= numeric_limits<int>::max())
                {
                    result=next;
                    
                    break;
                }
            }
            
            return result;
        }
};