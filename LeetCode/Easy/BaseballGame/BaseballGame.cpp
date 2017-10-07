#include <iostream>
#include <vector>
#include <string>
using namespace std;

int calPoints(vector<string>& ops)
{
    if(ops.empty())
    {
        return 0;
    }
    
    vector<int> cache;
    
    const size_t opsSize=ops.size();
    
    for(int index=0;index<opsSize;++index)
    {
        if(ops[index]=="+")
        {
            int points=cache[cache.size()-1] + cache[cache.size()-2];
            
            cache.emplace_back(points);
        }
        else if(ops[index]=="D")
        {
            cache.emplace_back(cache[cache.size()-1]*2);
        }
        else if(ops[index]=="C")
        {
            cache.pop_back();
        }
        else
        {
            cache.emplace_back(stoi(ops[index]));
        }
    }
    
    int total=0;
    
    for(const auto & element : cache)
    {
        total+=element;
    }
    
    return total;
}