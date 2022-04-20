#include <vector>
using namespace std;

class SparseVector
{
    public:
        vector<int> numbers;
    
        SparseVector(vector<int> & nums)
        {
            numbers=nums;
        }

        // Return the dotProduct of two sparse vectors
        int dotProduct(SparseVector & vec)
        {
            int n=vec.numbers.size();
            
            int result=0;
            
            //Since both SparseVectors have the same size, we can iterate through both with one for loop
            for(int i=0;i<n;i++)
            {
                //If the number in either SparseVector at the current index is zero, then it won't contribute anything meaningful to the dot product
                if(numbers[i]==0 || vec.numbers[i]==0)
                {
                    continue;
                }
                
                //Two non-zero numbers; calculate the dot product
                result+=(numbers[i] * vec.numbers[i]);
            }
            
            return result;
        }
};