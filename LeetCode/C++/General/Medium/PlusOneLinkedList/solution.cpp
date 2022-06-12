#include <deque>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n) [where n is the length of the input linked list]
Space complexity: O(n)
*/

class Solution
{
    public:
        ListNode* plusOne(ListNode* head)
        {   
            //Holds numbers from linked list
            deque<int> digits;
            
            ListNode* current=head;
            
            //Populate the digits deque
            while(current!=nullptr)
            {
                digits.emplace_back(current->val);
                
                current=current->next;
            }
            
            int last=digits.back();

            //Add one two the last digit in the number
            int next=last + 1;

            //Update the value of last digit
            digits.back()=next % 10;

            //If next is 10, then we need to propagate the carry value (the 1 in 10) as far to the left in the deque as possible
            //For example, if the number is 9999, and we add 1 to it, then the number is 10000 and we need to move the 1 to the front
            if(next > 9)
            {
                int carry=next/10;

                int i=digits.size()-2;

                while(i >= 0 || carry > 0)
                {
                    if(i >= 0)
                    {
                        int sum=digits[i] + carry;

                        carry=sum/10;

                        sum=sum % 10;

                        digits[i]=sum;
                    }
                    else
                    {
                        if(carry > 0)
                        {
                            digits.push_front(carry);

                            carry=0;
                        }
                    }

                    i-=1;
                }
            }
            
            //Linked list holding the digits of the input number + 1
            ListNode* result=new ListNode(-1);
            
            current=result;
            
            //Populate the linked list
            while(!digits.empty())
            {
                int digit=digits.front();
                
                digits.pop_front();
                
                ListNode* newTail=new ListNode(digit);
                
                current->next=newTail;
                
                current=current->next;
            }
            
            //IMPORTANT: return result->next since the first value in result is a placeholder
            return result->next;
        }
};