#include <cmath>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

/*
Solution: inspired by these resources

1) https://www.youtube.com/watch?v=NejzI9DxwjM
2) https://leetcode.com/problems/cracking-the-safe/solutions/708740/dfs-with-explanation-clean-code/

Time Complexity: O(|V| + |E|) [|V|=the number of nodes=k^n and |E|=k * k^n (every node has k neighbors)]
Space complexity : height of recursion tree --> O(|V|)=k^n
*/

class Solution
{
    public:
        string crackSafe(int n, int k)
        {
            string result="";

            int totalPossiblePasswords=pow(k, n);

            //Start our minimum sequence with all zeros
            for(int i=0;i<n;i++)
            {
                result.push_back('0');
            }

            string current=result;

            unordered_set<string> seen;

            seen.insert(current);

            helper(seen, current, result, n, k, totalPossiblePasswords);

            return result;
        }

        bool helper(unordered_set<string> & seen, string & current, string & result, int n, int k, int totalPossiblePasswords)
        {
            //If we have seen all possible passwords, then we have found a minimum sequence that will unlock the safe   
            if(seen.size()==totalPossiblePasswords)
            {
                return true;
            }

            //Start the substring at index 1 since we are only keeping n characters in the sequence
            string suffix=current.substr(1, string::npos);

            //Iterate through all possible k digits
            for(char digit='0';digit<'0' + k;digit++)
            {
                //Next possible unlock sequence
                string next=suffix;

                //Add digit to next
                next.push_back(digit);

                //If we haven't seen next before
                //We need this check in order to prevent us from going down a recursive path that doesn't lead to an answer
                if(seen.find(next)==seen.end())
                {
                    //Mark next as seen
                    seen.insert(next);

                    //Add the digit to the minimum sequence
                    result.push_back(digit);

                    //Recurse
                    if(helper(seen, next, result, n, k, totalPossiblePasswords)==true)
                    {
                        return true;
                    }

                    //Remove character from minimum sequence
                    result.pop_back();

                    //Mark next as unseen
                    seen.erase(next);
                }
            }

            //If we reach here, we didn't get a true at this level of the recursion, so return false
            return false;
        }
};