#include <string>
#include <vector>
using namespace std;

/*
Time complexity: O(2^n)
Space complexity: O(n)
*/

class Solution
{
    public:
        vector<string> generateAbbreviations(string word)
        {
            vector<string> result;

            int n=word.size();

            string abbreviation="";

            int length=0;

            int index=0;

            helper(result, word, abbreviation, n, length, index);

            return result;
        }

        void helper(vector<string> & result, string & word, string abbreviation, int n, int length, int index)
        {
            if(index >= n)
            {
                if(length > 0)
                {
                    abbreviation.append(to_string(length));
                }

                result.push_back(abbreviation);

                return;
            }

            //Choice 1: increase length of abbreviation
            helper(result, word, abbreviation, n, length + 1, index + 1);

            //Choice 2: don't abbreviate and take the current letter
            //Also, because we are taking the character, the length of the previous abbreviation has to be reset to
            //zero since we can't have two numbers next to each other in the abbreviation string
            helper(result, word, abbreviation + (length > 0 ? to_string(length) : "") + word[index], n, 0, index + 1);
        }
};