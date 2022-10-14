#include <vector>
using namespace std;

class Solution
{
    public:
        vector<int> sumEvenAfterQueries(vector<int> & nums, vector<vector<int>> & queries)
        {
            vector<int> result;
            
            int n=nums.size();
            
            int q=queries.size();
            
            result.resize(q, -1);
            
            int evenSum=0;
            
            for(int number : nums)
            {
                if((number % 2)==0)
                {
                    evenSum+=number;
                }
            }
            
            for(int i=0;i<q;i++)
            {
                int index=queries[i][1];
                
                int value=queries[i][0];
                
                int before=nums[index];
                
                nums[index]+=value;
                
                if(nums[index]!=before)
                {
                    if((before % 2)==0)
                    {
                        evenSum-=before;
                    }
                    
                    if((nums[index] % 2)==0)
                    {
                        evenSum+=nums[index];
                    }
                }
                
                result[i]=evenSum;
            }
            
            return result;
        }
};