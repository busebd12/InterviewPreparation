#include <string>
using namespace std;

/*
Time complexity: O(n + m) [where n is the length of word1 and m is the length of word2]
Space complexity: O(n + m)
*/

class Solution
{
    public:
        bool arrayStringsAreEqual(vector<string> & word1, vector<string> & word2)
        {
            string w1="";

            for(string word : word1)
            {
                w1.append(word);
            }

            string w2="";

            for(string word : word2)
            {
                w2.append(word);
            }

            return (w1==w2);
        }
};