#include <unordered_map>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of nums]
Space complexity: O(u) [where u is the number of unique values in nums]
*/

class Solution
{
    private:
        unordered_map<int, int> frequencies;
    
    public:
        int singleNumber(vector<int> & nums)
        {
            int result=0;
            
            for(int number : nums)
            {
                frequencies[number]+=1;
            }
            
            for(auto & [number, frequency] : frequencies)
            {
                if(frequency==1)
                {
                    result=number;
                
                    break;
                }
            }
            
            return result;
        }
};