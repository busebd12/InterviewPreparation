#include <unordered_map>
#include <iostream>
using namespace std;

int single_number(int arr[], int sz)
{
    unordered_map<int, int> frequencies;
    
    for(int index=0;index<sz;++index)
    {
        int current=arr[index];
        
        frequencies[current]++;
    }
    
    int answer=0;
    
    if(!frequencies.empty())
    {
        for(const auto & element : frequencies)
        {
            if(element.second==1)
            {
                answer=element.first;
            }
        }
    }
    
    return answer;
}
