#include <algorithm>
#include <iterator>
#include <random>
#include <vector>
using namespace std;

/*
Solution: see this page --> https://en.cppreference.com/w/cpp/algorithm/random_shuffle

Time complexity: O(n) [where n is the length of nums]
Space complexity: O(n)
*/

class Solution
{
    public:
        vector<int> original;
    
        vector<int> shuffled;
    
        Solution(vector<int> & nums)
        {
            original=nums;
            
            shuffled=nums;
        }

        vector<int> reset()
        {
            return original;
        }

        vector<int> shuffle()
        {
            random_device rd{};
    
            mt19937 engine(rd());
            
            std::shuffle(begin(shuffled), end(shuffled), engine);
            
            return shuffled;
        }
};