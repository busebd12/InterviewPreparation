#include <vector>
using namespace std;

class ProductOfNumbers
{
    private:
        vector<int> prefixProducts;
    
    public:
        ProductOfNumbers()
        {
            prefixProducts={1};
        }

        void add(int num)
        {
            if(num==0)
            {
                //If num is zero, then all prefix products up to this point will be zero, so just reset the prefix products array to 1
                prefixProducts.clear();
                
                prefixProducts={1};
            }
            else
            {
                prefixProducts.push_back(prefixProducts.back() * num);
            }
        }

        int getProduct(int k)
        {   
            int product=0;
            
            int p=prefixProducts.size();
            
            if(k >= p)
            {
                return product;
            }
            
            int numerator=prefixProducts.back();
            
            //We need to divide the last k numbers by the k + 1 number
            int denominator=prefixProducts[p - 1 - k];
            
            product=numerator / denominator;
            
            return product;
        }
};