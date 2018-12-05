#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> topKFrequentSlower(vector<int> & nums, int k)
{
    if(nums.size() <= k)
    {
        return nums;
    }

    unordered_map<int, int> numberToFrequency;

    multimap<int, int> frequencyToNumber;

    for(auto & number : nums)
    {
        numberToFrequency[number]++;
    }

    for(auto & element : numberToFrequency)
    {
        frequencyToNumber.insert(make_pair(element.second, element.first));
    }

    vector<int> topKElements;

    int count=k;

    for(auto itr=frequencyToNumber.crbegin();itr!=frequencyToNumber.crend();++itr)
    {
        if(count==0)
        {
            break;
        }

        topKElements.emplace_back(itr->second);

        --count;
    }

    return topKElements;
}

vector<int> topKFrequent(vector<int> & nums, int k)
{
    if(nums.size() <= k)
    {
        return nums;
    }

    int n=int(nums.size());

    unordered_map<int, int> numberToFrequency;

    vector<vector<int>> buckets(n+1);

    for(auto & number : nums)
    {
        numberToFrequency[number]++;
    }

    for(auto & element : numberToFrequency)
    {
        int number=element.first;

        int frequency=element.second;

        buckets[frequency].emplace_back(number);
    }

    int count=k;

    bool done=false;

    vector<int> topKElements;

    for(int i=n;i>=0;--i)
    {
        if(!buckets[i].empty())
        {
            for(auto & element : buckets[i])
            {
                if(count==0)
                {
                    done=true;

                    break;
                }

                topKElements.emplace_back(element);

                --count;
            }
        }
    }

    return topKElements;
}