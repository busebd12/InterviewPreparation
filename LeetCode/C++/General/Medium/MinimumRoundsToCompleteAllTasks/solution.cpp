#include <unordered_map>
#include <vector>
using namespace std;

/*
Time complexity: O(n + u) [where n is the length of tasks and u is the number of unique tasks]
Space complexity: O(u)
*/

class Solution
{
    public:
        int minimumRounds(vector<int> & tasks)
        {
            int result=0;

            unordered_map<int, int> hashmap;

            for(int task : tasks)
            {
                if(hashmap.find(task)==hashmap.end())
                {
                    hashmap.emplace(task, 0);
                }

                hashmap[task]+=1;
            }

            for(auto & [task, frequency] : hashmap)
            {
                if(frequency < 2)
                {
                    return -1;
                }

                if((frequency % 3)==0)
                {
                    result+=(frequency / 3);
                }
                else
                {
                    result+=(frequency / 3) + 1;
                }
            }

            return result;
        }
};