#include <deque>
#include <string>
#include <vector>
using namespace std;

class Solution
{
    public:
        int clumsy(int n)
        {
            int result=0;

            deque<string> expression;

            int flag=0;

            for(int number=n;number>0;number--)
            {
                expression.emplace_back(to_string(number));

                if(number > 1)
                {
                    switch(flag)
                    {
                        case 0:
                            expression.emplace_back("*");
                            break;
                        case 1:
                            expression.emplace_back("/");
                            break;
                        case 2:
                            expression.emplace_back("+");
                            break;
                        case 3:
                            expression.emplace_back("-");
                            break;
                        default:
                            break;
                    }

                    flag=(flag + 1) % 4;
                }
            }

            string op="*";

            evaluateMultiplicationOrDivision(expression, op);

            op="/";

            evaluateMultiplicationOrDivision(expression, op);

            evaluateAdditionOrSubtraction(expression);

            result=stoi(expression.front());

            return result;
        }

        void evaluateMultiplicationOrDivision(deque<string> & expression, string & op)
        {
            deque<string> evaluated;
    
            bool doOperation=false;
            
            while(!expression.empty())
            {   
                if(!isdigit(expression.front()[0]))
                {
                    if(expression.front()==op)
                    {   
                        doOperation=true;
                        
                        expression.pop_front();
                    }
                    else
                    {
                        evaluated.emplace_back(expression.front());
                        
                        expression.pop_front();
                    }
                }
                else
                {
                    if(doOperation==true)
                    {
                        int left=stoi(evaluated.back());
                        
                        evaluated.pop_back();
                        
                        int right=stoi(expression.front());
                        
                        expression.pop_front();
                        
                        int operationResult=0;
                        
                        if(op=="*")
                        {
                            operationResult=left * right;
                        }
                        else if(op=="/")
                        {
                            operationResult=left / right;
                        }

                        evaluated.emplace_back(to_string(operationResult));

                        doOperation=false;
                    }
                    else
                    {
                        evaluated.emplace_back(expression.front());
                        
                        expression.pop_front();
                    }
                }
            }
            
            while(!evaluated.empty())
            {
                expression.emplace_back(evaluated.front());
                
                evaluated.pop_front();
            }
        }

        void evaluateAdditionOrSubtraction(deque<string> & expression)
        {
            deque<string> evaluated;

            string op="$";
    
            bool doOperation=false;
            
            while(!expression.empty())
            {   
                if(!isdigit(expression.front()[0]))
                {
                    if(expression.front()=="+" or expression.front()=="-")
                    {
                        doOperation=true;

                        op=expression.front();
                        
                        expression.pop_front();
                    }
                    else
                    {
                        evaluated.emplace_back(expression.front());
                        
                        expression.pop_front();
                    }
                }
                else
                {
                    if(doOperation==true)
                    {
                        int left=stoi(evaluated.back());
                        
                        evaluated.pop_back();
                        
                        int right=stoi(expression.front());
                        
                        expression.pop_front();
                        
                        int operationResult=0;

                        if(op=="+")
                        {
                            operationResult=left + right;
                        }
                        else
                        {
                            operationResult=left - right;
                        }
                        
                        evaluated.emplace_back(to_string(operationResult));

                        doOperation=false;

                        op="$";
                    }
                    else
                    {   
                        evaluated.emplace_back(expression.front());
                        
                        expression.pop_front();
                    }
                }
            }
            
            while(!evaluated.empty())
            {
                expression.emplace_back(evaluated.front());
                
                evaluated.pop_front();
            }
        }
};

class Solution
{
    public:
        int clumsy(int n)
        {
            int result=0;

            deque<int> stack;

            vector<char> operators={'*', '/', '+', '-'};

            stack.push_back(n);

            n-=1;

            int index=0;

            while(n > 0)
            {
                int current=0;
                
                if(operators[index]=='*')
                {
                    current=stack.back();

                    stack.pop_back();

                    stack.emplace_back(current * n);
                }
                else if(operators[index]=='/')
                {
                    current=stack.back();

                    stack.pop_back();

                    stack.emplace_back(current / n);
                }
                else if(operators[index]=='+')
                {
                    current=stack.back();
                    
                    stack.emplace_back(n);
                }
                else
                {
                    stack.emplace_back(-1 * n);
                }

                n-=1;

                index=(index + 1) % 4;
            }

            while(!stack.empty())
            {
                result+=stack.back();

                stack.pop_back();
            }

            return result;
        }
};