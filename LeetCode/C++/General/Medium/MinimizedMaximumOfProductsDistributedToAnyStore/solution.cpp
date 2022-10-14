#include <vector>
using namespace std;

/*
Time complexity: O(q * log(100000)) [where q is the size of quantities]
Space complexity: O(1)
*/
class Solution
{
    public:
        int minimizedMaximum(int n, vector<int> & quantities)
        {
            int result=0;
            
            int low=1;
            
            int high=100000;
            
            while(low <= high)
            {
                int amount=(low + (high - low)/2);
                
                //If we can distribute all the products among the n stores such that any one store will not be given more than "amount" number of products
                if(canAllocate(quantities, n, amount)==true)
                {   
                    //Update our result
                    result=amount;
                    
                    //Try again with a smaller amount since we want to minimize
                    high=amount - 1;
                }
                else
                {
                    //Try with a larger amount
                    low=amount + 1;
                }
            }
            
            return result;
        }
    
        bool canAllocate(vector<int> & quantities, int n, int amount)
        {
            int stores=0;
            
            for(int i=0;i<quantities.size();i++)
            {
                int product=quantities[i];
                
                //Divided the quantity of product quantities[i] by the max amount we want to distribute to some stores
                stores=stores + (product / amount);
                
                //If the quantity of the product does not divide evenly with the amount we want to distribute then we need an extra store to handle the overflow
                if((product % amount)!=0)
                {
                    stores+=1;
                }
            }
            
            //The number of stores we require needs to be at most n
            return stores <= n;
        }
};