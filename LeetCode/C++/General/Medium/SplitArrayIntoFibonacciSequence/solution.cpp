#include <limits>
#include <string>
#include <vector>
using namespace std;

/*
Solution: backtracking + properties of fibonacci sequences.

Time complexity: O(n) [where n is the length of num]
Space complexity: O(n)
*/

class Solution
{
    public:
        vector<int> splitIntoFibonacci(string num)
        {
            vector<int> result;

            int n=num.size();

            vector<int> fibonacciSequence;

            int start=0;

            helper(num, result, fibonacciSequence, n, start);

            return result;
        }

        void helper(string & num, vector<int> & result, vector<int> & fibonacciSequence, int n, int start)
        {
            if(start==n and fibonacciSequence.size() > 2)
            {
                result=fibonacciSequence;

                return;
            }

            for(int stop=start;stop<n;stop++)
            {
                int substringLength=(stop - start) + 1;
                
                long long next=stoll(num.substr(start, substringLength));

                if(next > numeric_limits<int>::max())
                {
                    return;
                }

                if(stop > start and num[start]=='0')
                {
                    return;
                }

                if(fibonacciSequence.size() < 2 or ((long long)fibonacciSequence.back() + (long long)fibonacciSequence[fibonacciSequence.size() - 2])==next)
                {
                    fibonacciSequence.push_back((int)next);

                    helper(num, result, fibonacciSequence, n, stop + 1);

                    fibonacciSequence.pop_back();
                }
            }
        }
};