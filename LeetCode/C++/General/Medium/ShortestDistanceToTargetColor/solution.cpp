#include <algorithm>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<int> shortestDistanceColor(vector<int> & colors, vector<vector<int>> & queries)
        {
            vector<int> result;
            
            int c=colors.size();
            
            int q=queries.size();
            
            result.resize(q, -1);
            
            unordered_map<int, set<int>> colorsToIndices;
            
            for(int index=0;index<c;index++)
            {
                int color=colors[index];
                
                colorsToIndices[color].insert(index);
            }
            
            for(int i=0;i<q;i++)
            {
                int index=queries[i][0];
                
                int targetColor=queries[i][1];
                
                if(colorsToIndices.find(targetColor)!=end(colorsToIndices))
                {
                    auto itr=colorsToIndices[targetColor].lower_bound(index);
                    
                    if(itr==end(colorsToIndices[targetColor]))
                    {
                        itr=prev(itr, 1);
                        
                        int foundIndex=*(itr);
                    
                        int dist=0;

                        if(foundIndex >= index)
                        {
                            dist=foundIndex - index;
                        }
                        else
                        {
                            dist=index - foundIndex;
                        }
                        
                        result[i]=dist;
                    } 
                    else if(itr!=end(colorsToIndices[targetColor]) and itr!=begin(colorsToIndices[targetColor]))
                    {   
                        auto itr2=prev(itr, 1);
                        
                        int firstFoundIndex=*(itr);
                    
                        int firstDistance=0;

                        if(firstFoundIndex >= index)
                        {
                            firstDistance=firstFoundIndex - index;
                        }
                        else
                        {
                            firstDistance=index - firstFoundIndex;
                        }

                        int secondFoundIndex=*(itr2);

                        int secondDistance=0;

                        if(secondFoundIndex >= index)
                        {
                            secondDistance=secondFoundIndex - index;
                        }
                        else
                        {
                            secondDistance=index - secondFoundIndex;
                        }

                        result[i]=min(firstDistance, secondDistance);
                    }
                    else
                    {
                        int foundIndex=*(itr);
                    
                        int dist=0;

                        if(foundIndex >= index)
                        {
                            dist=foundIndex - index;
                        }
                        else
                        {
                            dist=index - foundIndex;
                        }
                        
                        result[i]=dist;
                    }
                }
            }
            
            return result;
        }
};