#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

/*
Solution 1:

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        int minOperations(int n)
        {
            int result=0;
            
            vector<int> numbers(n, 0);
            
            for(int i=0;i<n;i++)
            {
                int number=(2 * i) + 1;
                
                numbers[i]=number;
            }
            
            int sum=accumulate(begin(numbers), end(numbers), 0);
            
            int target=sum / n;
            
            for(int i=0;i<n/2;i++)
            {
                result+=abs(target - numbers[i]);
            }
            
            return result;
        }
};


/*
Solution 1:

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution
{
    public:
        int minOperations(int n)
        {
            int result=0;
            
            int sum=0;
            
            for(int i=0;i<n;i++)
            {
                int number=(2 * i) + 1;
                
                sum+=number;
            }
            
            int target=sum / n;
            
            for(int i=0;i<n/2;i++)
            {
                int number=(2 * i) + 1;
                
                result+=abs(target - number);
            }
            
            return result;
        }
};