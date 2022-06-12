#include <deque>
#include <numeric>
using namespace std;

/*
Solution: inspired by these pages

1) https://en.wikipedia.org/wiki/Negative_base#Calculation

2) https://leetcode.com/problems/convert-to-base-2/discuss/540820/python-fast-(greater98)-short-detailed-explanation-and-some-tips-only-basic-arithmetics-any-base

3) https://helloacm.com/the-negabinary-algorithm-how-to-convert-to-base-minus-two-2/

Time complexity: O(n)
Space complexity: O(d) [where d is the number of digits in the result string]
*/

class Solution
{
    public:
        string baseNeg2(int n)
        {
            if(n==0)
            {
                return "0";
            }
            
            const int BASE=-2;
            
            deque<char> digits;
            
            while(n != 0)
            {
                div_t divResult=div(n, -2);
                
                if(divResult.rem < 0)
                {
                    n=divResult.quot + 1;
                }
                else
                {
                    n=divResult.quot;
                }
                
                if(divResult.rem < 0)
                {
                    divResult.rem=divResult.rem - BASE;
                }
                
                digits.push_front(divResult.rem + '0');
            }
            
            string result(begin(digits), end(digits));
            
            return result;
        }
};