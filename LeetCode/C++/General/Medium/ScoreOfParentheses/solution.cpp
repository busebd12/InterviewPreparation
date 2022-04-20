#include <deque>
#include <string>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/score-of-parentheses/discuss/1856520/Java-Easy-to-understand-or-Intuition-and-solution-or-O(n)-greater-O(1)

Time complexity: O(n) [where n is the length s]
Space complexity: O(n)
*/

class Solution
{
    public:
        int scoreOfParentheses(string s)
        {
            int result=0;
            
            deque<int> stack;
            
            for(auto & character : s)
            {
                if(character=='(')
                {
                    stack.emplace_back(0);
                }
                //Current character is a )
                else
                {
                    if(!stack.empty())
                    {
                        //Previous character was a (
                        if(stack.back()==0)
                        {
                            stack.pop_back();
                            
                            stack.emplace_back(1);
                        }
                        //This closing ) is the closing ) for the case like (A)
                        else
                        {
                            int sum=0;
                            
                            //Sum up the score of the parenthesis string inside the ()
                            while(!stack.empty() && stack.back()!=0)
                            {
                                sum+=stack.back();
                                
                                stack.pop_back();
                            }
                            
                            //Remove the opening (
                            stack.pop_back();
                            
                            //Multiply the sum by two to get the score
                            sum*=2;
                            
                            stack.emplace_back(sum);
                        }
                    }
                }
            }
            
            while(!stack.empty())
            {
                result+=stack.back();
                
                stack.pop_back();
            }
            
            return result;
        }
};