#include "../ListNode.h"
#include <iostream>

/*
 * Solution: we make two passes through the linked-list. During the first iteration, we add all numbers that are strictly
 * less than the partition value to the result linked-list. During the second iteration, we add all numbers that are
 * greater than or equal to the partition value to the result linked-list. Then, just return the result linked-list.
 *
 * Time complexity: O((n * S) + (n * L)) [where n is the length of the input linked-list, S is the number of elements smaller
 * than the partition value, and L is the number of elements greater than or equal to the partition value]
 *
 * Space complexity: O(n)
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

ListNode* partition(ListNode* head, int x)
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

    while(current!=nullptr)
    {
        if(current->val < x)
        {
            addToEnd(result, current->val);
        }

        current=current->next;
    }

    current=head;

    while(current!=nullptr)
    {
        if(current->val >= x)
        {
            addToEnd(result, current->val);
        }

        current=current->next;
    }

    return result;
}