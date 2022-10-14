#include <unordered_set>
using namespace std;

/*
Time complexity: O(c + s) [s is the total amount of square numbers less than or equal to c]
Space complexity: O(s)
*/

class Solution
{
    public:
        bool judgeSquareSum(int c)
        {
            unordered_set<long> squares;
            
            for(long a=0;a*a<=c;a++)
            {
                int aSquared=a * a;
                
                squares.insert(aSquared);
            }
            
            for(int aSquared : squares)
            {
                int bSquared=c - aSquared;
                
                if(squares.find(bSquared)!=end(squares))
                {
                    return true;
                }
            }
            
            return false;
        }
};