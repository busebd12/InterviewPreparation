/*
Time complexity: O(n)
Space complexity: O(1)
*/

class Solution
{
    public:
        ListNode* deleteMiddle(ListNode* head)
        {
            int length=getLength(head);

            if(length==1)
            {
                head=nullptr;

                return head;
            }

            if(length==2)
            {
                head->next=nullptr;

                return head;
            }

            int stop=(length / 2) - 1;

            ListNode* back=head;

            ListNode* front=head->next;

            for(int count=0;count<stop;count++)
            {
                front=front->next;

                back=back->next;
            }

            back->next=front->next;

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
};