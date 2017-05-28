#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class MonsterValley
{
  public:
    int minimumPrice(vector<long> Dread, vector<int> Price)
    {
        vector<int> indices;
        
        int partyScariness{};
        
        indices.emplace_back(0);
        
        partyScariness+=Dread[0];
        
        int maxDreadValue=*(max_element(begin(Dread), end(Dread)));
        
        int count{};
        
        for(int index=1;index<Dread.size();++index)
        {
            if(Dread[index] > partyScariness)
            {
                indices.emplace_back(index);
                
                partyScariness+=Dread[index];
            }
            else if(partyScariness > maxDreadValue)
            {
                continue;
            }
            else
            {
                if(partyScariness + Dread[index] > maxDreadValue)
                {
                    if(count > 0)
                    {
                        int lastPriceIndex=indices[indices.size()-1];
                    
                        if(Price[index] < Price[lastPriceIndex])
                        {
                            indices.pop_back();

                            indices.emplace_back(index);

                            partyScariness+=Dread[index];
                        }
                    }
                    else
                    {
                        indices.emplace_back(index);
                        
                        partyScariness+=Dread[index];
                        
                        ++count;
                    }
                }
            }
        }
        
        int cost{};
        
        for(const auto & index : indices)
        {
            cost+=Price[index];
        }
        
        return cost;
    }
};