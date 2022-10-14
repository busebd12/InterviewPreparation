#include <algorithm>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of damage]
Space complexity: O(1)
*/

class Solution
{
    public:
        long long minimumHealth(vector<int> & damage, int armor)
        {
            long long result=numeric_limits<long long>::max();
            
            int n=damage.size();
            
            long long totalDamage=accumulate(begin(damage), end(damage), static_cast<long long>(0));
            
            for(int i=0;i<n;i++)
            {
                int protectedFrom=min(damage[i], armor);
                
                long long healthNeeded=static_cast<long long>((totalDamage - protectedFrom) + 1);
                
                result=min(result, healthNeeded);
            }
            
            return result;
        }
};