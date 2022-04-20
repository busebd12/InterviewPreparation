#include <string>
#include <vector>
using namespace std;

/*
Solution: see comments

Time complexity: O(n + c) [where n is the length of the chars vector and c is the length of the compressed string]
Space complexity: O(c) [where c is the length of the compressed string]
*/

class Solution
{
    public:
        int compress(vector<char> & chars)
        {
            int result=0;
            
            int n=chars.size();
            
            int front=0;
            
            int back=0;
            
            int count=0;
            
            string compressed{};
            
            while(front < n)
            {
                //While consecutive characters match
                while(front < n && chars[back]==chars[front])
                {
                    //Increment the count of the matching consecutive characters
                    count++;
                    
                    front++;
                }
                
                //Add the character
                compressed.push_back(chars[back]);
                
                //Only append the count of the consecutive characters if it is greater than 1
                if(count > 1)
                {
                    compressed.append(to_string(count));
                }
                
                back=front;
                
                count=0;
            }
            
            //Iterate through compressed string and update the chars vector accordingly
            for(int index=0;index<compressed.size();index++)
            {
                chars[index]=compressed[index];
            }
            
            result=compressed.size();
            
            return result;
        }
};