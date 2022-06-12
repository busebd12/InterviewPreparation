#include <vector>
using namespace std;

/*
Time complexity: O(finalSum)
Space complexity: O(1) [if we don't count the result vector] O(u) [where u is the number of unique positive integers if we are counting the output vector]
*/

class Solution
{
    public:
        vector<long long> maximumEvenSplit(long long finalSum)
        {
            vector<long long> result;
            
            bool isOdd=finalSum % 2;
            
            //If finalSum is odd, then there is no way to split it into a list of positive integers
            if(isOdd==true)
            {
                return result;
            }
            
            if(finalSum==2)
            {
                result.emplace_back(2);
                
                return result;
            }
            
            if(finalSum==4)
            {
                result.emplace_back(4);
                
                return result;
            }
            
            long long sum=0;
            
            //loop till we either reach finalSum or sum becomes larger than finalSum
            for(long long number=2;number<=finalSum && sum <= finalSum;number+=2)
            {
                sum+=number;
                
                result.push_back(number);
            }
            
            //If the sum is larger than final sum
            if(sum > finalSum)
            {
                sum-=result.back();
                
                result.pop_back();
            }
            
            long long leftOver=finalSum - sum;
            
            if(leftOver > 0)
            {
                result.back()+=leftOver;
            }
            
            return result;
        }
};