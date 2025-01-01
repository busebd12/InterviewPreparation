#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n) [where n is the length of arr]
Space complexity: O(u) [where u is the total number of unique values in arr]
*/

class Solution
{
    public:
        int longestSubsequence(vector<int> & arr, int difference)
        {
            int result=0;

            result+=1;

            unordered_map<int, int> hashmap;

            for(int number : arr)
            {
                int previousNumberInSequence=number - difference;

                //If we don't find the previous number in the sequence, then the current number is the beginning of a sequence with length 1
                if(hashmap.find(previousNumberInSequence)==hashmap.end())
                {
                    hashmap.emplace(number, 1);
                }
                //Else, we found the previous number in the sequence ending with the current number
                else
                {
                    //Current length of the sequence ending with the previous number
                    int currentLength=hashmap[previousNumberInSequence];

                    //Increment the sequence length by one
                    int updatedLength=currentLength + 1;

                    //Map the current number to the updated length
                    hashmap[number]=updatedLength;
                }

                //Maximize our result
                result=max(result, hashmap[number]);
            }

            return result;
        }
};