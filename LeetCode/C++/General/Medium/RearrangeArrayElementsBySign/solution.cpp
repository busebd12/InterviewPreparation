#include <deque>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of nums]
Space complexity: O(n)
*/

class Solution
{
    public:
        vector<int> rearrangeArray(vector<int> & nums)
        {
            vector<int> result;

            deque<int> positives;

            for(int number : nums)
            {
                if(number > 0)
                {
                    positives.push_back(number);
                }
            }

            deque<int> negatives;

            for(int number : nums)
            {
                if(number < 0)
                {
                    negatives.push_back(number);
                }
            }

            while(!positives.empty() and !negatives.empty())
            {
                int positive=positives.front();

                positives.pop_front();

                result.push_back(positive);

                int negative=negatives.front();

                negatives.pop_front();

                result.push_back(negative);
            }

            return result;
        }
};