#include <set>
using namespace std;

/*
Time complexity: O(n * log(n))
Space complexity: O(n)
*/

class Solution
{
    public:
        int nthUglyNumber(int n)
        {
            long result=0;

            set<long> numbers;

            long start=1;

            numbers.insert(start);

            for(int count=0;count<n;count++)
            {
                long smallest=*(numbers.begin());

                result=smallest;

                numbers.erase(numbers.begin());

                numbers.emplace(smallest * 2);

                numbers.emplace(smallest * 3);

                numbers.emplace(smallest * 5);
            }

            return (int)result;
        }
};