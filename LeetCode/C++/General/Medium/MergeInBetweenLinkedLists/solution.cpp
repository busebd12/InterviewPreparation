class Solution
{
    public:
        ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
        {
            ListNode* first=list1;

            for(int iteration=0;iteration<a-1;iteration+=1)
            {
                first=first->next;
            }

            ListNode* second=list1;

            for(int iteration=0;iteration<b+1;iteration+=1)
            {
                second=second->next;
            }

            ListNode* list2_pointer=list2;

            while(list2_pointer->next!=nullptr)
            {
                list2_pointer=list2_pointer->next;
            }

            first->next=list2;

            list2_pointer->next=second;

            return list1;
        }
};