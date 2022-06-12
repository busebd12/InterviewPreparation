#include <deque>
#include <vector>
using namespace std;

/*
Solution 1: see comments.

Time complexity: O(n^2)
Space complexity: O(n)
*/

class Solution
{
    public:
        vector<int> nextGreaterElements(vector<int> & nums)
        {
            vector<int> result;
            
            int n=nums.size();
            
            result.resize(n, -1);
            
            //Vector that holds two copies of nums
            vector<int> doubled;
            
            //Add one copy of nums to doubled
            for(int number : nums)
            {
                doubled.push_back(number);
            }
            
            //Add a second copy of nums to doubled
            for(int number : nums)
            {
                doubled.push_back(number);
            }
            
            //For each value in nums
            for(int i=0;i<n;i++)
            {   
                int current=doubled[i];
                
                bool done=false;
                
                //Loop until we reach the second copy of the number (which means we've made one full loop through the original circular array)
                for(int j=i+1,count=1;count<n;j++,count++)
                {   
                    //If we've found the next greater number
                    if(doubled[j] > current)
                    {
                        //Set the result accordingly
                        result[i]=doubled[j];
                        
                        done=true;
                    }
                    
                    //Break out of the loop since we've found what we were looking for
                    if(done)
                    {
                        break;
                    }
                }
            }
            
            return result;
        }
};

/*
Solution 2: see comments.

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        vector<int> nextGreaterElements(vector<int> & nums)
        {
            vector<int> result;
            
            int n=nums.size();
            
            result.resize(n, -1);
            
            //vector to hold two copies of nums concatenated together
            vector<int> doubled;
            
            //Add one copy of nums to doubled
            for(int number : nums)
            {
                doubled.push_back(number);
            }
            
            //Add a second copy of nums to doubled
            for(int number : nums)
            {
                doubled.push_back(number);
            }
            
            //Stack of indices
            deque<int> stack;
            
            for(int i=0;i<doubled.size();i++)
            {   
                if(stack.empty())
                {
                    stack.emplace_back(i);
                }
                else
                {
                    //If current number in doubled is greater than the previous number in doubled
                    if(doubled[i] > doubled[stack.back()])
                    {   
                        //While the stack is not empty and the current number is greater than the number in doubled found at the index at the top of the stack
                        while(!stack.empty() && doubled[i] > doubled[stack.back()])
                        {
                            //Set result at the index at the top of the stack to the current number
                            result[stack.back() % n]=doubled[i];
                        
                            //Remove the index from the top of the stack
                            stack.pop_back();
                        }
                        
                        //Add the current index to the stack
                        stack.emplace_back(i);
                    }
                    //Else, the current number is less than the number in doubled found at the index at the top of the stack
                    else
                    {   
                        //Only add the index to the stack if we don't have a next greater value for the current number
                        if(result[i % n]==-1)
                        {
                            stack.emplace_back(i);
                        }
                    }
                }
            }
            
            return result;
        }
};