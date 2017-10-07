#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findLHS(vector<int>& nums)
{
    if(nums.empty())
    {
        return 0;
    }

    unordered_map<int, int> table;

    unordered_map<int, int> frequency;

    for(const auto & number : nums)
    {
        table.insert(make_pair(number, number-1));

        frequency[number]++;
    }

    int answer=0;

    for(const auto element: table)
    {
        int maxElement=element.first;

        int minElement=element.second;

        auto minSearchResult=frequency.find(minElement);

        auto maxSearchResult=frequency.find(maxElement);

        if(minSearchResult!=end(frequency) && maxSearchResult!=end(frequency))
        {
            int length=frequency[minElement] + frequency[maxElement];

            if(length > answer)
            {
                answer=length;
            }
        }
    }

    return answer;
}