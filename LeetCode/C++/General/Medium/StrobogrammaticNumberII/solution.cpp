#include <deque>
#include <string>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/strobogrammatic-number-ii/discuss/733036/Clean-Java-BFS-using-Queue-similar-to-level-order-traversal

Time complexity: O(5^(n/2) * n)
Space complexity: O(n)
*/

class Solution
{
    public:
        vector<string> findStrobogrammatic(int n)
        {
            vector<string> result;
            
            if(n==0)
            {
                return result;
            }
            
            deque<string> queue;
            
            if((n % 2)==0)
            {
                queue.emplace_back("");
            }
            else
            {
                queue.emplace_back("0");
                
                queue.emplace_back("1");
                
                queue.emplace_back("8");
            }
            
            while(!queue.empty() && n > 1)
            {
                size_t qSize=queue.size();
                
                for(size_t count=0;count<qSize;count++)
                {
                    string middle=queue.front();
                    
                    queue.pop_front();
                    
                    //Since the case where n=3 and n=2 reduce to the base cases of n=1 and n=0 respectively
                    //We can't add 0 to the front and back of the empty string (the empty string is the starting point for n=2) since "00"
                    //is not a valid Strobogrammatic number
                    //We also can't sandwich two zeros around 1, 6, or 8 since 010, 060, and 080 are not valid Strobogrammatic numbers either
                    //So, we can only add a zero to the front and back of the string when n is greater than 3
                    if(n > 3)
                    {
                        queue.emplace_back('0' + middle + '0');
                    }
                    
                    queue.emplace_back('1' + middle + '1');
                    
                    queue.emplace_back('8' + middle + '8');
                    
                    queue.emplace_back('6' + middle + '9');
                    
                    queue.emplace_back('9' + middle + '6');
                }
                
                n-=2;
            }
            
            while(!queue.empty())
            {
                result.emplace_back(queue.front());
                
                queue.pop_front();
            }
            
            return result;
        }
};