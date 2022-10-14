#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/lexicographical-numbers/discuss/2286925/Python-O(N)-Time-and-O(1)-Extra-Space-Solution

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution
{
    public:
        vector<int> lexicalOrder(int n)
        {
            vector<int> result;
            
            int number=1;
            
            while(result.size() < n)
            {
                if(number <= n)
                {
                    result.push_back(number);
                    
                    if(number * 10 <= n)
                    {
                        number*=10;
                    }
                    else
                    {
                        number+=1;
                        
                        while((number % 10)==0)
                        {
                            number=number / 10;
                        }
                    }
                }
                else
                {
                    number=number / 10;
                    
                    number+=1;
                    
                    while((number % 10)==0)
                    {
                        number=number / 10;
                    }
                }
            }
            
            return result;
        }
};