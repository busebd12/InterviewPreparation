#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool helper(vector<int> & nums, unordered_set<int> & visited, unordered_map<int, int> & directions, const int & start, int & current, const int & n)
{
    if(visited.count(current))
    {
        if(current==start)
        {
            if(!directions.empty())
            {
                if(visited.size() > 1)
                {
                    if(nums[current] > 0)
                    {
                        if(directions.count(-1))
                        {
                            return false;
                        }
                    }
                    else
                    {
                        if(directions.count(1))
                        {
                            return false;
                        }
                    }

                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        visited.insert(current);
    }

    (nums[current] > 0) ? directions[1]++ : directions[-1]++;

    int newIndex=((current + nums[current]) % n);

    if(newIndex < 0)
    {
        newIndex=n + newIndex;
    }

    current=newIndex;

    return helper(nums, visited, directions, start, current, n);
}

bool circularArrayLoop(vector<int> & nums)
{
    int n=int(nums.size());

    for(int i=0;i<n;++i)
    {
        unordered_map<int, int> directions;

        unordered_set<int> visited;

        int start=i;

        visited.insert(start);

        int current=start;

        if(helper(nums, visited, directions, start, current, n))
        {
            return true;
        }
    }

    return false;
}