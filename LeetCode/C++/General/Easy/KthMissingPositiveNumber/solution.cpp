#include <unordered_set>
#include <vector>
using namespace std;

/*
Solution 1

Submission status: accepted.

Time complexity: O(n + k)
Space complexity: O(n)
*/

class Solution
{
    public:
        int findKthPositive(vector<int> & arr, int k)
        {
            int result=0;

            unordered_set<int> hashset;

            for(int number : arr)
            {
                hashset.insert(number);
            }

            int limit=1000;

            int missing=0;

            for(int number=1;number<=limit or missing<k;number++)
            {
                if(hashset.find(number)==hashset.end())
                {
                    missing+=1;

                    result=number;
                }

                if(missing==k)
                {
                    break;
                }
            }

            return result;
        }
};

/*
Solution 2

Submission status: accepted.

Time complexity: O(n + k)
Space complexity: O(2000) => O(1)
*/

class Solution
{
    public:
        int findKthPositive(vector<int> & arr, int k)
        {
            int result=0;

            int limit=2000;

            vector<int> hashmap(limit + 1, false);

            for(int number : arr)
            {
                hashmap[number]=true;
            }

            int missing=0;

            for(int number=1;number<=limit or missing<k;number++)
            {
                if(hashmap[number]==false)
                {
                    missing+=1;

                    result=number;
                }

                if(missing==k)
                {
                    break;
                }
            }

            return result;
        }
};