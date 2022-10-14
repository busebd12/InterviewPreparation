#include <string>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/decode-the-slanted-ciphertext/discuss/1581290/C%2B%2B-Observation-or-beginner-Level-or

Time complexity: O(columns * n)
Space complexity: O(1)
*/

class Solution
{
    public:
        string decodeCiphertext(string encodedText, int rows)
        {
            string result="";
            
            int n=encodedText.size();
            
            int columns=n / rows;
            
            for(int column=0;column<columns;column++)
            {
                for(int index=column;index<n;index+=(columns + 1))
                {
                    result.push_back(encodedText[index]);
                }
            }
            
            while(isspace(result.back()))
            {
                result.pop_back();
            }
            
            return result;
        }
};