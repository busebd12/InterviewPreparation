#include "../ListNode.h"
#include <iostream>

/*
 * Solution: the algorithm works in three steps.
 *
 * 1) Break the linked list into two halves - firstHalf and secondHalf.
 * 2) Reverse the second half of the linked list.
 * 3) Interweave the first half with the reversed second half.
 *
 * Time complexity: O(n) [where n is the length of the input linked list]
 * Space complexity: O(1)
 */

ListNode* reverseLinkedList(ListNode* node)
{
    ListNode* previous=nullptr;

    ListNode* current=node;

    while(current!=nullptr)
    {
        ListNode* after=current->next;

        current->next=previous;

        previous=current;

        current=after;
    }

    return previous;
}

void reorderList(ListNode* head)
{
    if(head==nullptr)
    {
        return;
    }

    if(head->next==nullptr)
    {
        return;
    }

    if(head->next->next==nullptr)
    {
        return;
    }

    ListNode* firstHalf=head;

    ListNode* secondHalf=head->next;

    while(secondHalf!=nullptr && secondHalf->next!=nullptr)
    {
        firstHalf=firstHalf->next;

        secondHalf=secondHalf->next->next;
    }

    secondHalf=firstHalf->next;

    firstHalf->next=nullptr;

    firstHalf=head;

    secondHalf=reverseLinkedList(secondHalf);

    while(firstHalf!=nullptr && secondHalf!=nullptr)
    {
        ListNode* firstHalfNextNode=firstHalf->next;

        ListNode* secondHalfNextNode=secondHalf->next;

        firstHalf->next=secondHalf;

        firstHalf=firstHalfNextNode;

        secondHalf->next=firstHalfNextNode;

        secondHalf=secondHalfNextNode;
    }
}