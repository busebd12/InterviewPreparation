#include <algorithm>
#include <vector>
using namespace std;

/*
Time complexity: O(k^n) [where n is the length of cookies]
Space complexity: O(k + n)
*/

class Solution
{
    public:
        int distributeCookies(vector<int> & cookies, int k)
        {
            int result=numeric_limits<int>::max();

            int n=cookies.size();

            int totalCookies=accumulate(cookies.begin(), cookies.end(), 0);

            int index=0;

            vector<int> buckets(k, 0);

            helper(cookies, buckets, n, k, totalCookies, result, index);

            return result;
        }

        void helper(vector<int> & cookies, vector<int> & buckets, int n, int k, int totalCookies, int & result, int index)
        {
            if(index==n and totalCookies==0)
            {
                int unfairness=numeric_limits<int>::min();

                bool emptyBuckets=false;

                for(int amount : buckets)
                {
                    if(amount > 0)
                    {
                        unfairness=max(unfairness, amount);
                    }
                    else
                    {
                        emptyBuckets=true;
                    }   
                }

                if(emptyBuckets==false)
                {
                    result=min(result, unfairness);
                }
            }

            if(index < n)
            {
                int cookie=cookies[index];

                for(int j=0;j<k;j++)
                {
                    buckets[j]+=cookie;

                    helper(cookies, buckets, n, k, totalCookies - cookie, result, index + 1);

                    buckets[j]-=cookie;
                }
            }
        }
};