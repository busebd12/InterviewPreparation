#include <deque>
using namespace std;

/*
See this video on converting base 10 numbers to any other base: https://www.youtube.com/watch?v=VUg6O0tlFcA
*/

class Solution
{
    public:
        bool isStrictlyPalindromic(int n)
        {
            for(int targetBase=2;targetBase<=n-2;targetBase++)
            {
                deque<int> remainders=getRemainders(n, targetBase);

                if(isPalindrome(remainders)==false)
                {
                    return false;
                }
            }

            return true;
        }

        deque<int> getRemainders(int baseTenNumber, int targetBase)
        {
            deque<int> remainders;
            
            while(baseTenNumber >= targetBase)
            {
                int remainder=baseTenNumber % targetBase;
                
                remainders.push_front(remainder);
                
                baseTenNumber/=targetBase;
            }
            
            remainders.push_front(baseTenNumber);
            
            return remainders;
        }

        bool isPalindrome(deque<int> & remainders)
        {
            int r=remainders.size();

            int low=0;

            int high=r - 1;

            while(low < high)
            {
                if(remainders[low]!=remainders[high])
                {
                    return false;
                }

                low+=1;

                high-=1;
            }

            return true;
        }
};