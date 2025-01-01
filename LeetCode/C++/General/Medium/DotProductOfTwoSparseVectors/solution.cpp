#include <unordered_map>
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

class SparseVector
{
    private:
        unordered_map<int, int> non_zero_hashmap;
    
    public: 
        SparseVector(vector<int> & nums)
        {
            build_non_zero_hashmap(nums);
        }

        void build_non_zero_hashmap(vector<int> & nums)
        {
            int n=nums.size();

            for(int i=0;i<n;i++)
            {
                if(nums[i]!=0)
                {
                    this->non_zero_hashmap.insert(make_pair(i, nums[i]));
                }
            }
        }

        unordered_map<int, int> get_non_zero_hashmap()
        {
            return this->non_zero_hashmap;
        }
        
        // Return the dotProduct of two sparse vectors
        int dotProduct(SparseVector & vec)
        {
            int dot_product=0;
            
            unordered_map<int, int> vector1_non_zero_hashmap=this->get_non_zero_hashmap();

            unordered_map<int, int> vector2_non_zero_hashmap=vec.get_non_zero_hashmap();

            for(auto [index, number] : vector1_non_zero_hashmap)
            {
                if(vector2_non_zero_hashmap.find(index)!=vector2_non_zero_hashmap.end())
                {
                    int product=vector1_non_zero_hashmap[index] * vector2_non_zero_hashmap[index];

                    dot_product+=product;
                }
            }

            return dot_product;
        }
};