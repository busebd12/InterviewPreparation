/*
Time complexity: O(n)
Space complexity: O(1)
*/

class Solution
{
    public:
        int concatenatedBinary(int n)
        {
            int result=0;
            
            long decimal=0;
            
            const int MOD=1e9 + 7;
            
            for(int number=1;number<=n;number++)
            {
                int x=number;
                
                int numberOfBits=0;
                
                while(x > 0)
                {
                    numberOfBits+=1;
                    
                    x=x >> 1;
                }
                
                decimal=((decimal << numberOfBits) + number) % MOD;
            }
            
            result=static_cast<int>(decimal);
            
            return result;
        }
};