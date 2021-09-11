#include "../ListNode.h"
#include <iostream>

/*
 * Solutions:
 *
 * 1. As we loop over the input linked-list, we add the nodes in the correct swapped order to
 * our result linked-list. After we finish iterating, return the result linked-list.
 *
 * Time complexity: O(n-squared) [where n is the length of the input linked-list]
 * Space complexity: O(n)
 *
 * 2. As we iterate over the input linked-list, we swap the nodes in pair-wise fashion.
 * The bookeeping we need to be aware of is not loosing links to nodes when we swap
 * and what happens we reach the end of the linked-list.
 *
 * Time complexity: O(n) [where n is the length of the input linked-list]
 * Space complexity: O(1)
 */

void addToEnd(ListNode* & result, const int & value)
{
    if(result==nullptr)
    {
        result=new ListNode(value);
    }
    else
    {
        auto current=result;

        while(current->next!=nullptr)
        {
            current=current->next;
        }

        current->next=new ListNode(value);
    }
}

ListNode* swapPairs(ListNode* head)
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

    auto current=head;

    while(current!=nullptr)
    {
        if(current->next!=nullptr)
        {
            addToEnd(result, current->next->val);
        }

        addToEnd(result, current->val);

        if(current->next==nullptr)
        {
            break;
        }

        current=current->next->next;
    }

    return result;
}

ListNode* swapPairs(ListNode* head)
{
    if(head==nullptr)
    {
        return head;
    }

    if(head->next==nullptr)
    {
        return head;
    }

    ListNode* p=head;

    ListNode* newStart=p->next;

    while(true)
    {
        ListNode* q=p->next;

        ListNode* temp=q->next;

        q->next=p;

        if(temp==nullptr)
        {
            p->next=nullptr;

            break;
        }

        if(temp->next==nullptr)
        {
            p->next=temp;

            break;
        }

        p->next=temp->next;

        p=temp;
    }

    return newStart;
}