#include <string>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/break-a-palindrome/discuss/939823/Java-0-ms-Intuitive-Code-w-Explanation

Time complexity: O(n/2)
Space complexity: O(1)

*/
class Solution
{
    public:
        string breakPalindrome(string palindrome)
        {
            string result{};
            
            size_t n=palindrome.size();
            
            if(n==1)
            {
                return result;
            }
            
            for(size_t i=0;i<n/2;i++)
            {
                if(palindrome[i]!='a')
                {
                    palindrome[i]='a';
                    
                    return palindrome;
                }
            }
            
            palindrome[n - 1]='b';
            
            return palindrome;
        }
};