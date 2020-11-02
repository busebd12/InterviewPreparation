#include <iostream>
#include <string>
#include <vector>

/*
 * Solution: for the string of parentheses to be balanced. There needs to be a total of 2n parenthesis, open and closed.
 * So, we keep track of how many open and closed parentheses we are adding to our string and once both open and closed
 * equal n, we know we have a valid string of parentheses. We only add an opening parenthesis when the number of open
 * parentheses is less than n. We only add a closed parenthesis when the number of closed parentheses is less than the
 * number of open parentheses. This way we make sure that we have a valid number of open and closed parentheses at all
 * times.
 *
 * Time complexity: O(n * 2^n)
 * Space complexity: O(n * 2^n)
 */

void backtracking(std::vector<std::string> & result, std::string combination, const int & n, int open, int closed)
{
    if(open==n && closed==n)
    {
        result.push_back(combination);
    }

    if(open < n)
    {
        combination+='(';

        backtracking(result, combination, n, open+=1, closed);

        combination.pop_back();

        open-=1;
    }

    if(closed < open)
    {
        combination+=')';

        backtracking(result, combination, n, open, closed+=1);

        combination.pop_back();

        closed-=1;
    }
}

std::vector<std::string> generateParenthesis(int n)
{
    std::vector<std::string> result;

    if(n==0)
    {
        return result;
    }

    int open=0;

    int closed=0;

    std::string combination{};

    backtracking(result, combination, n, open, closed);

    return result;
}