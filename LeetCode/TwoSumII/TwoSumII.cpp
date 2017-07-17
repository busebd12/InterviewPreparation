#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> & numbers, int target)
{
    if(numbers.empty())
    {
        return vector<int>();
    }
    
    vector<int> answer;
    
    unordered_map<int, int> table;
    
    const size_t numbersSize=numbers.size();
    
    for(int index=0;index<numbersSize;++index)
    {
        auto search=table.find(numbers[index]);
        
        if(search!=end(table))
        {
            answer.emplace_back((search->second)+1);
            
            answer.emplace_back(index+1);
            
            break; 
        }
        else
        {
            int difference=target-numbers[index];
            
            table.emplace(make_pair(difference, index));
        }
    }
    
    return answer;
}
