#include <iostream>
#include <vector>
#include <string>
using namespace std;

void getCombinations(string combination, string digits, const size_t digitsSize, int offset, const vector<string> & keys, vector<string> & answer)
{
    if(offset >= digitsSize)
    {
        answer.emplace_back(combination);

        return;
    }

    string letters=keys[digits[offset]-'0'];

    const size_t lettersSize=letters.size();

    for(int index=0;index<lettersSize;++index)
    {
        getCombinations(combination + letters[index], digits, digitsSize, offset+1, keys, answer);
    }
}

vector<string> letterCombinations(string digits)
{   
    vector<string> answer;
    
    if(digits.empty())
    {
        return answer;
    }

    vector<string> keys={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    const size_t digitsSize=digits.size();

    int offset=0;

    string combination="";

    getCombinations(combination, digits, digitsSize, offset, keys, answer);

    return answer;
}