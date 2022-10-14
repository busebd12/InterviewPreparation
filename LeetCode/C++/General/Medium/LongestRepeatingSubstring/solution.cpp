#include <algorithm>
#include <string>
#include <string_view>
#include <unordered_map>
using namespace std;

/*
Time complexity: O(n^2) [where n is the length of s]
Space complexity: O(u) [where u is the number of unique substrings]
*/

class Solution
{
    public:
        int longestRepeatingSubstring(string s)
        {
            int result=0;
            
            int n=s.size();
            
            string_view view=s;
            
            unordered_map<string_view, int> substringFrequencies;
            
            for(int i=0;i<n;i++)
            {
                for(int j=i;j<=n;j++)
                {
                    string_view substring=view.substr(i, j - i);
                    
                    if(substringFrequencies.find(substring)==end(substringFrequencies))
                    {
                        substringFrequencies.emplace(substring, 0);
                    }
                    
                    substringFrequencies[substring]+=1;
                }
            }
            
            for(auto & [substring, frequency] : substringFrequencies)
            {
                if(frequency > 1)
                {
                    result=max(result, int(substring.size()));
                }
            }
            
            return result;
        }
};