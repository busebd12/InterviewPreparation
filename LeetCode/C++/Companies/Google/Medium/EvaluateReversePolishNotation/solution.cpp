#include <algorithm>
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
using namespace std;

/*
Time complexity: O(t) [where t is the number of input tokens]
Space complexity: (n) [where n is the number of numeric tokens]
*/

int evalRPN(vector<string> & tokens)
{
    int result=0;
    
    //stack used to hold integer tokens and result of operations
    deque<string> stack;
    
    int t=tokens.size();
    
    //iterate through the tokens
    for(int index=0;index<t;index++)
    {
        string token=tokens[index];
        
        //if the token is a number - positive or negative
        if(isdigit(token[0]) || (token[0]=='-' && token.size() > 1))
        {
            stack.emplace_back(token);
        }
        //else, token is an operator
        else
        {
            //pop the first two numbers off the stack that will be used in the calculation
            int secondNumber=stoi(stack.back());
            
            stack.pop_back();
            
            int firstNumber=stoi(stack.back());
            
            stack.pop_back();
            
            //do the appropriate operation based on the operator
            if(token=="+")
            {
                result=firstNumber + secondNumber;
            }
            else if(token=="-")
            {
                result=firstNumber - secondNumber;
            }
            else if(token=="*")
            {
                result=firstNumber * secondNumber;
            }
            else
            {
                result=firstNumber / secondNumber;
            }
            
            //add operation result back onto the stack since it will be used in future operations
            stack.emplace_back(to_string(result));
        }
    }
    
    //edge case: just a single digit, no operators
    if(!stack.empty())
    {
        result=stoi(stack.back());
        
        stack.pop_back();
    }

    return result;
}