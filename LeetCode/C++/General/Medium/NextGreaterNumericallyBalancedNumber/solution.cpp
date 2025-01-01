#include <vector>
using namespace std;

class Solution
{
    public:
        int nextBeautifulNumber(int n)
        {
            int result=0;

            int limit=1224444;

            for(int number=n+1;number<=limit;number++)
            {
                if(isBalanced(number)==true)
                {
                    result=number;

                    break;
                }
            }

            return result;
        }

        bool isBalanced(int number)
        {
            vector<int> frequencies(10, 0);

            while(number > 0)
            {
                int digit=number % 10;

                if(digit==0)
                {
                    return false;
                }

                frequencies[digit]+=1;

                number=number / 10;
            }

            for(int digit=0;digit<10;digit++)
            {
                if(frequencies[digit] > 0 and frequencies[digit]!=digit)
                {
                    return false;
                }
            }

            return true;
        }
};