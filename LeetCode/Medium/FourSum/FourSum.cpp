#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int> & num, int target)
{
    vector<vector<int>> result;

    if(num.empty())
    {
        return {};
    }
    
    const size_t numSize=num.size();

    sort(begin(num), end(num));

    for(int i=0;i<num.size();++i)
    {
        int target3=target - num[i];
    
        for (int j=i+1;j<numSize;++j)
        {
            int target2=target3 - num[j];
        
            int front=j+1;
            
            int back=numSize-1;
        
            while(front < back)
            {
                int twoSum=num[front] + num[back];
            
                if(twoSum < target2)
                {
                    front++;
                }
                else if(twoSum > target2)
                {
                    back--;
                }
                else
                {
                
                    vector<int> quadruplet(4, 0);
                    
                    quadruplet[0]=num[i];
                    
                    quadruplet[1]=num[j];
                    
                    quadruplet[2]=num[front];
                    
                    quadruplet[3]=num[back];
                    
                    result.push_back(quadruplet);
                
                    while(front < back && num[front]==quadruplet[2])
                    {
                        ++front;
                    }

                    while(front < back && num[back]==quadruplet[3])
                    {
                        --back;
                    }
                }
            }
            
            while(j+1 < numSize && num[j+1] == num[j])
            {
                ++j;
            }
        }
    
        while(i+1 < numSize && num[i + 1]==num[i])
        {
            ++i;
        }
    }
    
    return result;
}