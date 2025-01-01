#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

class Solution
{
    public:
        int largestAltitude(vector<int> & gain)
        {
            int result=numeric_limits<int>::min();

            vector<int> gains;

            gains.emplace_back(0);

            for(int number : gain)
            {
                gains.push_back(gains.back() + number);
            }

            result=*(max_element(gains.begin(), gains.end()));

            return result;
        }
};