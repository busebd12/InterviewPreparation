/*
Time complexity: O(n) [where n is the length of the string s]
Space complexity: O(1)
*/

class Solution
{
    public:
        int minSwaps(string s)
        {
            int result=0;
            
            size_t n=s.size();
            
            int open=0;
            
            int closed=0;
            
            for(size_t i=0;i<n;i++)
            {
                char c=s[i];
                
                if(c=='[')
                {
                    open+=1;
                }
                else
                {
                    closed+=1;
                }
                
                if(closed > open)
                {   
                    result+=1;
                    
                    open+=1;
                    
                    closed-=1;
                }
            }
            
            return result;
        }
};