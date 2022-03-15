#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(u + (n log n) + u) [where u is the total unique numbers in arr and n is the length of arr]
Space complexity: O(u)
*/

class Solution
{
    public:
        bool canReorderDoubled(vector<int> & arr)
        {
            //Hashtable used to record the frequency of each number in arr
            unordered_map<int, int> hashtable;
            
            //Calculate the frequencies
            for(const auto & number : arr)
            {
                hashtable[number]++;
            }
            
            //Sort arr based on the absolute value of each number
            sort(begin(arr), end(arr), [] (auto & num1, auto & num2){return abs(num1) < abs(num2);});
            
            //For each number in arr
            for(auto & number : arr)
            {   
                //If the frequency is zero, we can skip it as we have used all instances of the number
                if(hashtable[number]==0)
                {
                    continue;
                }
                else
                {
                    //The doubled value of the number
                    int doubled=number * 2;
                    
                    //If the doubled value is in the hashtable
                    if(hashtable.count(doubled))
                    {
                        //If the frequency is greater than zero
                        if(hashtable[doubled] > 0)
                        {
                            //Decrement the frequencies of the original and doubled values
                            hashtable[doubled]--;
                            
                            hashtable[number]--;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            
            return true;
        }
};