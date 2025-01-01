#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<vector<int>> groupThePeople(vector<int> & groupSizes)
        {
            vector<vector<int>> result;

            int n=groupSizes.size();

            unordered_map<int, vector<int>> hashmap;

            for(int i=0;i<n;i++)
            {
                int groupSize=groupSizes[i];

                int id=i;

                if(hashmap.find(groupSize)==hashmap.end())
                {
                    hashmap.emplace(groupSize, vector<int>());
                }

                hashmap[groupSize].push_back(id);
            }

            for(auto & [groupSize, people] : hashmap)
            {
                while(!people.empty())
                {
                    int count=0;

                    vector<int> group;

                    while(!people.empty() and count < groupSize)
                    {
                        group.emplace_back(people.back());

                        people.pop_back();

                        count+=1;
                    }

                    result.push_back(group);
                }
            }

            return result;
        }
};

class Solution
{
    public:
        vector<vector<int>> groupThePeople(vector<int> & groupSizes)
        {
            vector<vector<int>> result;

            int n=groupSizes.size();

            unordered_map<int, vector<int>> hashmap;

            for(int i=0;i<n;i++)
            {
                int groupSize=groupSizes[i];

                int id=i;

                if(hashmap.find(groupSize)==hashmap.end())
                {
                    hashmap.emplace(groupSize, vector<int>());
                }

                hashmap[groupSize].push_back(id);

                if(hashmap[groupSize].size()==groupSize)
                {
                    result.push_back(hashmap[groupSize]);

                    hashmap.erase(groupSize);
                }
            }

            return result;
        }
};