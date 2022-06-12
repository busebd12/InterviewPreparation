#include <algorithm>
#include <vector>
using namespace std;

/*
Time complexity: O(m + n) [where m is the length of encoded2 and n is the length of encoded1]
Space complexity: O(1)
*/

class Solution
{
    public:
        vector<vector<int>> findRLEArray(vector<vector<int>> & encoded1, vector<vector<int>> & encoded2)
        {
            vector<vector<int>> result;
            
            int n=encoded1.size();
            
            int m=encoded2.size();
            
            int i=0;
            
            int j=0;
            
            int previousProduct=0;
            
            while(i < n && j < m)
            {
                int currentProduct=encoded1[i][0] * encoded2[j][0];
                
                int frequency=min(encoded1[i][1], encoded2[j][1]);
                
                if(currentProduct==previousProduct && !result.empty())
                {
                    result.back()[1]+=frequency;
                }
                else
                {
                    result.emplace_back(vector<int>{currentProduct, frequency});
                }
                
                previousProduct=currentProduct;
                
                encoded1[i][1]-=frequency;
                
                encoded2[j][1]-=frequency;
                
                if(encoded1[i][1]==0)
                {
                    i+=1;
                }
                
                if(encoded2[j][1]==0)
                {
                    j+=1;
                }
            }
            
            return result;
        }
};