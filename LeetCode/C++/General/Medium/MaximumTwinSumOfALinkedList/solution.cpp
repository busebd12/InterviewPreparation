#include <deque>
#include <unordered_map>
using namespace std;

/*
Solution 1: see comments.

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        int pairSum(ListNode* head)
        {
            int result=0;
            
            int n=0;
            
            unordered_map<int, int> indexToValue;
            
            ListNode* current=head;
            
            //Map each value in the linked-list to its index
            for(int index=0;current!=nullptr;index++,current=current->next)
            {
                indexToValue[index]=current->val;
                
                n+=1;
            }
            
            //Iterate through half of the indices (starting from n-1)
            for(int index=n-1;index>=n/2;index--)
            {
                //Calculate the twin
                int twin=(n - 1) - index;
                
                //Calculate the sum
                int sum=indexToValue[index] + indexToValue[twin];

                //Update the result
                result=max(result, sum);
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
        int pairSum(ListNode* head)
        {
            int result=0;
            
            //Since the problem is just asking us to find the maximum sum for each pair of front linked list node and back linked list node,
            //we can simply put the values from the linked list into a std::deque. A std::deque gives us constant time access to the first and last
            //vaue.
            deque<int> values;
            
            //Populate the deque
            for(ListNode* current=head;current!=nullptr;current=current->next)
            {
                values.emplace_back(current->val);
            }
            
            //While the deque is not empty
            while(!values.empty())
            {   
                //Sum up the two end values
                int sum=values.front() + values.back();
                
                //Update the result
                result=max(result, sum);
                
                //Remove the two end values
                values.pop_back();
                
                values.pop_front();
            }
            
            return result;
        }
};