#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: inspired by this video --> https://www.youtube.com/watch?v=uVLp1tkT4NU

Time complexity: O(n) [where n is the length of arr]
Space complexity: O(r) [where r is the number of unique remainder values]
*/

class Solution
{
    public:
        bool canArrange(vector<int> & arr, int k)
        {
            int n=arr.size();
            
            unordered_map<int, int> remainderFrequencies;
            
            for(int number : arr)
            {
                int remainder=number % k;
                
                if(number < 0)
                {
                    remainder=(remainder + k) % k;
                }
                
                remainderFrequencies[remainder]+=1;
            }
            
            for(int remainder=0;remainder<k;remainder++)
            {
                if(remainder==0)
                {
                    //There must be an even amount of numbers that are already evenly divisible by k by themselves since those numbers can only form pairs
                    //with other numbers that are also already evenly divisible by k 
                    if((remainderFrequencies[remainder] % 2)!=0)
                    {
                        return false;
                    }
                }
                else
                {
                    //If a number x1 % k equals y and a number x2 % k equals z,
                    //then the only way these two numbers can form a pair which has sum divisible by k is if y + z equals k
                    //The formulat y + z = k can be re-written as y = k - z
                    //So, if we are trying to create pairs for all numbers that have remainder as y, then the frequency of remainders which
                    //are equal to k - z must be equal to the frequency of remainders equal to y
                    if(remainderFrequencies[remainder]!=remainderFrequencies[k - remainder])
                    {
                        return false;
                    }
                }
            }
            
            return true;            
        }
};