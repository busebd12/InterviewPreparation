#include <string>
#include <unordered_map>
using namespace std;

/*
Time complexity: O(n^3 + m^3) [where n is the length of s and m is the length of t]
Space complexity: O(S) [where S is the total number of substrings of s]
*/

class Solution
{
    public:
        int countSubstrings(string s, string t)
        {
            int result=0;
            
            unordered_map<string, int> hashmap;
            
            int n=s.size();
            
            int m=t.size();
            
            for(int i=0;i<m;i++)
            {
                for(int j=i;j<=m;j++)
                {
                    string substring=t.substr(i, j - i);
                    
                    if(hashmap.find(substring)==end(hashmap))
                    {
                        hashmap.emplace(substring, 0);
                    }
                    
                    hashmap[substring]+=1;
                }
            }
            
            for(int i=0;i<n;i++)
            {
                for(int j=i;j<=n;j++)
                {
                    string substring=s.substr(i, j - i);
                    
                    for(int k=0;k<substring.size();k++)
                    {
                        char current=substring[k];
                        
                        for(char replacement='a';replacement<='z';replacement++)
                        {
                            if(replacement!=current)
                            {
                                substring[k]=replacement;
                                
                                if(hashmap.find(substring)!=end(hashmap))
                                {
                                    result+=hashmap[substring];
                                }
                            }
                        }
                        
                        substring[k]=current;
                    }
                }
            }
            
            return result;
        }
};