#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/*
Solution: based on this resource --> https://www.youtube.com/watch?v=sMGZXT_ylwY

Time complexity: O(d * log(d)) [where d=length of digits]
Space complexity: O(d)
*/

class Solution
{
    public:
        string largestMultipleOfThree(vector<int> & digits)
        {
            string result="";

            int d=digits.size();

            vector<vector<int>> remainderBuckets(3);

            int sum=0;

            //Iterate through the digits
            for(int digit : digits) //O(d)
            {   
                int remainder=digit % 3;

                //Place the digit in the appropriate bucket based on its remainder when % by 3
                remainderBuckets[remainder].push_back(digit);

                sum+=digit;
            }

            for(int remainder=0;remainder<3;remainder++)
            {
                //Sort digits in each remainder bucket in descending order
                sort(remainderBuckets[remainder].begin(), remainderBuckets[remainder].end(), greater<int>()); //O(log(d))
            }

            int sumRemainder=sum % 3;

            if(sumRemainder==1)
            {
                if(!remainderBuckets[1].empty())
                {
                    remainderBuckets[1].pop_back();
                }
                else if(remainderBuckets[2].size() > 1)
                {
                    remainderBuckets[2].pop_back();

                    remainderBuckets[2].pop_back();
                }
                else
                {
                    return result;
                }
            }
            else if(sumRemainder==2)
            {
                if(!remainderBuckets[2].empty())
                {
                    remainderBuckets[2].pop_back();
                }
                else if(remainderBuckets[1].size() > 1)
                {
                    remainderBuckets[1].pop_back();

                    remainderBuckets[1].pop_back();
                }
                else
                {
                    return result;
                }
            }

            //Buckets used for counting sort
            vector<int> buckets(10, 0);

            //Perform counting sort for the remaining digits
            for(int remainder=0;remainder<3;remainder++)
            {
                for(int digit : remainderBuckets[remainder])
                {
                    buckets[digit]+=1;
                }
            }

            //Generate the result string
            for(int digit=9;digit>=0;digit--)
            {
                int times=buckets[digit];

                for(int count=0;count<times;count++)
                {
                    result.push_back(digit + '0');
                }
            }

            //If the result string contains leading zeros
            if(result.front()=='0')
            {
                return "0";
            }

            return result;
        }
};