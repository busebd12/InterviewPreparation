#include <string>
#include <vector>

/*
Solution: inspired by this post --> https://leetcode.com/problems/add-bold-tag-in-string/discuss/104248/Java-Solution-boolean-array

Time complexity:  O((w * l) + n) [where w is the length of words, l is the average length of a word, and n is the length of s]
Space complexity: O(n)
*/

class Solution
{
    public:
        string addBoldTag(string s, vector<string> & words)
        {
            int n=s.size();
            
            vector<bool> bold(n, false);
            
            for(string & word : words) //O(w)
            {
                auto index=s.find(word); //O(l)

                while(index!=string::npos)
                {   
                    int back=index;
                    
                    int front=back + word.size() - 1;
                    
                    for(int i=back;i<=front;i++)
                    {
                        bold[i]=true;
                    }
                    
                    index=s.find(word, index + 1);
                }
            }
            
            string result{};
            
            for(int i=0;i<n;) //O(n)
            {
                int j=-1;
                
                if(bold[i]==true)
                {
                    result.append("<b>");
                    
                    j=i;
                    
                    while(j < n && bold[j]==true)
                    {
                        result.push_back(s[j]);
                        
                        j++;
                    }
                    
                    result.append("</b>");
                }
                else
                {
                    j=i;
                    
                    while(j < n && bold[j]==false)
                    {
                        result.push_back(s[j]);
                        
                        j++;
                    }
                }
                
                i=j;
            }
            
            return result;
        }
};