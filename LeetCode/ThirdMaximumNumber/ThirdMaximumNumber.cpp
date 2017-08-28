#include <iostream>
#include <vector>
#include <set>
using namespace std;

int thirdMax(vector<int> & nums)
{
    if(nums.empty())
    {
        return 0;
    }

    set<int> top3;

    for(const auto & number : nums)
    {
        top3.insert(number);

        if(top3.size() > 3)
        {
           top3.erase(top3.begin());
        }
    }

    return (top3.size()==3) ? (*top3.begin()) : (*top3.rbegin());
}