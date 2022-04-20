#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
    public:
        string getSmallestString(int n, int k)
        {
            string result{};
            
            //Hashtable to map numbers to letters
            vector<char> hashtable(27, '$');
            
            //Create number to letter mappings
            char c='a';
            
            for(int number=1;number<=26;number++,c++)
            {
                hashtable[number]=c;
            }
            
            //Add n copies of the letter a to ensure that the string is lexicographically the smallest
            for(int count=0;count<n;count++)
            {
                result.push_back('a');
                
                //Decrement by 1 since the numeric value of a when 1-indexed is 1
                k-=1;
            }
            
            for(int i=n-1;i>=0;i--)
            {   
                //Since we've already added the letter 'a' to every position in the string, each position already has a value of 1 ('a'=1 because we are 1-indexing)
                //So, the maximum additional value we can add to each position is 25 (25 + 1==26)
                int additional=min(k, 25);
                
                //If k==0, we are done
                if(k==0)
                {
                    break;
                }
                else
                {
                    //Calculate the index within the hashtable
                    int index=1 + additional;
                    
                    //Set current character to be the character found in the hashtable at index
                    result[i]=hashtable[index];
                    
                    //Decrement k
                    k-=additional;
                }
            }
            
            return result;
        }
};