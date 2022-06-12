#include <string>
#include <unordered_set>
using namespace std;

/*
Time complexity: O(n) [where n is the length of s and t]
Space complexity: O(n)
*/

class Solution
{
    public:
        int minSteps(string s, string t)
        {
            int result=0;
            
            unordered_multiset<char> tLetters(begin(t), end(t));
            
            for(char letter : s)
            {
                auto itr=tLetters.find(letter);
                
                if(itr!=end(tLetters))
                {
                    tLetters.erase(itr);
                }
            }
            
            result=tLetters.size();
            
            return result;
        }
};