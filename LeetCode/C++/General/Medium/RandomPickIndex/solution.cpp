#include <random>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution
{
    private:
        unordered_map<int, unordered_set<int>> hashtable;
        
        int length;
    
    public:
        Solution(vector<int> & nums)
        {
            int n=nums.size();
            
            length=n;
            
            for(int index=0;index<n;index++)
            {
                int number=nums[index];
                
                hashtable[number].insert(index);
            }
        }
    
        int pick(int target)
        {
            random_device rd;
   
            default_random_engine generator(rd());
   
            uniform_int_distribution<int> distribution(0, length-1);
            
            int index=distribution(generator);
            
            while(hashtable[target].find(index)==end(hashtable[target]))
            {
                index=distribution(generator);
            }
            
            return index;
        }
};


class Solution
{
    private:
        unordered_map<int, vector<int>> hashtable;
        
        int length;
    
    public:
        Solution(vector<int> & nums)
        {
            int n=nums.size();
            
            length=n;
            
            for(int index=0;index<n;index++)
            {
                int number=nums[index];
                
                hashtable[number].push_back(index);
            }
        }
    
        int pick(int target)
        {
            random_device rd;
   
            default_random_engine generator(rd());
   
            uniform_int_distribution<int> distribution(0, int(hashtable[target].size()-1));
            
            int index=hashtable[target][distribution(generator)];
            
            return index;
        }
};