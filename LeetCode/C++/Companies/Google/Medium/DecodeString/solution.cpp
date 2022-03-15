#include <algorithm>
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
using namespace std;

class Solution
{
    public:
        string decodeString(string s)
        {
            string result{};
    
            deque<char> stack;

            int n=s.size();

            for(int i=0;i<n;i++)
            {
                if(s[i]==']')
                {
                    string betweenBrackets{};

                    string part{};

                    //Store the string between the brackets
                    while(!stack.empty() && stack.back()!='[')
                    {
                        betweenBrackets+=stack.back();

                        stack.pop_back();
                    }

                    //pop the opening [ off the stack
                    if(!stack.empty())
                    {
                        stack.pop_back();
                    }

                    //number of times to add the string between the brackets to the part string
                    string kString{};

                    //pop the number off the stack; since the number could be double digits, use loop
                    while(!stack.empty() && isdigit(stack.back()))
                    {
                        kString+=stack.back();

                        stack.pop_back();
                    }

                    //reverse the string between the brackets and number so that they have the correct values
                    reverse(betweenBrackets.begin(), betweenBrackets.end());

                    reverse(kString.begin(), kString.end());

                    int k=stoi(kString);

                    //add string between the brackets to part string k times
                    for(int count=0;count<k;count++)
                    {
                        part+=betweenBrackets;
                    }

                    //add the part string back onto the stack since it can be inside another set of []
                    for(int index=0;index<part.size();index++)
                    {
                        stack.emplace_back(part[index]);
                    }
                }
                else
                {
                    stack.push_back(s[i]);
                }
            }
            
            //build the answer by iterating through the stack and adding each character to result
            while(!stack.empty())
            {
                result+=stack.front();

                stack.pop_front();
            }

            return result;
        }
};