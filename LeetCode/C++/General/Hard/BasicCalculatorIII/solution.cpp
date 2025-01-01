#include <deque>
#include <string>
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

            //Stores results of intermediate calculations as we iterate through the string
            deque<int> numberStack;

            //Stores the different operators +, -, *, /, and ( that we find as we iterate through the string
            deque<char> operatorStack;

            for(int i=0;i<n;i++)
            {
                //If the current character is a digit
                if(isdigit(s[i]))
                {
                    //Sum up all the digits until we reach the end of the string or a non-digit character
                    int total=s[i] - '0';

                    while(i + 1 < n and isdigit(s[i + 1]))
                    {
                        total=(total * 10) + (s[i + 1] - '0');

                        i+=1;
                    }

                    //Add the total to the numberStack
                    numberStack.push_back(total);
                }
                //Else if the character is an operator
                else if(s[i]=='*' or s[i]=='/' or s[i]=='+' or s[i]=='-')
                {
                    //While the operator stack contains an operator or operators to the left of the current one in the string that has equal
                    //or higher precedence according to the rules of PEMDAS and is not a '('
                    while(!operatorStack.empty() and getPrecedence(operatorStack.back()) >= getPrecedence(s[i]) and operatorStack.back()!='(')
                    {
                        int first=numberStack.back();

                        numberStack.pop_back();

                        int second=numberStack.back();

                        numberStack.pop_back();

                        char op=operatorStack.back();

                        operatorStack.pop_back();

                        //Then, do the calculation involving that operator
                        int calculationResult=evaluate(second, first, op);

                        //Add the calculation result to the number stack
                        numberStack.push_back(calculationResult);
                    }

                    //Add the operator to the operator stack
                    operatorStack.push_back(s[i]);
                }
                else if(s[i]=='(')
                {
                    operatorStack.push_back(s[i]);
                }
                //If the character is an ')'
                else if(s[i]==')')
                {
                    //Perform all operations found within the set of ()
                    while(operatorStack.back()!='(')
                    {
                        int first=numberStack.back();

                        numberStack.pop_back();

                        int second=numberStack.back();

                        numberStack.pop_back();

                        char op=operatorStack.back();

                        operatorStack.pop_back();

                        int calculationResult=evaluate(second, first, op);

                        //Add the operation result to the numberStack
                        numberStack.push_back(calculationResult);
                    }

                    operatorStack.pop_back();
                }
            }

            //Once we have done all the preliminary operations, we just need to evaluate the string one last time to get our answer
            while(!operatorStack.empty())
            {
                int first=numberStack.back();

                numberStack.pop_back();

                int second=numberStack.back();

                numberStack.pop_back();

                char op=operatorStack.back();

                operatorStack.pop_back();

                int calculationResult=evaluate(second, first, op);

                numberStack.push_back(calculationResult);
            }

            result=numberStack.back();

            return result;
        }

        //Returns the integer precedence of the different operators: +, -, *, /, and (
        int getPrecedence(char op)
        {
            int precedence=-1;

            if(op=='(' or op==')')
            {
                precedence=2;
            }
            else if(op=='*' or op=='/')
            {
                precedence=1;
            }
            else if(op=='+' or op=='-')
            {
                precedence=0;
            }

            return precedence;
        }

        //Evaluates an expression of the following forms: a + b, a - b, a * b, and a / c
        int evaluate(int second, int first, char op)
        {
            int operationResult=-1;

            if(op=='*')
            {
                operationResult=second * first;
            }
            else if(op=='/')
            {
                operationResult=second / first;
            }
            else if(op=='+')
            {
                operationResult=second + first;
            }
            else if(op=='-')
            {
                operationResult=second - first;
            }

            return operationResult;
        }
};