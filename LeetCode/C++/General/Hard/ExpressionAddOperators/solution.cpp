#include <string>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(4^n) [where n=length of num]
Space complexity: O(n) recursive stack space
*/

class Solution
{
    public:
        vector<string> addOperators(string num, int target)
        {
            vector<string> result;

            int n=num.size();

            int index=0;

            string path="";

            long previousNumber=0;

            long totalSoFar=0;

            helper(result, num, path, n, target, totalSoFar, previousNumber, index);

            return result;
        }

        void helper(vector<string> & result, string & num, const string & path, int n, int target, long totalSoFar, long previousNumber, int index)
        {
            if(index==n)
            {
                if(totalSoFar==target)
                {
                    result.push_back(path);
                }

                return;
            }

            string next="";

            long number=0;

            for(int i=index;i<n;i++)
            {   
                //Handle case of leading zero
                if(i > index and num[index]=='0')
                {
                    break;
                }

                next.push_back(num[i]);

                number=number * 10 + (num[i] - '0');

                //If index==0, then we are selecting the first number in our total, so no need for any operators (yet)
                if(index==0)
                {
                    helper(result, num, path + next, n, target, number, number, i + 1);
                }
                else
                {
                    //+ operator time
                    helper(result, num, path + "+" + next, n, target, totalSoFar + number, number, i + 1);

                    //- operator time
                    helper(result, num, path + "-" + next, n, target, totalSoFar - number, -number, i + 1);

                    //Time for the '*' operator
                    //Since * has higher precedence than + or -, we need to do a little trick
                    //If we have the expression 1 + 2, and we want to multiply it by 3, i.e. 1 + 2 * 3,
                    //we can accomplish this by re-writing the expression in the following manner:
                    //1 + 2 * 3 => 3 * 3 => 3 - 2 + (2 * 3) => 3 - 2 + 6 => 1 + 6 => 7
                    //1 + (2 * 3) => 1 + 6 => 7
                    helper(result, num, path + "*" + next, n, target, totalSoFar - previousNumber + (previousNumber * number), previousNumber * number, i + 1);
                }
            }
        }
};