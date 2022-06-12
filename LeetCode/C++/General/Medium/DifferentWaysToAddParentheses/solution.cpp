#include <string>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/different-ways-to-add-parentheses/discuss/1191840/Java-or-Recursion-visualization
*/

class Solution
{
    public:
        vector<int> diffWaysToCompute(string expression)
        {
            vector<int> result;
            
            bool allNumbers=true;
            
            for(int i=0;i<expression.size();i++)
            {
                if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*')
                {
                    allNumbers=false;
                    
                    vector<int> leftSide=diffWaysToCompute(expression.substr(0, i));
                    
                    vector<int> rightSide=diffWaysToCompute(expression.substr(i + 1, string::npos));
                    
                    for(int num1 : leftSide)
                    {
                        for(int num2 : rightSide)
                        {
                            if(expression[i]=='+')
                            {
                                result.emplace_back(num1 + num2);
                            }
                            else if(expression[i]=='-')
                            {
                                result.emplace_back(num1 - num2);
                            }
                            else
                            {
                                result.emplace_back(num1 * num2);
                            }
                        }
                    }
                }
            }
            
            if(allNumbers==true)
            {
                result.emplace_back(stoi(expression));
            }
            
            return result;
        }
};