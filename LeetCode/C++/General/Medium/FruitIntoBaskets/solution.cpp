#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: sliding window + hashtable (unordered_map). See comments.

Time complexity: O(n) [where n is the length of fruits]
Space complexity: O(baskets) [where baskets equals 2]
*/

class Solution
{
    public:
        int totalFruit(vector<int> & fruits)
        {
            int result=0;
            
            int n=fruits.size();
            
            const int maxSize=2;
            
            unordered_map<int, int> hashtable;
            
            int back=0;
            
            for(int front=0;front<n;front++)
            {
                int fruitType=fruits[front];
                
                //If we have already have this type of fruit in one of our baskets, just increment the frequency
                if(hashtable.find(fruitType)!=end(hashtable))
                {
                    hashtable[fruitType]+=1;
                }
                //Else, we don't have this type of fruit in one of our baskets
                else
                {
                    //We can only use a maximum of two baskets, so we need to remove all the fruits from one of the baskets
                    while(hashtable.size()==maxSize)
                    {
                        hashtable[fruits[back]]-=1;
                        
                        if(hashtable[fruits[back]]==0)
                        {
                            hashtable.erase(fruits[back]);
                        }
                        
                        back+=1;
                    }

                    //Now that we have room in one of the baskets for a different type of fruit, add it to the hashtable
                    hashtable.emplace(fruitType, 1);
                }
                
                //Calculate the length/number of fruits
                int numberOfFruit=(front - back) + 1;
                
                //Update the result
                result=max(result, numberOfFruit);
            }
            
            return result;
        }
};