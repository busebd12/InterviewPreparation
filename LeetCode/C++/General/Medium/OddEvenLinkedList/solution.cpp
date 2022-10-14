#include "../ListNode.h"
using namespace std;

/*
Solution:

1) Append all the odd elements to the end of the original list
2) Append all the even elements to the end of the original list
3) Move the head pointer through the now expanded list until we reach the first odd node in the expanded section
4) Return the head node

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution
{
    public:
        ListNode* oddEvenList(ListNode* head)
        {
            int n=getLength(head);

            if(n < 3)
            {
                return head;
            }

            ListNode* current=head;

            while(current->next!=nullptr)
            {
                current=current->next;
            }

            int oddElements=countOddElements(head);

            int evenElements=countEvenElements(head);

            ListNode* pointer=head;

            int count=0;

            while(count < oddElements)
            {
                current->next=new ListNode(pointer->val);

                current=current->next;

                if(pointer->next!=nullptr and pointer->next->next!=nullptr)
                {
                    pointer=pointer->next->next;
                }

                count+=1;
            }

            pointer=head->next;

            count=0;

            while(count < evenElements and pointer->next!=nullptr and pointer->next->next!=nullptr)
            {
                current->next=new ListNode(pointer->val);

                current=current->next;

                pointer=pointer->next->next;

                count+=1;
            }

            for(int count=0;count<n;count++)
            {
                head=head->next;
            }

            return head;
        }

        int getLength(ListNode* head)
        {
            int length=0;

            ListNode* current=head;

            while(current!=nullptr)
            {
                length+=1;

                current=current->next;
            }

            return length;
        }

        int countOddElements(ListNode* head)
        {
            int oddElements=1;

            ListNode* current=head;

            while(current->next!=nullptr and current->next->next!=nullptr)
            {
                oddElements+=1;

                current=current->next->next;
            }

            return oddElements;
        }

        int countEvenElements(ListNode* head)
        {
            int evenElements=0;

            ListNode* current=head->next;

            while(current->next!=nullptr and current->next->next!=nullptr)
            {
                evenElements+=1;

                current=current->next->next;
            }

            return evenElements+=1;
        }
};