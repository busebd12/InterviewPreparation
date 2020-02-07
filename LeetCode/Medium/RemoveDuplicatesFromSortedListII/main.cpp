#include "../ListNode.h"
#include <iostream>

/*
 * Solution: as we iterate through the linked-list, we count how many times each node appears.
 * If a node appears only once, we add its value to our result linked-list. If a node appears
 * more than once, we skip it.
 *
 * Time complexity: O(n * d) [where n is the length of the input linked-list and d is the number of distinct elements in the linked-list]
 * Space complexity: O(d)
 */

void addToEnd(ListNode* & result, const int value)
{
    ListNode* newTail=new ListNode(value);

    if(result==nullptr)
    {
        result=newTail;
    }
    else
    {
        ListNode* current=result;

        while(current->next!=nullptr)
        {
            current=current->next;
        }

        current->next=newTail;
    }
}

ListNode* deleteDuplicates(ListNode* head)
{
    if(head==nullptr)
    {
        return head;
    }

    if(head->next==nullptr)
    {
        return head;
    }

    ListNode* result=nullptr;

    ListNode* current=head;

    int value=head->val;

    int count=0;

    while(current!=nullptr)
    {
        while(current!=nullptr && current->val==value)
        {
            count++;

            current=current->next;
        }

        if(count==1)
        {
            addToEnd(result, value);
        }

        if(current!=nullptr)
        {
            value=current->val;
        }

        count=0;
    }

    return result;
}