#include <vector>
using namespace std;

class Solution
{
    public:
        int findMinFibonacciNumbers(int k)
        {
            int result=0;
            
            vector<int> fibonacciNumbers;

            fibonacciNumbers.emplace_back(1);

            fibonacciNumbers.emplace_back(1);

            while(fibonacciNumbers.back() <= k)
            {
                int size=fibonacciNumbers.size();
                
                int sum=fibonacciNumbers[size - 1] + fibonacciNumbers[size - 2];

                fibonacciNumbers.push_back(sum);
            }

            int total=k;

            for(int i=fibonacciNumbers.size()-1;i>=0;i--)
            {   
                if(fibonacciNumbers[i] <= total)
                {
                    total-=fibonacciNumbers[i];

                    result+=1;
                }
            }

            return result;
        }
};