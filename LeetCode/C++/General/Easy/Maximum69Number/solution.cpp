#include <deque>
using namespace std;

/*
Time complexity: O(d) [where d is the number of digits in num]
Space complexity: O(d)
*/

class Solution
{
    public:
        int maximum69Number(int num)
        {
            int result=0;

            deque<int> digits;

            while(num > 0)
            {
                int digit=num % 10;

                digits.push_front(digit);

                num=num / 10;
            }

            int d=digits.size();

            for(int i=0;i<d;i++)
            {
                if(digits[i]==6)
                {
                    digits[i]=9;

                    break;
                }
            }

            int place=1;

            while(!digits.empty())
            {
                int value=digits.back() * place;
                
                result+=value;

                digits.pop_back();

                place*=10;
            }

            return result;
        }
};