#include <string>
using namespace std;

/*
Time complexity: O(n * m) [where n is the length of haystack and m is the length of needle]
Space complexity: O(1)
*/

class Solution
{
    public:
        int strStr(string haystack, string needle)
        {
            int result=-1;
            
            auto index=haystack.find(needle);
            
            if(index!=string::npos)
            {
                result=index;
            }
            
            return result;
        }
};