#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
    public:
        string maximumOddBinaryNumber(string s)
        {
            string result="";

            int n=s.length();

            int ones=count(s.begin(), s.end(), '1');

            vector<char> digits(n, '0');

            digits[n - 1]='1';

            ones-=1;

            for(int index=0;index<ones;index++)
            {
                digits[index]='1';
            }

            for(int index=0;index<n;index++)
            {
                result.push_back(digits[index]);
            }

            return result;
        }
};