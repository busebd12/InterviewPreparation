#include <deque>
#include <string>
#include <utility>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n) [where n is the length of s]
Space complexity: O(n)
*/

class Solution
{
    public:
        int calculate(string s)
        {
            int result=0;

            int n=s.size();

            //Stack used to store the state of the evaluated expression so far when we encounter a '('
            //Each pair is {value of the evaluated expression so far, 1 or -1 [1==positive, -1==negative]}
            deque<pair<int, int>> stack;

            //Keeps track of positive or negative
            //1==positive and -1==negative
            int sign=1;

            for(int i=0;i<n;i++)
            {
                if(s[i]=='+')
                {   
                    sign=1;
                }
                else if(s[i]=='-')
                {   
                    sign=-1;
                }
                else if(isdigit(s[i]))
                {   
                    int total=s[i] - '0';

                    //Keep adding digits to our total until we reach a non-digit character
                    while(i + 1 < n and isdigit(s[i + 1]))
                    {
                        total=(total * 10) + (s[i + 1] - '0');

                        i+=1;
                    }

                    //Make sure to update our result with the total we just calculated
                    result+=(total * sign);
                }
                else if(s[i]=='(')
                {
                    //IMPORTANT: make sure to push the "state" on to the stack
                    //The state represents the value the part of the expression we have evaluated up to
                    //this point and the sign let's us know if the value should be positive or negative
                    stack.emplace_back(result, sign);

                    //Reset the result and sign since we are starting a new calculation that is independent of the one we just finished
                    result=0;

                    sign=1;
                }
                else if(s[i]==')')
                {
                    //Remove the state we just pushed onto the stack so we can either
                    //add it to or subtract it from the total we calculate from inside the parenthesis
                    auto [amount, op]=stack.back();

                    stack.pop_back();

                    //Update the result accordingly
                    result=(result * op) + amount;
                }
            }

            return result;
        }
};