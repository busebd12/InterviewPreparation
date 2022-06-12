#include <unordered_map>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of nums]
Space complexity: O(u) [where u is the number of unique numbers in nums]
*/

class Solution
{
    public:
        int maxOperations(vector<int> & nums, int k)
        {
            int result=0;
            
            unordered_map<int, int> hashtable;
            
            for(int number : nums)
            {
                hashtable[number]+=1;
            }
            
            for(int number : nums)
            {
                int target=k - number;
                
                if(hashtable.find(number)!=end(hashtable) && hashtable.find(target)!=end(hashtable))
                {
                    if(number==target)
                    {
                        if(hashtable[number] >= 2)
                        {
                            result+=1;
                    
                            hashtable[number]-=1;

                            if(hashtable[number]==0)
                            {
                                hashtable.erase(number);
                            }

                            hashtable[target]-=1;

                            if(hashtable[target]==0)
                            {
                                hashtable.erase(target);
                            }
                        }
                    }
                    else
                    {
                        if(hashtable[number] > 0 && hashtable[target] > 0)
                        {
                            result+=1;
                    
                            hashtable[number]-=1;

                            if(hashtable[number]==0)
                            {
                                hashtable.erase(number);
                            }

                            hashtable[target]-=1;

                            if(hashtable[target]==0)
                            {
                                hashtable.erase(target);
                            }
                        }
                    }
                }
            }
            
            return result;
        }
};