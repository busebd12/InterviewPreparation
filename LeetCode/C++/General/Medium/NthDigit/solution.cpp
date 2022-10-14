#include <cmath>
#include <string>
using namespace std;

/*
Solution inspired by this post --> https://leetcode.com/problems/nth-digit/discuss/88400/Just-explain-no-code
*/

class Solution
{
    public:
        int findNthDigit(int n)
        {
            int result=0;
            
            if(n < 10)
            {
                return n;
            }
            
            long long numberOfDigits=1;
    
            long long totalNumbersInRange=9;

            while(n > numberOfDigits * totalNumbersInRange)
            {
                n-=(numberOfDigits * totalNumbersInRange);

                numberOfDigits+=1;

                totalNumbersInRange*=10;
            }
            
            n-=1;

            int start=pow(10, numberOfDigits - 1);

            int offset=n / numberOfDigits;

            int desiredNumber=start + offset;

            int index=(n % numberOfDigits);

            string str=to_string(desiredNumber);

            int digit=str[index] - '0';
            
            result=digit;
            
            return result;
        }
};