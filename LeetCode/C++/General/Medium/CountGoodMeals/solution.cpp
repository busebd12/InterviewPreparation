#include <cmath>
#include <unordered_map>
using namespace std;

/*
Time complexity: O(22 * n) => O(n) [where n is the length of deliciousness]
Space complexity: O(u) [where u is the number of unqiue values in deliciousness]
*/

class Solution
{
    public:
        int countPairs(vector<int> & deliciousness)
        {
            int result=0;
            
            unordered_map<int, int> hashtable;
            
            const int MOD=1e9 + 7;
            
            //Largest power of two value
            const int limit=pow(2, 22);
            
            //Iterate through each value in deliciousness
            for(int & number : deliciousness)
            {
                //Iterate through all the possible powers of two based on the question constraints
                for(int powerOfTwo=1;powerOfTwo<=limit;powerOfTwo*=2)
                {
                    //If the difference between the power of two and current number is in the hashtable
                    if(hashtable.find(powerOfTwo - number)!=end(hashtable))
                    {
                        //Add the frequency of it to the result
                        result+=hashtable[powerOfTwo - number];
                        
                        //Do the modulo
                        result=result % MOD;
                    }
                }
                
                //Insert the number if it doesn't exist in the hashtable
                if(hashtable.find(number)==end(hashtable))
                {
                    hashtable.emplace(number, 0);
                }
                
                //Increment the frequency of the number
                hashtable[number]+=1;
            }
            
            return result;
        }
};