#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/*
 * Solutions:
 *
 * 1. We use backtracking to form all the possible combinations of letters.
 * We make use of a hashtable (unordered_map<char, string>) to map each digit
 * to the appropriate string.
 *
 * Time complexity: O(4^n) [where n is the length of the longest string associated with a digit]
 * Space complexity: O(4^n)
 *
 * 2. Same logic as the first solution, but we use a vector<string> instead of unordered_map<char, string> for our hashtable.
 *
 * Time complexity: O(4^n) [where n is the length of the longest string associated with a digit]
 * Space complexity: O(4^n)
 */

void backtracking(const std::vector<std::string> & strings, std::vector<std::string> & result, std::string combination, const size_t & length, int i)
{
    if(combination.size()==length)
    {
        result.push_back(combination);
    }

    if(i > strings.size()-1)
    {
        return;
    }

    for(auto j=0;j<strings[i].size();++j)
    {
        combination+=strings[i][j];

        backtracking(strings, result, combination, length, i+1);

        combination.pop_back();
    }
}

std::vector<std::string> letterCombinations(std::string digits)
{
    std::vector<std::string> result;

    if(digits.empty())
    {
        return result;
    }

    const size_t length=digits.size();

    std::unordered_map<char, std::string> hashtable;

    hashtable['1']="";

    hashtable['2']="abc";

    hashtable['3']="def";

    hashtable['4']="ghi";

    hashtable['5']="jkl";

    hashtable['6']="mno";

    hashtable['7']="pqrs";

    hashtable['8']="tuv";

    hashtable['9']="wxyz";

    std::vector<std::string> strings;

    for(const auto & digit : digits)
    {
        strings.emplace_back(hashtable[digit]);
    }

    int i=0;

    std::string combination{};

    backtracking(strings, result, combination, length, i);

    return result;
}

void backtracking(const std::vector<std::string> & strings, std::vector<std::string> & result, std::string combination, const size_t & length, int i)
{
    if(combination.size()==length)
    {
        result.push_back(combination);
    }

    if(i > strings.size()-1)
    {
        return;
    }

    for(auto j=0;j<strings[i].size();++j)
    {
        combination+=strings[i][j];

        backtracking(strings, result, combination, length, i+1);

        combination.pop_back();
    }
}

std::vector<std::string> letterCombinations(std::string digits)
{
    std::vector<std::string> result;

    if(digits.empty())
    {
        return result;
    }

    const size_t length=digits.size();

    std::vector<std::string> hashtable(10, "");

    hashtable[2]="abc";

    hashtable[3]="def";

    hashtable[4]="ghi";

    hashtable[5]="jkl";

    hashtable[6]="mno";

    hashtable[7]="pqrs";

    hashtable[8]="tuv";

    hashtable[9]="wxyz";

    std::vector<std::string> strings;

    for(const auto & digit : digits)
    {
        strings.emplace_back(hashtable[digit-'0']);
    }

    int i=0;

    std::string combination{};

    backtracking(strings, result, combination, length, i);

    return result;
}