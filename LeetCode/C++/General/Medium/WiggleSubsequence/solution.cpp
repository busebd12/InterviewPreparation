#include <deque>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n) [where n is the length of nums]
Space complexity: O(n)
*/
class Solution
{
    public:
        int wiggleMaxLength(vector<int>& nums)
        {
            int result=0;
            
            int n=nums.size();
            
            //List of 'D' and 'U' characters that represent the places in the input vector where the difference between two numbers is negative (Down) or postive (Up)
            deque<char> characters;
            
            for(int i=0;i<n-1;i++)
            {
                int difference=nums[i] - nums[i + 1];
                
                if(difference < 0)
                {
                    characters.emplace_back('D');
                }
                else if(difference > 0)
                {
                    characters.emplace_back('U');
                }
            }
            
            //Count the total number of groups of D's and U's in the list of D's and U's
            //So, for example, if we have nums=[1 17 5 10 13 15 10 5 16 8], then the characters deque will look like [D U D D D U U D U]
            //If we divide the deque into groups of D's and U's, we would have the following: [D | U | D D D | U U | D | U]
            //Then, all we need to do is just select one D or U from each group in order to get the maximum number of D's and U's
            //So, for the above example, the maximum length for a list of D's and U's is 6, since there are 6 different groupings
            int groups=0;
            
            int j=0;
            
            while(j < characters.size())
            {
                char c=characters[j];
                
                //While we are iterating through a group of D's or U's
                while(j < characters.size() and characters[j]==c)
                {
                    j+=1;
                }
                
                //Once we reach the end of a group of D's or U's, increment the number of groups
                groups+=1;
            }
            
            //Increment by one since a list of n numbers will be represented by a list of n-1 D's and U's
            result=groups + 1;
            
            return result;
        }
};