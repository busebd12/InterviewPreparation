#include <map>
#include <vector>
using namespace std;

/*
Time complexity: O(n log n) [where n is the length of intervals]
Space complexity: O(n)
*/

class Solution
{
    public:
        vector<int> findRightInterval(vector<vector<int>> & intervals)
        {
            vector<int> result;

            int n=intervals.size();

            result.resize(n, -1);

            map<int, int> hashmap;

            for(int i=0;i<n;i++)
            {
                vector<int> interval=intervals[i];

                int start=interval[0];

                hashmap.emplace(start, i);
            }

            for(int i=0;i<n;i++)
            {
                vector<int> interval=intervals[i];

                int end=interval[1];

                auto itr=hashmap.lower_bound(end);

                if(itr!=hashmap.end())
                {
                    int j=itr->second;

                    result[i]=j;
                }
            }

            return result;
        }
};