#include <string>
using namespace std;

/*
Solution: based on this resource --> https://www.codingninjas.com/codestudio/library/number-of-unique-good-subsequences

Time complexity: O(n) [where n=length of binary]
Space complexity: O(1)
*/

class Solution
{
    public:
        int numberOfUniqueGoodSubsequences(string binary)
        {
            int result=0;

            int n=binary.size();

            int endsWithOne=0;

            int endsWithZero=0;

            int singleZero=0;

            const int MOD=1e9 + 7;

            for(char digit : binary)
            {
                if(digit=='1')
                {
                    endsWithOne=endsWithOne + endsWithZero + 1;

                    endsWithOne=endsWithOne % MOD;
                }
                else
                {
                    endsWithZero=endsWithZero + endsWithOne;

                    endsWithZero=endsWithZero % MOD;

                    singleZero=1;
                }
            }

            result=(endsWithOne + endsWithZero + singleZero);

            result=result % MOD;

            return result;
        }
};