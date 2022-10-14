#include <string>
using namespace std;

/*
Time complexity: O(n * m) [where n is the length of a and m is the length of b]
Space complexity: O(n + m)
*/

class Solution
{
    public:
        int repeatedStringMatch(string a, string b)
        {
            int result=0;
            
            string s="";
            
            //Keep appending a to s until s.size() >= b.size() since s needs to be at least as long as b to contain b as a substring
            while(s.size() < b.size())
            {
                s.append(a);
                
                result+=1;
            }
            
            //Check to see if b is a substring of s
            if(s.find(b)!=string::npos)
            {
                return result;
            }
            
            //Append a to s one more time just in-case only a part of b is in s at this point
            s.append(a);
            
            result+=1;
            
            //Check one last if b is a substring of s
            if(s.find(b)!=string::npos)
            {
                return result;
            }
            
            return -1;
        }
};