#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*
Solution: breadth-first search.

Time complexity: O(n) [where n is the length of arr]
Space complexity: O(n + u) [where u is the total number of unique values in arr]
*/

class Solution
{
    public:
        int minJumps(vector<int> & arr)
        {
            int result=0;

            int n=arr.size();

            unordered_map<int, vector<int>> hashmap;

            for(int index=0;index<n;index++)
            {
                hashmap[arr[index]].push_back(index);
            }

            unordered_set<int> visited;

            deque<int> queue;

            int start=0;

            queue.push_back(start);

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    int current=queue.front();

                    queue.pop_front();

                    if(current==n-1)
                    {
                        return result;
                    }

                    if(visited.find(current)!=visited.end())
                    {
                        continue;
                    }

                    visited.insert(current);

                    if(current + 1 < n)
                    {
                        queue.emplace_back(current + 1);
                    }

                    if(current - 1 >= 0)
                    {
                        queue.emplace_back(current - 1);
                    }

                    int value=arr[current];

                    for(int j : hashmap[value])
                    {
                        if(j!=current)
                        {
                            queue.push_back(j);
                        }
                    }

                    hashmap[value].clear();
                }

                result+=1;
            }

            return -1;
        }
};