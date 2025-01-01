#include <algorithm>
#include <limits>
#include <queue>
#include <vector>

/*
Submission result: accepted.

Time complexity: O(n * log(n)) [where n=length of nums]
Space complexity: O(n)
*/

class Solution
{
    public:
        int minimumDeviation(vector<int> & nums)
        {
            int result=numeric_limits<int>::max();

            int n=nums.size();

            int minValue=numeric_limits<int>::max();

            priority_queue<int, vector<int>, less<int>> maxHeap;

            for(int number : nums)
            {
                //If the number is odd
                if((number % 2)==1)
                {
                    //Do the allowed multiplication operation
                    number*=2;
                }

                //Update the minValue
                minValue=min(minValue, number);

                maxHeap.emplace(number);
            }

            while(!maxHeap.empty() and maxHeap.top()%2==0)
            {
                int maxValue=maxHeap.top();

                maxHeap.pop();

                int deviation=maxValue - minValue;

                result=min(result, deviation);

                //Since every number we encounter during the while loop execution will be even, do the allowed operation and divide it by two
                maxValue/=2;

                //Keep track of the minValue since dividing an even number by two could result in a smaller min value (ex: 2/2=1)
                minValue=min(minValue, maxValue);

                maxHeap.emplace(maxValue);
            }

            result=min(result, maxHeap.top() - minValue);

            return result;
        }
};