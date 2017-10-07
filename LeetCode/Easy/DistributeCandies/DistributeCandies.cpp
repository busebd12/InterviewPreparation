#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int distributeCandies(vector<int>& candies)
{
    if(candies.empty())
    {
        return 0;
    }

    unordered_map<int, int> table;

    unordered_set<int> s(begin(candies), end(candies));

    for(const auto & element : s)
    {
        table[element]++;
    }

    const size_t candiesSize=candies.size();

    if(s.size()==candies.size()/2)
    {
        return s.size();
    }

    for(const auto & element : table)
    {
        if(s.size() > candiesSize/2)
        {
            s.erase(element.first);
        }
        else if(s.size()==candiesSize/2)
        {
            break;
        }
    }

    return s.size();
}