#include <iostream>
#include <vector>
#include <string>
using namespace std;

void helper(vector<string> & result, string output, int open, int closed, int pairs)
{
    if(open==pairs && closed==pairs)
    {        
        result.emplace_back(output);
    }
    else
    {
        if(open < pairs)
        {
            helper(result, output + "(", open+1, closed, pairs);
        }

        if(closed < open)
        {
            helper(result, output + ")", open, closed+1, pairs);
        }
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> result;
    
    helper(result, "", 0, 0, n);

    return result;
}