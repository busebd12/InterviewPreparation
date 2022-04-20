#include <algorithm>
#include <string>
using namespace std;

/*
Solution 1: see comments.

Time complexity: O(d^2) [where d is the number of digits in num]
Space complexity: O(d)
*/

class Solution
{
    public:
        int maximumSwap(int num)
        {
            int result=num;
            
            string number=to_string(num);

            int n=number.size();
            
            //Perform all possible two digit swaps
            //Example: for 2736
            //Swap index (0 and 1), (0 and 2), and (0 and 3)
            //Swap index (1 and 2) and (1 and 3)
            //Swap index (2 and 3)
            for(int i=0;i<n;i++)
            {
               for(int j=i+1;j<n;j++)
               {
                   swap(number[i], number[j]);
                   
                   //Don't covert string to integer if the first character is a zero
                   if(number[0]!='0')
                   {
                        int num=stoi(number);

                        result=max(result, num);
                   }

                   swap(number[i], number[j]);
               }
            }
            
            return result;
        }
};

/*
Solution 2: see comments.

Time complexity: O(d) [where d is the number of digits in num]
Space complexity: O(u) [where u is the number of unique digits in num]

*/

class Solution
{
    public:
        int maximumSwap(int num)
        {
            int result=num;
            
            string number=to_string(num);

            int n=number.size();
            
            //Hashtable used to map each digit to the last index within the number at which it occurs
            unordered_map<int, int> hashtable;
            
            //Create mappings
            for(int i=0;i<n;i++)
            {
                char digit=number[i];
                
                hashtable[digit - '0']=i;
            }
            
            //for each digit in number
            for(int i=0;i<n;i++)
            {
                int current=number[i] - '0';
                
                //Loop through all digits that are greater than the current one
                for(int digit=9;digit>current;digit--)
                {
                    //Get the index of the digit from the hashtable
                    int largerDigitIndex=hashtable[digit];
                    
                    //If the larger digit appears later in the number than the current one
                    if(largerDigitIndex > i)
                    {
                        //Swap the two digits
                        swap(number[i], number[largerDigitIndex]);
                        
                        return stoi(number);
                    }
                }
            }
            
            return result;
        }
};