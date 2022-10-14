#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
    public:
        bool reorderedPowerOf2(int n)
        {
            unordered_set<string> powerOfTwoStrings;
            
            for(int exponent=0;exponent<31;exponent++)
            {
                int powerOfTwo=pow(2, exponent);
                
                string powerOfTwoString=to_string(powerOfTwo);
                
                sort(begin(powerOfTwoString), end(powerOfTwoString));
                
                powerOfTwoStrings.insert(powerOfTwoString);
            }
            
            string numberString=to_string(n);
            
            sort(begin(numberString), end(numberString));
            
            return powerOfTwoStrings.find(numberString)!=end(powerOfTwoStrings);
        }
};