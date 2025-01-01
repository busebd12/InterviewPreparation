#include <deque>
#include <string>
using namespace std;

/*
Solution: based on these resources

1) Converting infix expression to postfix expression
    a) https://www.tutorialspoint.com/Convert-Infix-to-Postfix-Expression#
    b) https://www.youtube.com/watch?v=YHSj87pgjF8

2) Building expression tree from postfix expression: https://stackoverflow.com/questions/423898/postfix-notation-to-expression-tree

Time complexity: O(n) [where n=length of s]
Space complexity: O(n)
*/

class Solution
{
    public:
        Node* expTree(string s)
        {   
            string postfix=getPostfixExpression(s);

            deque<Node*> stack;

            for(char character : postfix)
            {
                if(isOperator(character)==true)
                {
                    Node* rightChild=stack.back();

                    stack.pop_back();

                    Node* leftChild=stack.back();

                    stack.pop_back();

                    stack.emplace_back(new Node(character, leftChild, rightChild));
                }
                else
                {
                    stack.emplace_back(new Node(character));
                }
            }

            return stack.back();
        }

        string getPostfixExpression(string & infix)
        {
            string postfix="";

            deque<char> stack;

            for(char character : infix)
            {   
                if(isOperator(character)==false)
                {
                    postfix.push_back(character);
                }
                else
                {
                    if(character=='(')
                    {
                        stack.push_back(character);
                    }
                    else if(character=='^')
                    {
                        stack.push_back(character);
                    }
                    else if(character==')')
                    {
                        while(!stack.empty() and stack.back()!='(')
                        {
                            postfix.push_back(stack.back());

                            stack.pop_back();
                        }

                        if(!stack.empty())
                        {
                            stack.pop_back();
                        }
                    }
                    else 
                    {
                        if(!stack.empty() and (getPrecedence(character) > getPrecedence(stack.back())))
                        {
                            stack.push_back(character);
                        }
                        else
                        {
                            while(!stack.empty() and getPrecedence(character) <= getPrecedence(stack.back()))
                            {
                                postfix.push_back(stack.back());

                                stack.pop_back();
                            }

                            stack.push_back(character);
                        }
                    }
                }
            }

            while(!stack.empty())
            {
                postfix.push_back(stack.back());

                stack.pop_back();
            }

            return postfix;
        }

        bool isOperator(char character)
        {
            return character=='+' or character=='-' or character=='*' or character=='/' or character=='^' or character=='(' or character==')';
        }

        int getPrecedence(char op)
        {
            if(op=='+' or op=='-')
            {
                return 1;
            }
            else if(op=='*' or op=='/')
            {
                return 2;
            }
            else if(op=='^')
            {
                return 3;
            }
            else
            {
                return 0;
            }
        }
};