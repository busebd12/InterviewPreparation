#include <algorithm>
#include <vector>
using namespace std;

/*
Solution 1: brute force.

Time complexity: O(n^2) [where n is the length of nums]
Space complexity: O(1)
*/
class Solution
{
    public:
        int maxProduct(vector<int> & nums)
        {
            int result=numeric_limits<int>::min();
            
            int n=nums.size();
            
            for(int i=0;i<n;i++)
            {
                int product=nums[i];
                
                result=max(result, product);
                
                for(int j=i+1;j<n;j++)
                {
                    product=product * nums[j];
                    
                    result=max(result, product);
                }
            }
            
            return result;
        }
};

/*
Solution 2: Dynamic programming. See comments.

Time complexity: O(n) [where n is the length of nums]
Space complexity: O(n)
*/

class Solution
{
    public:
        int maxProduct(vector<int> & nums)
        {
            int result=numeric_limits<int>::min();
            
            int n=nums.size();
            
            //Keep track of local maximum positive products in the array
            vector<int> positiveProducts(n, 0);
            
            //Keep track of local maximum negative products in the array
            //It could be possible that two negative numbers give the maximum product
            //For example, this test case: [-2, 3, 4]
            vector<int> negativeProducts(n, 0);
            
            positiveProducts[0]=nums[0];
            
            negativeProducts[0]=nums[0];
            
            for(int i=1;i<n;i++)
            {
                int number=nums[i];
                
                if(number < 0)
                {
                    //The local maximum negative product will be the current number or the current number multiplied by the local maximum positive product up to this point
                    negativeProducts[i]=min(nums[i], nums[i] * positiveProducts[i-1]);
                    
                    //The local maximum positive product will be the current number or the current number multiplied by the local maximum negative product up to this point
                    positiveProducts[i]=max(nums[i], nums[i] * negativeProducts[i-1]);
                }
                else
                {
                    //The maximum positive product will be the current number or the current number multiplied by the local maximum positive product up to this point
                    positiveProducts[i]=max(nums[i], nums[i] * positiveProducts[i-1]);
                
                    //The local maximum negative product will be the current number or the current number multiplied by the local maximum negative product up to this point
                    negativeProducts[i]=min(nums[i], nums[i] * negativeProducts[i-1]);
                }
            }
            
            //Get the maximum positive product out of all the local maximum positive products
            int maximumPositiveProduct=*(max_element(begin(positiveProducts), end(positiveProducts)));
            
            //Get the maximum negative product out of all the local maximum negative products
            int maximumNegativeProduct=*(max_element(begin(negativeProducts), end(negativeProducts)));
            
            //The answer will be the maximum of the maximumPositiveProduct and maximumNegativeProduct
            result=max(maximumPositiveProduct, maximumNegativeProduct);
            
            return result;
        }
};