#include "../ListNode.h"
#include <iostream>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * 1) While looping through the linked list, if the number is equal to the one
 * we want to remove, skip it. Else, add the number to the end of a new linked list.
 * Return the new linked list.
 *
 * Time complexity: O(n * m) [where n is the size of the original linked list and m is the size of our new linked list]
 * Space complexity: O(m) [where m is the size of our new linked list]
 *
 * 2) Remove all occurrences of the target value from the front of linked list.
 * Then, while looping over the linked list, if the number ahead of the current number
 * is the one we want to remove, set the current pointer's next pointer to point to
 * the number after the number we want to remove. Return the original list.
 *
 * Time complexity: O(n) [where n is the length of the input linked list]
 * Space complexity: O(1)
 *
 */

void addToEnd(ListNode* & result, int number)
{
    ListNode* last=result;

    while(last->next!=nullptr)
    {
        last=last->next;
    }

    last->next=new ListNode(number);
}

ListNode* removeElements(ListNode* head, int val)
{
    if(head==nullptr)
    {
        return head;
    }

    if(head->next==nullptr && head->val!=val)
    {
        return head;
    }

    ListNode* result=new ListNode(-1);

    ListNode* current=head;

    while(current!=nullptr)
    {
        if(current->val!=val)
        {
            addToEnd(result, current->val);
        }

        current=current->next;
    }

    return result->next;
}

ListNode* removeElements(ListNode* head, int val)
{
    if(head==nullptr)
    {
        return head;
    }

    while(head!=nullptr && head->val==val)
    {
        head=head->next;
    }

    ListNode* current=head;

    while(current!=nullptr)
    {
        if(current->next!=nullptr && current->next->val==val)
        {
            current->next=current->next->next;
        }
        else
        {
            current=current->next;
        }

    }

    return head;
}