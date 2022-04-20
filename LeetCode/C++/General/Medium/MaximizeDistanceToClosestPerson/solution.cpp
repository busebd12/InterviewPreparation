#include <algorithm>
#include <set>
#include <vector>
using namespace std;


class Solution
{
    public:
        int maxDistToClosest(vector<int> & seats)
        {
            int result=-1;
            
            int n=seats.size();
            
            vector<set<int>> distances;
            
            vector<int> occupiedSeatIndices;
            
            for(int i=0;i<n;i++) //O(n)
            {
                int seat=seats[i];
                
                if(seat==1)
                {
                    occupiedSeatIndices.emplace_back(i);
                }
            }
            
            for(int i=0;i<n;i++) //O(n)
            {
                int seat=seats[i];
                
                if(seat==0)
                {
                    set<int> currentDistances;
                    
                    for(auto index : occupiedSeatIndices) //O(o log r)
                    {
                        int dist=abs(i - index);
                        
                        currentDistances.emplace(dist);
                    }
                    
                    distances.emplace_back(currentDistances);
                }
            }
            
            for(auto & values : distances)
            {
                int minValue=*(begin(values));
                
                if(result==-1)
                {
                    result=minValue;
                }
                else
                {
                    result=max(result, minValue);
                }
            }
            
            return result;
        }
};

class Solution
{
    public:
        int maxDistToClosest(vector<int> & seats)
        {
            int result=0;
            
            int n=seats.size();
            
            int j=-1;
            
            for(int i=0;i<n;i++)
            {
                int seat=seats[i];
                
                if(seat==1)
                {
                    if(j!=-1)
                    {
                        result=max(result, (i - j)/2);
                    }
                    else
                    {
                        result=max(result, i);
                    }
                    
                    j=i;
                }
                else if(i==n-1)
                {
                    result=max(result, i - j);
                }
            }
            
            return result;
        }
};