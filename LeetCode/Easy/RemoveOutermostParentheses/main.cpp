#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

/*
 * Approach: we divide up the input string into chunks with equal amounts of opening and closing parentheses.
 * Then, for each chunk, we have two cases. Either, the chunk is a valid primitive string or it is not.
 * In either case, we remove the outter most parentheses and then add the remaing string to our result string.
 * Return our result string.
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(n) + O(number of valid parentheses strings)
 */

string removeOuterParentheses(string s)
{
    if(s.empty())
    {
        return s;
    }

    string result{};

    string decomposition{};

    int n=int(s.size());

    int openingParentheses=0;

    int closingParentheses=0;

    unordered_set<string> valid={"()", "(())", "()()", "()(())", "(())()"};

    for(int i=0;i<n;++i)
    {
        if(s[i]=='(')
        {
            openingParentheses++;
        }
        else
        {
            closingParentheses++;
        }

        decomposition+=s[i];

        if((openingParentheses-closingParentheses)==0)
        {
            if(valid.count(decomposition))
            {
                if(openingParentheses >= 1 && closingParentheses >= 1)
                {
                    decomposition.pop_back();

                    decomposition.erase(0, 1);
                }
            }
            else
            {
                decomposition.erase(0, 1);

                decomposition.pop_back();
            }

            result+=decomposition;

            openingParentheses=0;

            closingParentheses=0;

            decomposition.clear();
        }
    }

    return result;
}