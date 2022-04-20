#include <deque>
#include <vector>
using namespace std;

/*
Solution: see comments

Time complexity: O(n) [where n is the length of pushed and popped]
Space complexity: O(n)
*/

class Solution
{
    public:
        bool validateStackSequences(vector<int> & pushed, vector<int> & popped)
        {
            int n=pushed.size();

            deque<int> push;

            deque<int> pop;

            //Add all values from popped
            for(const auto & number : popped)
            {
                pop.emplace_back(number);
            }

            //Iterate over pushed
            for(int i=0;i<n;)
            {
                //While we are not at the end of pushed and either push is empty or the last element in push is not equal to first element in pop
                while(i < n && (push.empty() || push.back()!=pop.front()))
                {   
                    //Simulate the pushing of elements onto the stack
                    push.emplace_back(pushed[i]);
                    
                    i++;
                }

                //At this point, the last element in push is equal to the first element in pop and we have reached the point where 
                //the first pop from the original stack would have taken place. So, remove the last element from push and the first
                //element from pop to simulate the pop from the original stack
                if(!push.empty())
                {   
                    push.pop_back();
                }

                if(!pop.empty())
                {   
                    pop.pop_front();
                }
            }
            
            //Now, we are done iterating through pushed (all the elements have been pushed onto the original stack) and just need to verify that
            //the order of the remaining pop calls to the original stack are valid
            while(!push.empty() && !pop.empty())
            {
                //If the last element in push is not equal to the first element in pop, then we know that the sequence of push and pop operations was invalid
                if(push.back()!=pop.front())
                {
                    return false;
                }
                
                push.pop_back();
                
                pop.pop_front();
            }

            return true;
        }
};